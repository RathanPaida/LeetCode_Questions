class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string> s;
        for(int i=0;i<word.size();i++){
            string t="";
            for(int j=i;j<word.size();j++){
                t+=word[j];
                if(s.find(t)==s.end()){
                    s.insert(t);
                }
            }
        }
        int cnt=0;
        for(string i:patterns){
            if(s.find(i)!=s.end()){
                cnt++;
            }
        }
        return cnt;
    }
};