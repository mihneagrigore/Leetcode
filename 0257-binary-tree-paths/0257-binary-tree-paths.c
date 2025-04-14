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


void dfs(struct TreeNode* root, char* path, char*** ans, int* ans_size)
{
    if (!root) {
        return;
    }
    
    char val_str[20];
    sprintf(val_str, "%d", root->val);
    
    int path_len = strlen(path);
    if (path_len > 0) {
        strcat(path, "->");
    }
    strcat(path, val_str);
    
    if (!root->left && !root->right) {
        (*ans_size)++;
        *ans = realloc(*ans, (*ans_size) * sizeof(char*));
        (*ans)[*ans_size - 1] = strdup(path);
    } else {
        dfs(root->left, path, ans, ans_size);
        dfs(root->right, path, ans, ans_size);
    }
    
    path[path_len] = '\0';
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    char** ans = NULL;
    char path[1000] = "";
    
    dfs(root, path, &ans, returnSize);
    
    return ans;
}