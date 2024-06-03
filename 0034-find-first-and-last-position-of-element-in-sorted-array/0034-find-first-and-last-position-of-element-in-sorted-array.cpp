class Solution {
public:
    
    // Function to find the first occurrence of the target
    // By continue searching by moving the right limit
    int findFirst(const std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
            {
                result = mid;
                right = mid - 1; // Continue searching in the left half
            } 
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }

    // Function to find the last occurrence of the target
    // By continue searching by moving the left limit
    int findLast(const std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
            {
                result = mid;
                left = mid + 1; // Continue searching in the right half
            } 
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result(2, -1);
        result[0] = findFirst(nums, target);
        if (result[0] != -1) 
        {
            result[1] = findLast(nums, target);
        }
        return result;
    }
};