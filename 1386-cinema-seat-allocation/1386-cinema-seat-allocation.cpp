class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMap;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reservedMap[row] |= (1 << col);
        }
        int maxFamilies = (n - reservedMap.size()) * 2;
        for (const auto& [row, reserved] : reservedMap) {
            bool leftFree = (reserved & 60) == 0;    
            bool rightFree = (reserved & 960) == 0;              
            bool midFree = (reserved & 240) == 0;    
            if (leftFree && rightFree) {
                maxFamilies += 2;
            } else if (leftFree || rightFree || midFree) {
                maxFamilies += 1;
            }
        }
        return maxFamilies;
    }
};