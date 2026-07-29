class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied;
        
        vector<int> counts(n, 0);
        
        for (auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];
            
            while (!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }
            
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                counts[room]++;
                occupied.push({end, room});
            } else {
                auto [free_time, room] = occupied.top();
                occupied.pop();
                counts[room]++;
                occupied.push({free_time + (end - start), room});
            }
        }
        
        int max_room = 0;
        for (int i = 1; i < n; i++) {
            if (counts[i] > counts[max_room]) {
                max_room = i;
            }
        }
        
        return max_room;
    }
};