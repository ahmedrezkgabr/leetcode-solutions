class UnionFind 
{
public:
    vector<int> parent, rank;

    UnionFind(int n) 
    {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) 
    {
        if (u != parent[u]) parent[u] = find(parent[u]);
        
        return parent[u];
    }

    bool unite(int u, int v) 
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        
        if (rank[pu] < rank[pv]) swap(pu, pv);
        
        parent[pv] = pu;
        
        if (rank[pu] == rank[pv])   rank[pu]++;
        
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufAlice(n + 1), ufBob(n + 1);
        int removedEdges = 0;
        int commonEdgesUsed = 0;

        // 3
        for (const auto& edge : edges) 
        {
            if (edge[0] == 3) {
                if (ufAlice.unite(edge[1], edge[2])) 
                {
                    ufBob.unite(edge[1], edge[2]);
                    commonEdgesUsed++;
                } 
                else removedEdges++;
                
            }
        }

        // 1
        for (const auto& edge : edges) 
        {
            if (edge[0] == 1) 
            {
                if (!ufAlice.unite(edge[1], edge[2])) 
                {
                    removedEdges++;
                }
            }
        }

        // 2
        for (const auto& edge : edges) 
        {
            if (edge[0] == 2) 
            {
                if (!ufBob.unite(edge[1], edge[2])) 
                {
                    removedEdges++;
                }
            }
        }

        // if both Alice and Bob can traverse the entire graph
        for (int i = 1; i <= n; ++i) 
        {
            if (ufAlice.find(i) != ufAlice.find(1) || ufBob.find(i) != ufBob.find(1)) 
            {
                return -1;
            }
        }

        return removedEdges;
    }
};