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
    void helper(TreeNode* root,int level,vector<int> &ans){
        if(root==NULL)return ;


        if(level==ans.size()){
            ans.push_back(root->val);
        }

        helper(root->right,level+1,ans);
        helper(root->left,level+1,ans);

    }
    vector<int> rightSideView(TreeNode* root) {

        // vector<int> ans;
        //  helper(root,0,ans);
        // return ans;

        vector<int> ans;

        if (root == NULL)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode* currNode=q.front();
                q.pop();

                if(i==size-1){
                    ans.push_back(currNode->val);
                }
                if(currNode->left!=NULL){
                    q.push(currNode->left);
                }
                if(currNode->right!=NULL){
                    q.push(currNode->right);
                }

            }
        }
        return ans;
    }
};