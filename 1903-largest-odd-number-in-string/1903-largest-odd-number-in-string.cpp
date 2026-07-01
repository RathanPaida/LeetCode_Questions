class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int idx=-1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return ans;
        }
        for(int i=0;i<=idx;i++){
            ans+=num[i];
        }
        return ans;
    }
};