/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sum(struct TreeNode* root, int current_sum) {
    if (root == NULL) {
        return 0;
    }

    current_sum = current_sum * 10 + root->val;

    if (root->left == NULL && root->right == NULL) {
        return current_sum;
    }

    return sum(root->left, current_sum) + sum(root->right, current_sum);
}

int sumNumbers(struct TreeNode* root) {
    return sum(root, 0);
}

