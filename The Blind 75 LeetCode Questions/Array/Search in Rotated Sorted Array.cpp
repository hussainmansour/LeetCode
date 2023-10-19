class Solution {
public:
int search(vector<int> nums, int target) {
    int n = nums.size();
    int l=0,r=n-1,mid=0;
    while(l<r){
        mid = l+(r-l)/2;
        if(nums[l]<nums[(l+1)%n] && nums[l]<nums[(l-1+n)%n])
            break;
        if(nums[l] <= nums[mid])
            l = mid+1;
        else
            r = mid;
    }
    int ind = lower_bound(nums.begin(),nums.begin()+l,target)-nums.begin();
    if(nums[ind] == target)
        return ind;
    ind = lower_bound(nums.begin()+l,nums.end(),target)-(nums.begin()+l);
    if(ind+l <n && nums[ind+l] == target)
        return ind+l;
    return -1;
}
};
