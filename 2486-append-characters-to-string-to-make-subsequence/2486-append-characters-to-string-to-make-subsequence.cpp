class Solution {
public:
    int appendCharacters(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        int j = 0; // Pointer for t

        for (int i = 0; i < sLength && j < tLength; ++i) {
            if (s[i] == t[j]) {
                ++j; // Move to the next character in t
            }
        }

        // If j < tLength, it means not all characters of t were found in s
        return tLength - j;
    }
};