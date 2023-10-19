class Solution {
public:
    set<string> st;
    int dp[350];
    bool solve(int k,string& s){
        string temp;
        bool op1 = true;
        if(k==s.size())return true;
        if(dp[k]!=-1)return dp[k];
        for(int i=k; i<s.size();i++){
            temp += s[i];
            if(st.count(temp) != 0){
                op1 = solve(i+1,s);// aaa aaaa 
                if(op1)
                    return dp[k] = 1;
            }
        }
        if(st.count(temp)==0)
            return dp[k] = 0;
        return dp[k] = op1;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict)
            st.insert(i);
        memset(dp,-1,sizeof dp);
        return solve(0,s);   
    }
    
};
