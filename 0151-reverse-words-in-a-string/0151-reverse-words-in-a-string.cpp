class Solution {
public:
    string reverseWords(string s) {
        vector<string> a;
        string t = "";
        for (char ch : s) {
            if (ch == ' ') {
                if (!t.empty()) {
                    a.push_back(t);
                }
                t = "";
            } else {
                t += ch;
            }
        }
        if (!t.empty()) {
            a.push_back(t);
        }
        reverse(a.begin(), a.end());
        string ans = "";
        for (int i = 0; i < a.size(); i++) {
            for (char ch : a[i]) {
                ans += ch;
            }
            if (i != a.size() - 1) {
                ans += ' ';
            }
        }

        return ans;
    }
};