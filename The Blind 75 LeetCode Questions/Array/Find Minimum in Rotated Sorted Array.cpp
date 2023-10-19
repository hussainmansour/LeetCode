class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid,ans=INT_MAX,n=nums.size();
        ans = min(ans,nums[l]);
        while(l<r){
            mid = l+(r-l)/2;
            if(nums[l]<nums[mid])
                ans = min(ans,nums[l]),l = mid+1;
            else
                ans = min(ans,nums[mid]),r= mid;
        }
        ans = min(ans,nums[l]);
        ans = min(ans,nums[max(l-1,0)]);
        ans = min(ans,nums[min(l+1,n-1)]);
        return ans;
    }
};
