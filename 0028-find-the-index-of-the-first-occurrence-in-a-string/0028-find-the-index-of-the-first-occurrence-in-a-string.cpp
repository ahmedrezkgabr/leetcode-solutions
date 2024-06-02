class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayLength = haystack.length();
        int needleLength = needle.length();
    
        // base cases
        // if needle is empty, return 0
        if (needleLength == 0) { return 0; }

        // if haystack is shorter than needle, needle cannot be part of haystack
        if (hayLength < needleLength) { return -1; }

        for (int i = 0; i <= hayLength - needleLength; ++i) {
            bool found = true;
            for (int j = 0; j < needleLength; ++j) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }

        return -1; // needle not found in haystack
    }
};