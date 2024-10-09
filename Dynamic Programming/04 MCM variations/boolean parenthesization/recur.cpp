// cn tle
// https://www.codingninjas.com/studio/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=SUBMISSION



const int MOD = 1e9+7;

int solve(string &s, int i, int j, bool isTrue){
    //base cases
    if(i>j) return 0; // 0 no. of ways

    if(i==j){
        //if we want true
        if(isTrue == 1){
            return s[i] == 'T';
        }else{ // if we want false
            return s[i] == 'F';
        }
    }

    int ans = 0;
    for(int k = i+1; k < j; k+=2){
        int leftTrue = solve(s, i, k-1, 1);
        int leftFalse = solve(s, i, k-1, 0);
        int rightTrue = solve(s, k+1, j, 1);
        int rightFalse = solve(s, k+1, j, 0);
        
        if(s[k] == '&'){
            // T & T = T.
            //T & F, F & F, F & T = F
            if(isTrue){
                ans = (ans + (leftTrue * rightTrue)%MOD)%MOD; 
            }else{
                ans = (ans + (leftTrue * rightFalse)%MOD
                        + (leftFalse * rightFalse)%MOD
                        + (leftFalse * rightTrue)%MOD)%MOD;
            }
        }
        else if(s[k] == '|'){
            // T or F, T or T, F or T = T
            // F or F = F
            if(isTrue){
                ans = (ans + (leftTrue * rightFalse)%MOD
                        + (leftTrue * rightTrue)%MOD
                        + (leftFalse * rightTrue)%MOD)%MOD;
            }else{
                ans = (ans + (leftFalse * rightFalse)%MOD)%MOD;
            }
        }
        else{ // s[k] == '^'
            // T xor F, F xor T = T
            // T xor T, F xor F = F
            if(isTrue){
                    ans = (ans + (leftTrue * rightFalse)%MOD
                        + (leftFalse * rightTrue)%MOD)%MOD;
            } else {
                    ans = (ans + (leftFalse * rightFalse)%MOD
                                + (leftTrue * rightTrue)%MOD)%MOD;
            }
        }
    }
    return ans;
}
int evaluateExp(string & exp) {
    return solve(exp, 0, exp.size()-1, true);
