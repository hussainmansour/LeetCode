class Solution {
public:
    int dp[1005][1005]; 
    int solve(int ind1,int ind2,string& text1, string& text2){
        if(ind1 == text1.size()||ind2 == text2.size())
            return 0;   
        int& ret = dp[ind1][ind2];
        if(~ret) return ret;

        int op1=0,op2=0, op3 = 0;
        if(text1[ind1]==text2[ind2])
            op1 = 1+solve(ind1+1,ind2+1,text1,text2);
        else{
            op2 = max(solve(ind1+1,ind2,text1,text2), solve(ind1,ind2+1,text1,text2));
        }
        return ret = max(op1,op2);    
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,text1,text2);
    }
};
