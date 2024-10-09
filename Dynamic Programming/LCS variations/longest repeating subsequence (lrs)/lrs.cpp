// gfg accepted
// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    
		    //table
		    int t[n+1][n+1];
		    
		    //initialisation
		    for(int i =0; i < n+1; i++){
		         t[i][0] =0; //left-most col
		         t[0][i] =0; //top row
		    }
		    
		    //choice diagram
		    for(int i = 1; i< n+1; i++){
		        for(int j =1; j < n+1; j++){
		            //equal [ONLY CHANGE TO ENTIRE LCS CODE TO MAKE IT LRS]
		            if(str[i-1] == str[j-1] && i != j){
		                t[i][j] = 1+ t[i-1][j-1];
		            }
		            else{
		                t[i][j] = max(t[i-1][j], t[i][j-1]);
		            }
		        }
		    }
		    return t[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
