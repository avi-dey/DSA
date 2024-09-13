// cn passed
// https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

vector<int> getSecondOrderElements(int n, vector<int> a) {
    //lets first find the largest element in array
    vector<int> ans(2);

    int largest = INT_MIN;
    int smallest = INT_MAX;
    for(int i = 0; i< n; i++){
        largest = max(largest, a[i]);
        smallest = min(smallest, a[i]);
    }

    int sec_largest = INT_MIN;
    int sec_smallest = INT_MAX;
    for(int i = 0; i < n; i++){
        if(a[i] > sec_largest && a[i] < largest){
            sec_largest = a[i];
        }
        if(a[i] > smallest && a[i] < sec_smallest){
            sec_smallest = a[i];
        }
    }
    ans[0] = sec_largest;
    ans[1] = sec_smallest;
    return ans;
}

