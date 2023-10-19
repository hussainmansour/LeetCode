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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        if(preorder.empty() or inorder.empty())
        {
            return NULL;
        }
        TreeNode* root =new TreeNode(preorder[0]);
        int mid = 0;
        for(mid=0;mid<inorder.size();mid++)
        {
            if(preorder[0]==inorder[mid])break;
        }
        vector<int>pre,in;
        pre.insert(pre.begin(),preorder.begin()+1,preorder.begin()+mid+1);
        in.insert(in.begin(),inorder.begin(),inorder.begin()+mid);
        root -> left = buildTree(pre,in);
        pre.clear();
        in.clear();
        pre.insert(pre.begin(),preorder.begin()+mid+1,preorder.end());
        in.insert(in.begin(),inorder.begin()+mid+1,inorder.end());
        root -> right = buildTree(pre,in);
        return root;
    }
};
