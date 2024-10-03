// GFG ACCEPTED
// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends



// SOLUTION STARTS
int lcs(string a, string b){
    int m = a.size();
    int n = b.size();
    //table 
    int t[m+1][n+1];
    
    //initialisation
    for(int i = 0; i < m+1; i++) t[i][0] = 0;
    for(int i = 0; i < n+1; i++) t[0][i] = 0;
    //choice diagram
    for(int i =1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            //equal
            if(a[i-1] == b[j-1]) t[i][j] = 1+ t[i-1][j-1];
            else t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[m][n];
}

int minDeletions(string str, int n) { 
    //len(str) - len(lcs(str, rev(str))) = minimum number of deletion
    string rev= string(str.rbegin(), str.rend());
    int lps = lcs(str, rev); //lps = longest palindromic subsequence
    
    return n - lps;
} 
