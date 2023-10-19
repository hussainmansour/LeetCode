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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<TreeNode*> q,t;
        if(root == nullptr)return ans;
        q.push_back(root);
        do{
            for(auto i : q)
            {
                if(i->left != nullptr)t.push_back(i->left);
                if(i->right != nullptr)t.push_back(i->right);
                temp.push_back(i->val);
            }
            ans.push_back(temp);
            q = t;
            t.clear();
            temp.clear();
        }while(!q.empty());
        return ans;
    }
};
