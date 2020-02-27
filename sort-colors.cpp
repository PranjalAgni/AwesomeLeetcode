/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

* SOLUTION: This is solved using counting sort
*/

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        vector<int> countColors(3);
        for (int i = 0; i < len; i++) {
            countColors[nums[i]] += 1;
        }

        int idx = 0;
        for (int i = 0; i <= 2; i++) {
            while (countColors[i] > 0) {
                nums[idx++] = i;
                countColors[i] -= 1;
            }
        }
    }
};