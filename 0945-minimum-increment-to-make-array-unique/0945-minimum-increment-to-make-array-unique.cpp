class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int moves = 0;

        for (int i = 1; i < nums.size(); ++i) 
        {
            if (nums[i] <= nums[i - 1]) 
            {
                int new_value = nums[i - 1] + 1;
                moves += new_value - nums[i];
                nums[i] = new_value;
            }
        }

        return moves;
    }
};