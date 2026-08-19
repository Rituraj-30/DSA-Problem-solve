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
    vector<int> result;
    TreeNode* prev = nullptr;
    int count = 0;
    int maxCount = 0;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);   // pehle left subtree

        // ---- current node process ----
        if (prev != nullptr && prev->val == node->val) {
            count++;              // same value continue ho rahi hai
        } else {
            count = 1;             // naya value shuru hui
        }

        if (count > maxCount) {
            maxCount = count;
            result.clear();        // naya max mila, purana result hata do
            result.push_back(node->val);
        } else if (count == maxCount) {
            result.push_back(node->val);  // ye bhi mode hai
        }

        prev = node;   // current node ko prev bana do
        // --------------------------------

        inorder(node->right);   // fir right subtree
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
        
    }
};