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
 struct NodeInfo {
    int col;
    int row;
    int val;
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root==NULL)return {};

        vector<NodeInfo>nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            TreeNode*  node=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;

            nodes.push_back({col,row,node->val});

            if(node->left!=NULL){
                  q.push({node->left,{row+1,col-1}});
            }
            if(node->right!=NULL){
                  q.push({node->right,{row+1,col+1}});
            }
        }

        sort(nodes.begin(),nodes.end(),[](const NodeInfo&a, const NodeInfo &b){
            if(a.col!=b.col)return a.col<b.col;
            if(a.row!=b.row)return a.row<b.row;
            return a.val<b.val;
        });
        vector<vector<int>> ans;

        for(int i=0;i<nodes.size();i++){
            if(i==0 || nodes[i].col != nodes[i-1].col){
                    ans.push_back({nodes[i].val});
            }else{
                ans.back().push_back(nodes[i].val);
            }
        }

        return ans;
    }
};