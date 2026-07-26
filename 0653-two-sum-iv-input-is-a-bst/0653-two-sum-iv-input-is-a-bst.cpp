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
    bool dfs(TreeNode* root, int k, unordered_set<int>& visited) {

        if (root == NULL)
            return false;

        if (visited.count(k - root->val))
            return true;
        visited.insert(root->val);

        return dfs(root->left, k, visited) || dfs(root->right, k, visited);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> visited;

        return dfs(root, k, visited);
    }
};