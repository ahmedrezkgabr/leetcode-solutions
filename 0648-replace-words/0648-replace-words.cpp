class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // create a set of roots for quick lookup
        std::unordered_set<std::string> rootSet(dictionary.begin(), dictionary.end());

        // stream the sentence for word-by-word processing
        std::istringstream iss(sentence);
        std::string word;
        std::string result;

        // process each word in the sentence
        while (iss >> word) 
        {
            std::string prefix;
            // check each prefix of the word to see if it's in the root set
            for (int i = 1; i <= word.length(); ++i) 
            {
                prefix = word.substr(0, i);
                if (rootSet.find(prefix) != rootSet.end()) break;
            }
            
            // append the prefix or the original word if no prefix was found
            if (!result.empty())    result += " ";
            
            result += prefix;
        }

        return result;
    }
};