class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        int cnt=1;
        set<int> s;
        for(int i:arr){
            s.insert(i);
        }
        for(int i:s){
            mp[i]=cnt;
            cnt++;
        }
        vector<int> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};