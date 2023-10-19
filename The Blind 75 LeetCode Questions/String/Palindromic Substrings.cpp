class Solution {
public:
    int check_odd(int i,string& s)
    {
        int j = i+1;
        int k = i-1;
        int ans = 1;
        while(j<s.size() && k>=0 && s[j]==s[k]){
            ans++;
            j++;
            k--;
        }
        return ans;
    }
    int check_even(int i,string& s)
    {
        int j = i+1;
        int k = i;
        int ans=0;
        while(j<s.size()&&k>=0&&s[j]==s[k])
        {
            ans++;
            j++;
            k--;
        }
        return ans;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
            int x1 = check_odd(i,s);
            int x2 = check_even(i,s);
            ans+=x1+x2;
        }
        return ans;
    }
};
