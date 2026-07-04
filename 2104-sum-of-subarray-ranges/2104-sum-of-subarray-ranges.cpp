class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> stk; 
        stack<int> s;
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && nums[stk.top()] <= nums[i]) stk.pop();
            right[i] = stk.empty() ? n-i : stk.top() - i;
            stk.push(i);
        }
        for(int i = 0; i < n;i++){
            while(!s.empty() && nums[s.top()] < nums[i]) s.pop();
            left[i] = s.empty() ? i+1 : i - s.top();
            s.push(i); 
        }
        long long largest = 0;
        for(int i = 0; i <n;i++){
            largest += (1LL * left[i] * right[i] * nums[i]);
        }
        stk = stack<int>();
        s = stack<int>();
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
            smallest += (1LL * left[i] * right[i] * nums[i]);
        }
        return largest - smallest;
    }
};