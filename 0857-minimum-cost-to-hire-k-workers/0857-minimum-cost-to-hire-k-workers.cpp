class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;
        int n = quality.size();
        
        for (int i = 0; i < n; ++i) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        sort(workers.begin(), workers.end());
        
        priority_queue<int> max_heap;
        int sum_quality = 0;
        double min_cost = 1e15;
        
        for (int i = 0; i < n; ++i) {
            double current_ratio = workers[i].first;
            int current_quality = workers[i].second;
            
            sum_quality += current_quality;
            max_heap.push(current_quality);
            
            if (max_heap.size() > k) {
                sum_quality -= max_heap.top();
                max_heap.pop();
            }
            
            if (max_heap.size() == k) {
                min_cost = min(min_cost, sum_quality * current_ratio);
            }
        }
        
        return min_cost;
    }
};