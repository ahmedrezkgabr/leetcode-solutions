class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
         // since it's guaranteed to be a star graph, we can just check the first two edges
        int u1 = edges[0][0], v1 = edges[0][1];
        int u2 = edges[1][0], v2 = edges[1][1];

        if (u1 == u2 || u1 == v2) return u1;
        else return v1;
    }
};