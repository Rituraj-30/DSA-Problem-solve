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

     TreeNode* findMIN( TreeNode* node){
        while(node->left!=NULL){
            node=node->left;
        }

        return node;
     }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL)return NULL;

        if(key<root->val){
                root->left=deleteNode(root->left,key);
        }else if(key>root->val){
                root->right=deleteNode(root->right,key);
        }
        else {


            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp; // Right child parent ke sath attach ho jayega
            } 
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp; // Left child parent ke sath attach ho jayega
            }

            TreeNode* temp=findMIN(root->right);
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);

        }
        return root;
    }
};