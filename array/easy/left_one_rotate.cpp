// cn passed
// https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i = 0; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
    return arr;
}

