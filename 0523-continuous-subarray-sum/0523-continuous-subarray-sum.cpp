class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if the array has less than 2 elements, return false
        if (nums.size() < 2)    return false;

        // This map will store the remainder when the cumulative sum is divided by k
        std::unordered_map<int, int> remainderMap;
        remainderMap[0] = -1; // To handle the case where the subarray starts from index 0

        int cumulativeSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            cumulativeSum += nums[i];

            // calculate remainder of the current cumulative sum divided by k
            int remainder = cumulativeSum % k;

            // adjust remainder to handle negative values (if k is negative)
            if (remainder < 0)  remainder += k;

            // check if this remainder has been seen before
            if (remainderMap.find(remainder) != remainderMap.end()) 
            {
                // if the previous occurrence of this remainder was at least two indices before the current index
                if (i - remainderMap[remainder] > 1) 
                {
                    return true;
                }
            } 
            else 
            {
                // store the index of the first occurrence of this remainder
                remainderMap[remainder] = i;
            }
        }

        return false;
    }
};