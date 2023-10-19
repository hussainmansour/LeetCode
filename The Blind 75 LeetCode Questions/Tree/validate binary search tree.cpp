/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans,t;
    void dfs(TreeNode* root){
        if(root == nullptr)return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);     
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        t=ans;
        sort(t.begin(),t.end());
         for(int i=0;i<ans.size();i++){
             if(ans[i]!=t[i] || (i!=0 && t[i] == t[i-1]))return false;
         }
         return true;   
    }
};
