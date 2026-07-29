class Solution {
private:
    int calcDistance(int x, int y) {
        return x * x + y * y;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Pair structure: {distance, index_of_point}
        // Using a min-heap (greater comparison) to keep smallest distances at top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < points.size(); i++) {
            int dist = calcDistance(points[i][0], points[i][1]);
            minHeap.push({dist, i});
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            int pointIdx = minHeap.top().second;
            minHeap.pop();
            ans.push_back(points[pointIdx]);
        }

        return ans;
    }
};