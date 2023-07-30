class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prefix[nums.size()],suffix[nums.size()];
        vector<int> ans(nums.size());
        long long temp=1;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for (int i = nums.size()-1; i >=0 ;--i) {
            suffix[i] = temp;
            temp *= nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};

