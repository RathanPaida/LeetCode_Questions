class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int len = s.length();
        int num_digits = digits.size();
        int ans = 0;
        for (int i = 1; i < len; i++) {
            ans += pow(num_digits, i);
        }
        for (int i = 0; i < len; ++i) {
            bool has_same_digit = false;
            for (string &d : digits) {
                if (d[0] < s[i]) {
                    ans += pow(num_digits, len - 1 - i);
                } 
                else if (d[0] == s[i]) {
                    has_same_digit = true;
                }
            }
            if (!has_same_digit) {
                return ans;
            }
        }
        return ans + 1;
    }
};