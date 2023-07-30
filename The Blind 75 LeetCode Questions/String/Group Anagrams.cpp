class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        temp = strs;
        map<string,vector<string>>mp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }
        for(int i=0;i<strs.size();i++){
            mp[strs[i]].push_back(temp[i]);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
        }
  };
