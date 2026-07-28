class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> mp(26, 0);
        for (char c : s) {
            mp[c - 'a']++;
        }
        string leftHalf = "";
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (mp[i] != 0) {
                if (mp[i] % 2 != 0) {
                    middle = string(1, 'a' + i);
                }
                leftHalf += string(mp[i] / 2, 'a' + i);
            }
        }
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + middle + rightHalf;
    }
};