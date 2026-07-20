class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first_pos = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                first_pos = mid;
                right = mid - 1; 
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first_pos;
    }

    int findLast(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int last_pos = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                last_pos = mid;
                left = mid + 1; 
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return last_pos;
    }
};