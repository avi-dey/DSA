// leetcode accepted
// https://leetcode.com/problems/super-egg-drop/
// optimized memo(left, right) + binary search instead of linear search

class Solution {
public:
    int rec(int e, int f, vector<vector<int>> &t)
    {
        if(e==1) return f;
        if(f==0 || f==1) return f;
        if(t[e][f] != -1) return t[e][f];
        int mn = INT_MAX;
        int l = 1, h = f;
        while(l<=h) 
        {
            int mid=l+(h-l)/2;
            // int a=rec(e-1,mid-1);
            int a = (t[e-1][mid-1]!=-1)? t[e-1][mid-1]: rec(e-1,mid-1, t);
            int b = (t[e][f-mid]!=-1)? t[e][f-mid]: rec(e,f-mid, t);
            // int b=rec(e,f-mid);
            int x=max(a,b) + 1;
            mn=min(mn,x);
            if(a>b) h=mid-1;
            else l=mid+1;
        }
        return t[e][f] = mn;
    }

    int superEggDrop(int e, int f) {
        vector<vector<int>> t(e+1, vector<int>(f+1, -1));
        return rec(e,f,t);
    }
};

