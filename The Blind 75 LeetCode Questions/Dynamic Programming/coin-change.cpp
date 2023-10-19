class Solution {
public:
        int dp[(int)1e5];
    int solve(vector<int>& coins, int amount){
        if(amount==0)return 0;
        if(amount<0)return 1e9;
        int &ret=dp[amount];
        if(~ret)return ret;
        ret=1e9;
        for(auto i:coins){
            ret=min(ret,1+solve(coins,amount-i));
        }
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {

        memset(dp,-1,sizeof dp);
        int ans=solve(coins,amount);
        if(ans==1e9)return -1;
        return ans;

    }
};
