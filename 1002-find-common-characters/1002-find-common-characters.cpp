class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
         std::vector<int> minFreq(26, INT_MAX); // initialize with maximum value
        std::vector<int> charCount(26, 0);     // temporary character frequency count

        // iterate over each word in the input list
        for (const std::string& word : words)
        {
            std::fill(charCount.begin(), charCount.end(), 0); // reset temporary count

            // count the frequency of each character in the current word
            for (char ch : word) 
                charCount[ch - 'a']++;


            // update the minimum frequency of each character
            for (int i = 0; i < 26; i++)
                minFreq[i] = std::min(minFreq[i], charCount[i]);
        }

        // collect the common characters based on the minimum frequencies
        std::vector<std::string> result;
        for (int i = 0; i < 26; i++) 
        {
            for (int j = 0; j < minFreq[i]; j++) 
            {
                result.push_back(std::string(1, i + 'a'));
            }
        }

        return result;
    }
};