class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size() - 1, mid;
        while (s < e) {
            mid = s + (e - s) / 2;
            if (mid > 0 && mid < nums.size() - 1 &&
                nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            } else if (mid < nums.size() - 1 && nums[mid] != nums[mid + 1]) {
                if (mid % 2 == 0) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else if (mid > 0 && nums[mid] != nums[mid - 1]) {
                if (mid % 2 != 0) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
        }
        return nums[s];
    }
};
