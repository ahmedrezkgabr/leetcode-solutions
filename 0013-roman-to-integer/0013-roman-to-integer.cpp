class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;
        
         for (char c : s) 
         {
            int currentValue = romanMap[c];

            /*  if the current value is greater than the previous value,
                it means we have encountered a subtractive combination. (i.e. IX -> previous was I(1) and the current is X(10))
                so subract the previous value twice because we have added it in the previous iteration (total was 1 so we need to subtract 1 twice before adding 10 so the total becomes 9) */
             if (currentValue > prevValue) 
                total += currentValue - 2 * prevValue;
            else
                total += currentValue;


            prevValue = currentValue;
        }

        return total;
    }
};