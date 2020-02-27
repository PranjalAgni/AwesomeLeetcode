class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + ((high - low) / 2);
            int lowerFloor = low;
            int lowerCeil = mid;
            int upperFloor = mid + 1;
            int upperCeil = high;

            int itemsInLowerRange = 0;

            for (int items : nums) {
                if (items >= lowerFloor && items <= lowerCeil) {
                    itemsInLowerRange += 1;
                }
            }

            int totalItemsLowerRange = lowerCeil - lowerFloor + 1;

            if (itemsInLowerRange > totalItemsLowerRange) {
                low = lowerFloor;
                high = lowerCeil;
            } else {
                low = upperFloor;
                high = upperCeil;
            }
        }

        return nums[low];
    }
};