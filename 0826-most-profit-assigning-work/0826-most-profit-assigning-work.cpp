class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // create pairs of (difficulty, profit)
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) 
        {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        
        // sort jobs and workers
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        int totalProfit = 0;
        int jobIndex = 0;
        
        for (int ability : worker) 
        {
            // Update maxProfit to the maximum profit a worker with the current ability can get
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= ability) 
            {
                maxProfit = max(maxProfit, jobs[jobIndex].second);
                jobIndex++;
            }
            
            // add the best available profit for the current worker's ability
            totalProfit += maxProfit;
        }
        
        return totalProfit;
    }
};