// MST by Prim's Algo
//gfg passed
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        
        pq.push({0, 0}); // (wt, node)
        // we are not doing (wt, node, parent) format because MST vector is not
        // asked in this question
        
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(vis[node] == 1) continue;
            //if not visited:
            sum += wt;
            vis[node] = 1;
            
            for(auto it: adj[node]){
                int nbr = it[0]; //nbr = neighbour
                int nbrWt = it[1]; 
                if(!vis[nbr]){
                    pq.push({nbrWt, nbr});
                }
            }
        }
        return sum;
    }
};
