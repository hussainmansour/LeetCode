class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        vector<vector<int>>buckets(n+1);
        for(auto it=map.begin();it!=map.end();it++)
        {
            buckets[it->second].push_back(it->first);
        }
       vector<int>sorted;
        for(int i=0;i<=n;i++)
        {
            sorted.insert(sorted.end(),buckets[i].begin(),buckets[i].end());
        }
        vector<int>ans(sorted.rbegin(),sorted.rbegin()+k);
        return ans;
        
    }
};
