//gfg passed
// https://www.geeksforgeeks.org/problems/number-of-islands/1


// Disjoint Set Template for Java
class DisjointSet {
    List<Integer> rank = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();
    List<Integer> size = new ArrayList<>();
    public DisjointSet(int n) {
        for (int i = 0; i <= n; i++) {
            rank.add(0);
            parent.add(i);
            size.add(1);
        }
    }

    public int findUPar(int node) {
        if (node == parent.get(node)) {
            return node;
        }
        int ulp = findUPar(parent.get(node));
        parent.set(node, ulp);
        return parent.get(node);
    }

    public void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank.get(ulp_u) < rank.get(ulp_v)) {
            parent.set(ulp_u, ulp_v);
        } else if (rank.get(ulp_v) < rank.get(ulp_u)) {
            parent.set(ulp_v, ulp_u);
        } else {
            parent.set(ulp_v, ulp_u);
            int rankU = rank.get(ulp_u);
            rank.set(ulp_u, rankU + 1);
        }
    }

    public void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size.get(ulp_u) < size.get(ulp_v)) {
            parent.set(ulp_u, ulp_v);
            size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
        } else {
            parent.set(ulp_v, ulp_u);
            size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
        }
    }
}
class Solution {
    private boolean isValidCell(int adjrow, int adjcol, int n, int m){
        return adjrow < n && adjrow >= 0 && adjcol < m && adjcol >= 0;
    }
    public List<Integer> numOfIslands(int n, int m, int[][] operators) {
        DisjointSet ds = new DisjointSet(n * m);
        List<Integer> ans = new ArrayList<>();
        int[][] vis = new int[n][m];
        int cnt = 0;
        int len = operators.length;
        for(int i = 0; i < len; i++){
            int row = operators[i][0];
            int col = operators[i][1];
            if(vis[row][col] == 1){
                ans.add(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            int[] delrow = {0, -1, 0, 1};
            int[] delcol = {-1, 0, 1, 0};
            for(int j= 0; j < 4; j++){
                int adjrow = row + delrow[j];
                int adjcol = col + delcol[j];
                if(isValidCell(adjrow, adjcol, n, m) && vis[adjrow][adjcol] == 1){
                    int nodeNumber = row * m + col;
                    int adjNodeNumber = adjrow * m + adjcol;
                    if(ds.findUPar(nodeNumber) != ds.findUPar(adjNodeNumber)){
                        cnt--;
                        ds.unionBySize(nodeNumber, adjNodeNumber);
                    }
                }    
            }
            ans.add(cnt);
            
        }
        return ans;
    }
    
}
