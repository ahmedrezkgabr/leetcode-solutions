class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int left = 1; // minimum possible distance
        int right = position.back() - position.front(); // maximum possible distance
        
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (canPlaceBalls(position, m, mid)) 
            {
                left = mid; // mid is possible, so search in the right half
            } 
            else 
            {
                right = mid - 1; // mid is not possible, so search in the left half
            }
        }
        
        return left;
    }
    
private:
    bool canPlaceBalls(const vector<int>& position, int m, int minForce) 
    {
        int count = 1; // place the first ball in the first basket
        int lastPos = position[0]; // position of the last placed ball
        
        for (int i = 1; i < position.size(); ++i) 
        {
            if (position[i] - lastPos >= minForce) 
            {
                count++;
                lastPos = position[i]; // update the last position
                if (count == m) return true; // placed all balls
            }
        }
        
        return false; // not able to place all balls with at least minForce distance
    }
};