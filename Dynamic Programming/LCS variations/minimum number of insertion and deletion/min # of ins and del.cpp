// gfg accepted
// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int m = str1.size();
	    int n = str2.size();
	    
	    //table
	    int t[m+1][n+1];
	    
	    //initialistaton
	    for(int i = 0; i < m+1; i++) t[i][0]=0;
	    for(int i = 0; i < n+1; i++) t[0][i]=0;
	    
	    // choice diagram
	    for(int i = 1; i < m+1; i++){
	        for(int j =1; j< n+1; j++){
	            //equal
	            if(str1[i-1] == str2[j-1]){
	                t[i][j] = 1+ t[i-1][j-1];
	            }else{ //not equal
	                t[i][j] = max(t[i-1][j], t[i][j-1]);
	            }
	        }
	    }
	    //we have the table
	    
	    // t[m][n] = len(lcs)
	    int del = m- t[m][n];
	    int ins = n- t[m][n];
	    
	    return del+ins;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
