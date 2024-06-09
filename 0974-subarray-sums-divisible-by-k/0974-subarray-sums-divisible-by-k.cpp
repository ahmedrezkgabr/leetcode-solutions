class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // initialize with 0 sum having one occurrence
        
        int count = 0, prefixSum = 0;

        for (int num : nums) 
        {
            prefixSum += num;
            
            // take modulo k and handle negative values correctly
            int mod = ((prefixSum % k) + k) % k;
            
            // if mod is found in the map, add its count to the result
            if (prefixSumCount.find(mod) != prefixSumCount.end()) 
            {
                count += prefixSumCount[mod];
            }
            
            // update the map with the current mod
            prefixSumCount[mod]++;
        }

        return count; 
    }
};