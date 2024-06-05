class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // initialize the prefix with the first string
        std::string prefix = strs[0];

        // compare the prefix with each string in the array
        for (int i = 1; i < strs.size(); ++i) 
        {
            // find the common prefix between the current prefix and strs[i]
            while (strs[i].find(prefix) != 0) 
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};