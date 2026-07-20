class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int divsum=0;

            for (int i : nums) {
                divsum += (i + mid - 1) / mid; 
             }

            if (divsum <= threshold) { 
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};