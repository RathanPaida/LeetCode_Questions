class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> stk; 
        stack<int> s;
        int mod=1e9+7;
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            right[i] = stk.empty() ? n-i : stk.top() - i;
            stk.push(i);
        }
        for(int i = 0; i < n;i++){
            while(!s.empty() && nums[s.top()] > nums[i]) s.pop();
            left[i] = s.empty() ? i+1 : i - s.top();
            s.push(i); 
        }
        long long smallest = 0;
        for(int i = 0; i <n;i++){
            smallest =(smallest+ (1LL * left[i] * right[i] * nums[i]))%mod;
        }
        return smallest;
    }
};
