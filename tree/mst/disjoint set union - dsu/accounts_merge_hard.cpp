//GFG PASSED
// gfg medium but actually hard
// https://www.geeksforgeeks.org/problems/account-merge/1


class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        //part 1
        //mapping mails to nodes, if repeated emails are found, we union the nodes
        int n= accounts.size();
        unordered_map<string, int> mapMailNode;
        DisjointSet ds(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                //if not already in mapMailNode, just add it
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{ //mail is already present
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        //part 2
        //now, we do the merging, merging all emails to the ultimate parent
        vector<string> mergedAccounts[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = it.second;
            int ultParent = ds.findUPar(node);
            mergedAccounts[ultParent].push_back(mail);
        }
        
        // part 3 - sorting and adding the names
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergedAccounts[i].size() == 0) continue;
            sort(mergedAccounts[i].begin(), mergedAccounts[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]); //name of the account
            for(auto it: mergedAccounts[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        
        return ans;
    }
};
