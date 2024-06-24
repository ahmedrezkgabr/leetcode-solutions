class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> flip(n, 0); // Auxiliary array to track flips
        int flipCount = 0; // To track the number of flips done
        int result = 0; // To store the result (number of k-bit flips required)

        for (int i = 0; i < n; ++i) 
        {
            if (i >= k) 
            {
                flipCount ^= flip[i - k]; // Update flipCount by removing the effect of the out-of-window flip
            }
            
            if ((nums[i] ^ flipCount) == 0) 
            { 
                // If the current bit needs flipping
                if (i + k > n) 
                {
                    return -1; // If there are not enough bits to flip
                }
                
                flipCount ^= 1; // Flip the current bit
                flip[i] = 1; // Mark the flip in the auxiliary array
                result++; // Increment the result counter
            }
        }
        
        return result;
    }
};