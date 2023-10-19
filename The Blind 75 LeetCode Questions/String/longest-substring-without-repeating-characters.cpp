class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int ans = 0;
        int i=0,j=0;
        while(i<s.size()){
            if(mp[s[i]]==0){
                mp[s[i]]++;
            }
            else{
                ans = max(ans,(int)mp.size());
                while(s[i]!=s[j]){
                    mp.erase(s[j]);
                    j++;
                }
                j++;
            }
            i++;
        }
        return max(ans,(int)mp.size());
    }
};
