// cn passed
// https://www.codingninjas.com/studio/problems/palindrome-partitioning-ll_873266?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j){
    while(i<= j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(string &str, int i, int n, vector<int> &t){
    //base case
    if(i == n){
        return 0;
    }

    if(t[i] != -1) return t[i];

    int mn = INT_MAX;
    for(int k = i; k <= n-1; k++){
        if(isPalindrome(str, i, k)){
            int cuts_count = 1 + solve(str, k+1, n, t);
            mn = min(mn, cuts_count);
        }
    }
    return t[i] = mn;
}

int palindromePartitioning(string str)
{
    int n = str.size();

    vector<int> t(n, -1);
    return solve(str, 0, n, t)-1;
}
