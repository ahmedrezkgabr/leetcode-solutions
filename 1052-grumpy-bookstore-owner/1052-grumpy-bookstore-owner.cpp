class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
    
        // calculate the number of customers satisfied without using the secret technique
        int satisfied_customers = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (grumpy[i] == 0) 
            {
                satisfied_customers += customers[i];
            }
        }

        // calculate the additional customers that can be satisfied using the secret technique
        int max_additional_satisfied = 0;
        int current_additional_satisfied = 0;

        // calculate the additional satisfied customers for the first X minutes window
        for (int i = 0; i < minutes; ++i) 
        {
            if (grumpy[i] == 1) 
            {
                current_additional_satisfied += customers[i];
            }
        }
        
        max_additional_satisfied = current_additional_satisfied;

        // use sliding window to find the optimal position for the secret technique
        for (int i = minutes; i < n; ++i) 
        {
            if (grumpy[i] == 1) 
            {
                current_additional_satisfied += customers[i];
            }
            
            if (grumpy[i - minutes] == 1) 
            {
                current_additional_satisfied -= customers[i - minutes];
            }
            
            max_additional_satisfied = std::max(max_additional_satisfied, current_additional_satisfied);
        }

        return satisfied_customers + max_additional_satisfied;
    }
};