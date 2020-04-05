package codes;

class Solution {
    public int majorityElement(int[] nums) {
        int length = nums.length;
        int majority = 0;
        int count = 0;
        for (int n: nums) {
            if (count == 0) {
                majority = n;
            }

            if (majority == n) count += 1;
            else count -= 1; 
        }
        count = 0;
        for (int n: nums) {
            if (majority == n) {
                count += 1;
            }

        }

        return count >  (length / 2) ? majority : -1;
    }
}