class Solution {
public:
    int characterReplacement(string s, int k) {
       char c = 'A';
       int ans = 0;
       while(c<='Z')
       {
           int i=0,j=0,t=k;
           while(i<s.size()&&j<s.size())
           {
               if(s[j]==c)j++;
               else if(s[j]!=c && t != 0)t--,j++;
               else{
                   if(s[i]!=c)
                        t++;
                    i++;
               }
               ans = max(ans,j-i);
           }
           c++;
       }
       return ans; 
    }
};
