class Solution {
public: 
    string longestPalindrome(string s) {
        string ans;
        int n=s.size();
        // check the odd palindrome
        for(int k=0;k<n;k++){
            int i=k-1,j=k+1;
            string t;
            t+=s[k];
            while(i>=0 && j<n){
                if(s[i]!=s[j])
                    break;
                t+=s[j];
                t = s[i]+t;
                i--;j++;
            }
            if(t.size()>ans.size())
                ans =t;
        }
        // check the even palindrome
        for(int k=0;k<n;k++){
            int i=k,j=k+1;
            string t;
            while(i>=0 && j<n){
                if(s[i]!=s[j])
                    break;
                t+=s[j];
                t = s[i]+t;
                i--;j++;
            }
            if(t.size()>ans.size())
                ans =t;
        }




        return ans;
    }
};
