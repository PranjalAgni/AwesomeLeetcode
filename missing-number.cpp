class Solution {
public:
    int missingNumber(vector<int>& nums) {

        //[2,3,4,6,7,8]
        sort(nums.begin(), nums.end());
        int start = nums[0];
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            start += 1;
            if (!(start == nums[i])) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            return nums[nums.size()-1] + 1;
        } else {
            return start;
        }
    }
};