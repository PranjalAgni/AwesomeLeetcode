class Solution {
public:
    int findDuplicateModifyingArray(vector<int>& nums) {
        /**
        * Here we are using array elements as indexes
        * arr = [3,1,3,4,2]
        * arr[0] = 3 ==> arr[3] = 4 ==> modify arr[3] = -4
        * arr[2] = 3 ==> arr[3] = -4 ==> its negative means arr[2] is repeating
        * arr = [1,3,4,2,2]
        * test this case
        * [1,-3,4,2,2]
        * [1,-3,4,-2,2]
        * [1,-3,4,-2,-2]
        * [1,-3,-4,-2,-2]
        **/
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[abs(nums[i])] >= 0) {
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            } else {
                return abs(nums[i])
            }
        }

        return 0;      
    }


    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]]
        }

        fast = 0;
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// [3,1,3,4,2]
// slow = 3 fast = 4
// slow = 4 fast = 3
// slow = 2 fast = 2 cycle detected

// slow = 2
// fast = 0

// slow = 3, fast = 3
// answer = 3


// [2,5,9,6,9,3,8,9,7,1]
// slow = 2 fast = 9
// slow = 9 fast = 5
// slow = 1 fast = 6
// slow = 5 fast = 7
// slow = 3 fast = 1
// slow = 6 fast = 3
// slow = 8 fast = 8 cycle found

// slow = 8, fast = 0
// slow = 7 fast = 2
// slow = 9 fast = 9 answer 