class Solution {
private:
    int BASE = 1000000;
public:
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(Rabin_Karp(source,B) != -1) return count;
        if(Rabin_Karp(source+A,B) != -1) return count+1;
        return -1;
    }
    int Rabin_Karp(string source, string target){
        if(source==""||target==""){
            return -1;
        }
        long long power=1;
        int m=target.size();
        for(int i=0;i<m;i++){
            power=(power*31*1LL)%BASE;
        }
        long long thash=0;
        for(int i=0;i<m;i++){
            thash=(thash*31*1LL+target[i])%BASE;
        }
        long long shash=0;
        int n=source.size();
        for(int i=0;i<n;i++){
            shash=(shash*31*1LL+source[i])%BASE;
            if(i<m-1){
                continue;
            }
            if(i>=m){
            shash=(shash-source[i-m]*power)%BASE;
            }
            if(shash<0)shash+=BASE;
            if(shash==thash){
                string ss=source.substr(i-m+1,m);
                if(ss==target){
                    return i-m+1;
                }
            }
        }
        return -1;
    }
};