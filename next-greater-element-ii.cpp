class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, -1);
        stack<int> store;

        for (int i = 0; i < size * 2; i++) {
            int num = nums[i % size];

            while (store.empty() == false && nums[store.top()] < num) {
                result[store.top()] = num;
                store.pop();
            }

            if (i < size) store.push(i);
        }

        return result;
    }
};

// [1,2,1]
// start = 0 end = 2
// start = 1 end = 4