//gfg passed 
// solved by myself
// https://www.geeksforgeeks.org/problems/connecting-the-graph/1?

class DisjointSet {
    vector<int> parent, size; 
public: 
    DisjointSet(int n) {
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

    // if union is performed we return 1 otherwise 0
    bool unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return 0; //union not performed
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
        return 1; //union performed
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // lets first find no. of extra edges
        int m = edge.size(); //total edges
        DisjointSet ds(n);
        
        int cnt = 0;
        for(auto it: edge){
            int u = it[0];
            int v = it[1];
            if(ds.unionBySize(u,v)){
                cnt++; //exectutes only if union is performed
            }
        }
        
        int extra_edges = m - cnt;
        
        //lets now find the no. of components
        // logic : no. of edges required = total no. of components - 1
        
        int edges_req;
        unordered_set<int> total_components;
        for(int i = 0; i < n; i++){
            total_components.insert(ds.findUPar(i));
        }
        
        edges_req = total_components.size() - 1;
        
        //final logic
        if(extra_edges >= edges_req) return edges_req;
        else return -1; //extra edges < edges required
    }
};
