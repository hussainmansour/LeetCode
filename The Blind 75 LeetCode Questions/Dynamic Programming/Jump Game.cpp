
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curPossible=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i<=curPossible && nums[i]+i>curPossible)
                curPossible = nums[i]+i;
        }

        return (curPossible >= n-1);        
    }
};
