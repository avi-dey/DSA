// cn passed
// https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=SUBMISSION

int removeDuplicates(vector<int> &arr, int n) {
	if(n == 0) return 0;
	
	vector<int> vec;
	for(int i = 0; i < n-1; i++){
		if(arr[i] != arr[i+1]){
			vec.push_back(arr[i]);
		}
	}
	return vec.size()+1; //+1 for the last element
}
