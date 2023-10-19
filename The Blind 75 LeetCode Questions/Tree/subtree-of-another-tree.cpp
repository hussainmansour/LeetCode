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

    bool dfs(TreeNode* root,TreeNode* subroot){
        if(root == nullptr && subroot == nullptr){
            return true;
        }
        else if(root == nullptr || subroot == nullptr){
            return false;
        }
        if(root->val != subroot->val)
            return false;
        return dfs(root->left,subroot->left) && dfs(root->right,subroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       stack<TreeNode*> st;
       st.push(root);
       while(!st.empty()){
           if(dfs(st.top(),subRoot))
                return true;
            TreeNode* temp = st.top();
            st.pop();
            if(temp->left != nullptr)
                st.push(temp->left);
            if(temp->right != nullptr)
                st.push(temp->right);
       }
        return false;
    }
};
