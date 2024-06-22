class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int count = 0, prefixSum = 0;
        std::unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // to account for subarrays that start from index 0

        for (int num : nums) 
        {
            // increment the prefix sum if the current number is odd
            prefixSum += num % 2;

            // if there is a previous prefix sum that is `prefixSum - k`,
            // it means there are `k` odd numbers in the subarray.
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) 
            {
                count += prefixCount[prefixSum - k];
            }

            // increment the count of the current prefix sum in the map
            prefixCount[prefixSum]++;
        }

        return count; 
    }
};