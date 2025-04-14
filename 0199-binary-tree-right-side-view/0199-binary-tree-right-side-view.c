/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode* root, int level, int* result, int* returnSize)
{
    if (root == NULL)
        return;
    
    if (level == *returnSize) {
        result[*returnSize] = root->val;
        (*returnSize)++;
    }
    
    dfs(root->right, level + 1, result, returnSize);
    dfs(root->left, level + 1, result, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    dfs(root, 0, result, returnSize);
    return result;
}