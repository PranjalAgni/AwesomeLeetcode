class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vect;

        if (nums1.size() == 0 || nums2.size() == 0) {
            return vect;
        }

        stack<int> nge;
        nge.push(nums2[0]);
        unordered_map<int, int> map;

        // [2,5,4,12,6]
        // [2]
        // [5]
        // [5,4] comp by 12
        // [5] comp by 12
        // [12]
        for (int i = 1; i < nums2.size(); i++) {
            if (nge.empty()) {
                nge.push(nums2[i]);
                continue;
            }

            while (nge.empty() == false && nge.top() < nums2[i]) {
                map[nge.top()] = nums2[i];
                nge.pop();
            }

            nge.push(nums2[i]);
        }

        while (nge.empty() == false) {
            map[nge.top()] = -1;
            nge.pop();
        }

        for (int i = 0; i < nums1.size(); i++) {
            vect.push_back(map[nums1[i]]);
        }

        return vect;
    }
};