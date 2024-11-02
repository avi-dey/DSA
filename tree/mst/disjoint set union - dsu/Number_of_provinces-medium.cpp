// gfg passed 
// solved myself
// https://www.geeksforgeeks.org/problems/number-of-provinces/1


//User function Template for C++

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // lets fix the format
        DisjointSet ds(V);
        vector<pair<int, pair<int,int>>> edges;
        
        //the matrix is 0 based, but the graph is 1 based
        for(int i = 0; i < V; i++){
            for(int j = 0; j< V; j++){
                if(adj[i][j] == 1 && i != j){
                    ds.unionBySize(i+1, j+1); //+1 bcz based graph
                }
            }
        }
        
        //find ultimate parent of all nodes and see how many are distinct
        //see how many distinct elements
        unordered_set<int> distinctElements;
        for(int i = 1; i <= V; ++i){
            distinctElements.insert(ds.findUPar(i));
        }
        
        return distinctElements.size();  // the number at 0th index is of no use      
    }
};
