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
    // bool helper(TreeNode* t1,TreeNode* t2){
    //     if(t1==NULL && t2==NULL)return true;

    //     if(t1==NULL || t2==NULL)return false;

    //     return (t1->val==t2->val)&& 
    //     helper(t1->left,t2->right)
    //      && helper(t1->right,t2->left);

    // }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        // return helper(root->left,root->right);

        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root->left,root->right});

        while(!q.empty()){
            auto [t1,t2]=q.front();
            q.pop();

            if(t1==NULL && t2==NULL)continue;
            if(t1==NULL || t2==NULL || t1->val  !=t2->val ){
                return false;
            }

            q.push({t1->left,t2->right});
            q.push({t1->right,t2->left});
        }
        return true;
    }
};