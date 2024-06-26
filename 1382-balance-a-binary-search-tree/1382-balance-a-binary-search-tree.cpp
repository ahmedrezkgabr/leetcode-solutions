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
    // function to perform in-order traversal and store the node values in a vector
    void inOrderTraversal(TreeNode* root, vector<int>& nodes) 
    {
        if (root == nullptr) return;
        inOrderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inOrderTraversal(root->right, nodes);
    }

    // function to build a balanced BST from sorted node values
    TreeNode* buildBalancedBST(vector<int>& nodes, int start, int end) 
    {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = buildBalancedBST(nodes, start, mid - 1);
        node->right = buildBalancedBST(nodes, mid + 1, end);
        return node;
    }

    
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> nodes;
        inOrderTraversal(root, nodes); // get the node values in sorted order
        return buildBalancedBST(nodes, 0, nodes.size() - 1); // build and return the balanced BST
    }
};