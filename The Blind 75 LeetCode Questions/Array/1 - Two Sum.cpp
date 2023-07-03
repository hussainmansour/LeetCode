class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }
        int ans1=0,ans2=0,ind1=0,ind2=0;
        for (int i = 0; i < nums.size(); ++i) {
             ans1 = nums[i];
             ind1 = i;
             ans2 = target - ans1;
             if(mp[ans2] > 1 || (mp[ans2] == 1 && ans1 != ans2))
                 break;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == ans2 && i != ind1) {
                ind2 = i;
                break;
            }
        }
        return {ind1,ind2};
    }
};

