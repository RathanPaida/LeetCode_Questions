class Solution {
private:
    bool isPredecessor(const string& word1, const string& word2) {
        if (word1.length() + 1 != word2.length()) return false;
        int i = 0;
        for (char c : word2) {
            if (i < word1.length() && word1[i] == c) {
                i++;
            }
        }
        return i == word1.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a,string& b) {
            return a.length() < b.length();
        });
        int n = words.size();
        vector<int> dp(n, 1);
        int max_chain = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_chain = max(max_chain, dp[i]);
        }
        
        return max_chain;
    }
};