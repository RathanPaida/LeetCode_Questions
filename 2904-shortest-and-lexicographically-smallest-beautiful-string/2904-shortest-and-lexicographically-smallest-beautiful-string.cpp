class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;
        int n=s.size();
        int l=0,r=0;
        int cnt=0;
        int mini=INT_MAX;
        for(int r=0;r<n;r++){
            if(s[r]=='1'){
                cnt++;
            }
            while(cnt>k){
                if(s[l]=='1'){
                    cnt--;
                    l++;
                }
            }
            while(s[l]=='0'){
                l++;
            }
            if(cnt==k){
                if((r-l+1<mini)){
                    ans.clear();
                    string t = s.substr(l, r - l + 1);
                    ans.push_back(t);
                    mini=r-l+1;
                }
                else if((r-l+1==mini)){
                    string t = s.substr(l, r - l + 1);
                    ans.push_back(t);
                }
            }
        }
        sort(ans.begin(),ans.end());
        string emp="";
        return ans.empty()?emp:ans[0];
    }
};