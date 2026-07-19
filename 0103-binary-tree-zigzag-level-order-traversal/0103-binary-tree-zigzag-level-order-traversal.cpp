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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       if(root==NULL) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        bool leftToright=true;

        while(!q.empty()){
            int size=q.size();
            vector<int>res(size);

            for(int i=0;i<size;i++){
                TreeNode * node=q.front();
                q.pop();

                int idx=leftToright?i:(size-1-i);
                res[idx]=node->val;

                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            leftToright=!leftToright;
            ans.push_back(res);
        }
    return ans;
    }
};