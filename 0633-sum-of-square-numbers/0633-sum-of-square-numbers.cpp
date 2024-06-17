class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = static_cast<long>(sqrt(c));
        
        while (left <= right) 
        {
            long sumOfSquares = left * left + right * right;
            if (sumOfSquares == c) 
            {
                return true;
            } 
            else if (sumOfSquares < c) 
            {
                ++left;
            } 
            else 
            {
                --right;
            }
        }
        
        return false;
    }
};