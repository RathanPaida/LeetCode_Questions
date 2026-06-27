class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mpp;
        for (auto& i : nums) {
            mpp[i]++;
        }
        int maxi = 1;
        if (mpp.count(1)) {
            if (mpp[1] % 2 == 0) {
                maxi = max(maxi, mpp[1] - 1);
            }else {
                maxi = max(maxi, mpp[1]);
            }
        }
        for (auto& it : mpp) {
            long long x = it.first;
            int y = it.second;
            if (x == 1) {
                continue;
            }
            long long curr = x;
            int len = 0;
            while (mpp.count(curr) && mpp[curr] >= 2) {
                len += 2;
                if (curr > 1e9) {
                    break;
                }
                curr = curr * curr;
            }
            if (mpp.count(curr)) {
                len++;
            } else {
                len--;
            }
            maxi = max(maxi, len);
        }
        return maxi;
    }
};