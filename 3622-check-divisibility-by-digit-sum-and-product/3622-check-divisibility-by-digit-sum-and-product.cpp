class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int nu=n;
        while(n>0){
            int t=n%10;
            sum+=t;
            prod*=t;
            n/=10;
        }
        sum+=prod;
        return (nu%sum==0)?true:false;
    }
};