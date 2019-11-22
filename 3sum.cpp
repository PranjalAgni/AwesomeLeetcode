class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        if (nums.size() <= 0) return ans;
        sort(nums.begin(), nums.end());

       for (int x = 0; x < nums.size() - 1; x++) {
           if (x > 0 && nums[x] == nums[x - 1]) {
               continue;
           }
           int low = x + 1;
           int high = nums.size() - 1;
           bool lcheck = false;
           bool rcheck = false;
           while (low < high) {
               int sum = nums[x] + nums[low] + nums[high];
               if (sum == 0) {
                  curr.push_back(nums[x]);
                  curr.push_back(nums[low]);
                  curr.push_back(nums[high]);
                  ans.push_back(curr);
                  curr.clear();
                  low++;
                  high--;
                  lcheck = true;                
               } else if (sum > 0) {
                   high--;
                   rcheck = true;
               } else {
                   low++;
               }
               if (lcheck) {
                   while (low < high && nums[low-1] == nums[low]) {
                       low++;
                   }
                   lcheck = false;
               }

               if (rcheck) {
                   while (low < high && nums[high] == nums[high+1]) {
                       high--;
                   }
                   rcheck = false;
               }
           } 
       }

        return ans;
    }
};