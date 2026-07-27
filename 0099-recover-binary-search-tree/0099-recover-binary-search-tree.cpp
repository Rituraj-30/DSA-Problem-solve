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
    TreeNode *frist=NULL;
    TreeNode *last=NULL;
    TreeNode *prev=NULL;
    TreeNode *middle=NULL;
    
    void inOrder( TreeNode *root){
        if(root==NULL)return ;

        inOrder(root->left);

        if(prev!=NULL && root->val < prev->val){
            if(frist==NULL){
                frist=prev;
                middle=root;
            }else{
                    last=root;
            }
        }
        prev=root;

        inOrder(root->right);

    }
    void recoverTree(TreeNode* root) {

            inOrder(root);

            if(frist && last){
                swap(frist->val,last->val);
            }
            else if(frist && middle){
                swap(frist->val,middle->val);
            }
    }
};