//cn passed
// https://www.naukri.com/code360/problems/ninja-and-the-sorted-check_6581957?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM

int isSorted(int n, vector<int> arr) {
    // Write your code here.
    for(int i = 0; i < n-1; i++){
        if(arr[i+1] < arr[i]){
            return 0;
        }
    }
    return 1;
}
