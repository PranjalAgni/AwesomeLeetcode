class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //[1,2,3,2,3]
        //[1,2,2,3,3]
        //1,1
        //2
        // [1,1,2,2,3]
        // [1,1,2,3,3]
        sort(nums.begin(), nums.end());
        int num;
        bool flag = false; 
        for (int i = 0; i < nums.size()-1; i++) {
            int curr = nums[i];
            int next = nums[i+1];
            if (curr == next) {
                i += 1;   
            } else {
                num = curr;
                flag = true;
                break;
            }
        }

        if (!flag) {
            return nums[nums.size()-1];
        } else {
            return num;
        }
    }
};