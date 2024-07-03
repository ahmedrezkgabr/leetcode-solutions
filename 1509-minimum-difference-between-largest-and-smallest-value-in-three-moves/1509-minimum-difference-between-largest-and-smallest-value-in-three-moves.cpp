class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;

        std::sort(nums.begin(), nums.end());

        // Consider the following four scenarios:
        // 1. Change the 3 largest elements.
        // 2. Change the 2 largest and 1 smallest element.
        // 3. Change the 1 largest and 2 smallest elements.
        // 4. Change the 3 smallest elements.

        int diff1 = nums[n-1] - nums[3];
        int diff2 = nums[n-2] - nums[2];
        int diff3 = nums[n-3] - nums[1];
        int diff4 = nums[n-4] - nums[0];

        return std::min({diff1, diff2, diff3, diff4});
    }
};