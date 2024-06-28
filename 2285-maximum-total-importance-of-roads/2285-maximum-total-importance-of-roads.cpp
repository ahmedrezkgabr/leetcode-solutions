class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        /*
        assign higher values to cities with more roads 
        because those values will contribute more frequently to the total importance.
        */
        
        
        // count the number of roads each city is connected to
        std::vector<int> roadCount(n, 0);
        for (const auto& road : roads) 
        {
            roadCount[road[0]]++;
            roadCount[road[1]]++;
        }

        // create a vector of city indices and sort it based on the road count in descending order
        vector<int> cities(n);
        iota(cities.begin(), cities.end(), 0); // fill with 0, 1, ..., n-1 -> cities IDs
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return roadCount[a] > roadCount[b];
        });

        // assign values to the cities
        vector<int> cityValue(n);
        for (int i = 0; i < n; ++i) 
        {
            cityValue[cities[i]] = n - i;
        }

        // calculate the total importance
        long long totalImportance = 0;
        for (const auto& road : roads) 
        {
            totalImportance += cityValue[road[0]] + cityValue[road[1]];
        }

        return totalImportance;
    }
};