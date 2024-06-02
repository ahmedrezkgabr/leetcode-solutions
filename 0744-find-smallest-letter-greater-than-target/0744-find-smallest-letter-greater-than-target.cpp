class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // search boundries 
        int left = 0;
        int right = letters.size() - 1;
    
        // binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;
        
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    
    // if left is out of bounds, return the first character otherwise, return the character at index left
    return (left < letters.size()) ? letters[left] : letters[0];
    }
};