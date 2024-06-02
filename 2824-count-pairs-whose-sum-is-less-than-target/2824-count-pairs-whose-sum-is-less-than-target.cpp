class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // sort
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            int j = i + 1;
            while (j < n && nums[i] + nums[j] < target) {
                ++count;
                ++j;
            }
        }

        return count;
    }
};