class Solution {
public:
    vector<vector<int>> ans;
    int solve(int ind,vector<int>& candidates, int& target,int sum,vector<int> curr){
        if(sum == target){
            ans.push_back(curr);
            return 1;
        }
        if(sum>target || ind>=candidates.size())return 0;

        int op1,op2;
        //leave
        op1 = solve(ind+1,candidates,target,sum,curr);
        //take
        curr.push_back(candidates[ind]);
        op2 = solve(ind,candidates,target,sum+candidates[ind],curr);
        return 1;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        solve(0,candidates,target,0,curr);
        return ans;
    }
};
