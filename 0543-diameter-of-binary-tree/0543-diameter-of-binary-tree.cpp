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
    int height(TreeNode* root, int &maxHeight){
        if(root==NULL)return 0;

        int l=height(root->left,maxHeight);
        int r=height(root->right,maxHeight);

        maxHeight=max(maxHeight,l+r);

        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxHeight=0;
        height(root,maxHeight);
        
        return maxHeight;
    }
};