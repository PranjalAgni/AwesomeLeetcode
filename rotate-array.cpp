class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> numCopy(size);
        for (int i = 0; i < size; i++) {
            numsCopy[i] = nums[i]; 
        }

        for (int i = 0; i < size; i++) {
            nums[(i+k) % size] = numsCopy[i];
        }
    }
};