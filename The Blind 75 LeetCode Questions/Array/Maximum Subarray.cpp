class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<0){
                sum = 0;
                continue;
            }
            sum+=nums[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};
