class Solution {
    public long sumAndMultiply(int n) {
        String s = String.valueOf(n);
        int x = 0;
        int sum = 0;
        for (char c : s.toCharArray()) {
            int t = c - '0';
            if (t != 0) {
                x = (x * 10 + t);
                sum += t;
            }
        }
        return (long )x * sum;
    }
}