class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size();
        
        if (size % groupSize)
            return false;
        
        // count the freq of each card
        std::map<int, int> count;
        for (int card : hand)
        {
            count[card]++;
        }
        
        for (auto it = count.begin(); it != count.end(); ++it)
        {
            // get the card's number and freq
            int startCard = it->first;
            int freq = it->second;
            if (freq > 0)
            {
                // try to form a group starting with startCard
                for (int i = 0; i < groupSize; ++i)
                {
                    int card = startCard + i;
                    if (count[card] < freq)
                    {
                        return false;
                    }
                    count[card] -= freq;
                }
            }
        }

        return true;
    }
};