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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        convertBSTHelper(root, sum);
        return root;
    }
    
private:
    void convertBSTHelper(TreeNode* node, int& sum) 
    {
        if (node == nullptr) return;
        
        // traverse the right subtree first
        convertBSTHelper(node->right, sum);
        
        // update the current node
        sum += node->val;
        node->val = sum;
        
        // traverse the left subtree
        convertBSTHelper(node->left, sum);
    }
};