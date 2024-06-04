class Solution {
public:
    int longestPalindrome(string s) {
        
        // longest palindrome is consisting of the all even-freq letters + (the biggest even possible value) odd-freq letters + 1 (from the odd to be in the middle) 
        std::unordered_map<char, int> charCount;
    
        // count frequencies of each character
        for (char c : s)
            charCount[c]++;
        
        int length = 0;
        bool oddFound = false;

        // calculate the longest palindrome length
        for (const auto& pair : charCount) 
        {
            if (pair.second % 2 == 0) 
            {
                length += pair.second;  
            } 
            else 
            {
                length += pair.second - 1;
                oddFound = true;
            }
        }
        
        if (oddFound)
            length++;

        return length;
    }
};