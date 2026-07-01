class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto &i:s){
            m[i]++;
        }
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.second > b.second;
        });
        int j=0;
        for(auto &i:v){
            int k=i.second;
            while(k--){
                s[j]=i.first;
                j++;
            }
        }
        return s;
    }
};
