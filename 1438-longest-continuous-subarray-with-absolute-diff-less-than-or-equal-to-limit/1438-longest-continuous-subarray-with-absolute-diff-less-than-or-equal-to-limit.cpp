class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::deque<int> maxDeque, minDeque;
        int left = 0, right;
        for (right = 0; right < nums.size(); ++right) 
        {
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) 
            {
                maxDeque.pop_back();
            }
            
            maxDeque.push_back(nums[right]);

            while (!minDeque.empty() && nums[right] < minDeque.back()) 
            {
                minDeque.pop_back();
            }
            
            minDeque.push_back(nums[right]);

            if (maxDeque.front() - minDeque.front() > limit) 
            {
                if (maxDeque.front() == nums[left]) 
                {
                    maxDeque.pop_front();
                }
                
                if (minDeque.front() == nums[left]) 
                {
                    minDeque.pop_front();
                }
                
                ++left;
            }
        }
        
        
        return right - left;
    }
};