class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = nums1.size();
        int elts = 0;
        while (elts < n) {
            nums1.push_back(nums2[elts]);
            elts += 1;
        }

        bool go = false;
        for (int i = end-1; i >= 0; i--) {
            if (nums1[i] == 0) {
                nums1.erase(nums1.begin() + i);
            }
        }

        sort(nums1.begin(), nums1.end());
    }
};