struct Project 
{
    int capital;
    int profit;
    Project(int c, int p) : capital(c), profit(p) {}
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n = profits.size();
        vector<Project> projects;
        for (int i = 0; i < n; ++i) 
        {
            projects.push_back(Project(capital[i], profits[i]));
        }

        // min-heap to sort projects by their required capital
        priority_queue<int, vector<int>, greater<int>> minCapitalHeap;
        
        // max-heap to get the project with the maximum profit we can currently afford
        priority_queue<int> maxProfitHeap;

        // sorting projects by capital required
        sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {return a.capital < b.capital;});

        int projectIndex = 0;

        for (int i = 0; i < k; ++i) 
        {
            // move all projects we can afford to the max-profit heap
            while (projectIndex < n && projects[projectIndex].capital <= w) 
            {
                maxProfitHeap.push(projects[projectIndex].profit);
                projectIndex++;
            }

            // if no projects can be afforded, break out
            if (maxProfitHeap.empty()) break;

            // select the project with the maximum profit
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w; 
    }
};