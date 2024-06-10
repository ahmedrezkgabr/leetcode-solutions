class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // create a copy of heights and sort it to get the expected order
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());

        // count the number of indices where heights[i] != expected[i]
        int count = 0;
        for (int i = 0; i < heights.size(); ++i) 
        {
            if (heights[i] != expected[i]) 
            {
                count++;
            }
        }

        return count;
    }
};