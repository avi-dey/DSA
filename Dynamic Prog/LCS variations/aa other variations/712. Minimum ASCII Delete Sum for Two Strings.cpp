#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // lcs
        // sea -> eat   => lcs = ea
        // lcs variations, just store ascii sum for the not matching chars

        int m = s1.size();
        int n = s2.size();
        
        //table 
        int t[m+1][n+1];

        // init
        t[0][0] = 0;
        for (int i = 1; i < m + 1; i++) //row
            t[i][0] =  t[i-1][0] + (int)s1[i-1]; // ascii sum
        for (int i = 1; i < n + 1; i++)
            t[0][i] = t[0][i-1] + (int)s2[i-1]; // ascii sum

        // choice diagram
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = t[i - 1][j - 1];
                } else { //not equal then take min ascii sum
                    t[i][j] = min((int)s1[i-1] + t[i - 1][j] //ascii sum
                                        , (int)s2[j-1] + t[i][j - 1]); //ascii sum
                }
            }
        }
        return t[m][n];
    }
};

int main(){
    Solution ob;
    int ans = ob.minimumDeleteSum("delete", "leet");
    cout << ans << endl;

    return 0;
}