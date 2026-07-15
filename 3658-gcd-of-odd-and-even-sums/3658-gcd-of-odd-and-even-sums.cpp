class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int esum=0,osum=0;
        for(int i=1;i<=2*n;i+=2){
            esum+=i+1;
            osum+=i;
        }
        return __gcd(esum,osum);
    }
};