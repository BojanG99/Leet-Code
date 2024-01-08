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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root == nullptr) return 0;

        stack<TreeNode*> my_stack;
        int sum = 0;

        my_stack.push(root);

        while (my_stack.empty() == false) {

            TreeNode* tmp_node = my_stack.top();
            my_stack.pop();

            if (tmp_node->left && tmp_node->val >= low) {
                my_stack.push(tmp_node->left);
            }

            if (tmp_node->right && tmp_node->val <= high) {
                my_stack.push(tmp_node->right);
            }

            if (tmp_node->val >=low && tmp_node->val <= high) {
                sum += tmp_node->val;
            }

        }

        return sum;
    //    return inorder_traverse(root, low, high); //recursive
    }

    //recursive
    int inorder_traverse(TreeNode* root, int low, int high){

        if (root == nullptr) return 0;

        int sum = 0;

        if (root->val >= low) sum += inorder_traverse(root->left, low, high);

        if (root->val >=low && root->val <=high) sum += root->val;

        if (root->val <= high) sum += inorder_traverse(root->right, low, high);

        return sum;

    }

};