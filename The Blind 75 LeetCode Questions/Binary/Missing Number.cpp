class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> vis(nums.size()+1, -1);
        for(int i=0;i<nums.size();i++){
            vis[nums[i]] = 1;
        }
        int ind =0;
        for(int i =0;i<vis.size();i++){
            if(vis[i] == -1)
                {
                    ind = i;
                    break;
                }
        }
        return ind;
    }
};
