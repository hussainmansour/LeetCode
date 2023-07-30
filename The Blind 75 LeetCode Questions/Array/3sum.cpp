
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> v;
        int sz = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<sz;i++){
            int t = -nums[i];
            int j = i+1,k = sz-1;
            while(k>i && j<sz){
                if(k<=j)
                    break;
                if(nums[j]+nums[k] == t && j != k){
                    vector<int>vec = {{-t,nums[j],nums[k]}};
                    ans.insert(vec);
                }
                if(nums[j]+nums[k]<t)
                    j++;
                else
                    k--;
            }
        }
        for(auto it: ans){
            v.push_back(it);
        }
        return v;
    }

};
