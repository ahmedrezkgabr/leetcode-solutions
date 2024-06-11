class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // count the occurrences of each element in arr1
        unordered_map<int, int> countMap;
        for (int num : arr1) countMap[num]++;

        // sort arr1 according to the order in arr2
        vector<int> result;
        for (int num : arr2) 
        {
            while (countMap[num] > 0) 
            {
                result.push_back(num);
                countMap[num]--;
            }
        }

        // collect remaining elements and sort them
        vector<int> remaining;
        for (auto& pair : countMap) 
        {
            while (pair.second > 0) 
            {
                remaining.push_back(pair.first);
                pair.second--;
            }
        }
        sort(remaining.begin(), remaining.end());

        // append the remaining sorted elements to the result
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};