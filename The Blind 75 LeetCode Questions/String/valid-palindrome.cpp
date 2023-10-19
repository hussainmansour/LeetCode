class Solution {
public:
    bool isPalindrome(string s) {
       string t;
       for(auto i:s){
           if(isalpha(i))t.push_back(tolower(i));
           else if(isdigit(i))t.push_back(i);
       }
       int i=0,j=t.size()-1;
       while(i<j){
           if(t[i]!=t[j])return false;
           i++,j--;
       }
       return true; 
    }
};
