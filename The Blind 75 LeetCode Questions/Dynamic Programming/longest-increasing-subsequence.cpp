class Solution {
public:

    int dp[3000][3000];
    int solve(int i,int j,vector<int>& nums){
        if(j >= nums.size() || i>= nums.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int op1=0,op2=0;
        // leave
        op1 = solve(i,j+1,nums);
        // take
        if(nums[j]>nums[i])
            op2 = 1+solve(j,j+1,nums);
        return dp[i][j] = max(op1,op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        nums.insert(nums.begin(), INT_MIN);
        return solve(0,1,nums);
    }

};
