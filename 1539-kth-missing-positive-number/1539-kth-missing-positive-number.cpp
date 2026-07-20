class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0, e = arr.size() - 1, mid;
        int ans=0;
        while (s <= e) {
            mid = s + (e - s) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                ans=mid+1;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return k + ans;
    }
};
