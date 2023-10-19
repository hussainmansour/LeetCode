class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i] = ans[i/2];
            if(i%2==1)
                ans[i]++;
        }
        return ans;
    }
};
