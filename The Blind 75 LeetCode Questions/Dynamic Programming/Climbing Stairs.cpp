class Solution {
public:

    int dp[100];
    int solve(int i,int& n){
        if(i == n){
            return 1;
        }
        else if(i>n)
            return 0;
        if(dp[i]!=-1)return dp[i];
        //state
        int op1=0,op2=0;
        op1 = solve(i+1, n);
        op2 = solve(i+2, n);
        return dp[i] = op1+op2;    
    }
    
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,n);
    }
};



