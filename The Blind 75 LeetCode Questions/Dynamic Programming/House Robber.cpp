class Solution {
public:
    int dp[105][105]; 
    int solve(int lst,int i,vector<int>& nums)
    {
        if(i >= nums.size())
        {
            return 0;
        }
        int & ret = dp[lst][i];
        if(~ret)
            return ret;
        int op1=0,op2=0;
        // leave
        op1 = solve(lst,i+1,nums);
        // take
        if(abs(lst-i)>1)
            op2 = nums[i]+solve(i,i+1,nums);
        return ret = max(op1,op2);
    } 
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        vector<int> temp;
        temp.push_back(0);
        temp.push_back(0);
        for(auto i:nums)temp.push_back(i);
        return solve(0,2,temp);
    }
};
