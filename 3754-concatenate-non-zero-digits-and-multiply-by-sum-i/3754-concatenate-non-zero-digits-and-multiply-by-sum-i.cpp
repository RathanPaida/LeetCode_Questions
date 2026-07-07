class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        int x = 0;
        int sum = 0;
        for (char c : s) {
            int t = c - '0';
            if (t != 0) {
                x = (x * 10 + t);
                sum += t;
            }
        }
        return (long long)x * sum;
    }
};