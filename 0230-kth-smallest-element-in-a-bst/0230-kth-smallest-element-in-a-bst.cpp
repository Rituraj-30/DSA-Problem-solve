/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int res = -1;
    void inOrder(TreeNode* root, int k){
        if(root==NULL)return ;
        
         inOrder(root->left,k);

         count++;

         if(count==k){
            res=root->val;
            return ;
         }

        if(count<k){
                 inOrder(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        
        inOrder(root,k);
        return res;
    }
};