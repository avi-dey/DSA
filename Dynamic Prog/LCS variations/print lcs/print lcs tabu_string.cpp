// coding ninja accepted
//https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=SUBMISSION

string findLCS(int n, int m,string &s1, string &s2){
	// first we write code for normal lcs problem
	
	// keep in mind
	// here n = len(s1) & m = len(s2)

	//table
	int t[n+1][m+1];

	//initialisation
	for(int i = 0; i < m+1; i++) t[0][i] = 0;
	for(int i = 0; i < n+1; i++) t[i][0] = 0;

	//choice diagram
	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < m+1; j++){
			//equal
			if(s1[i-1] == s2[j-1]){
				t[i][j] = 1 + t[i-1][j-1];
			}
			else{ // not equal
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	//table is complete
	// now time to get string ans

	string ans= "";
	int i = n;
	int j = m;
	
	while(i > 0 && j > 0){
		// if equal
		// then add the char
		// and move to top-left diagonal
		if(s1[i-1]== s2[j-1]){
			ans.push_back(s1[i-1]);
			i--;
			j--;
		}
		else{// if not equal, then move to the max
			if(t[i-1][j] > t[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}
	//reverse the string
	reverse(ans.begin(), ans.end());
	return ans;
}