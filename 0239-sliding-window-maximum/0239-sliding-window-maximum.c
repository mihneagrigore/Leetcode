typedef struct TreapNode {
    int key, priority;
    struct TreapNode *left, *right;
} TreapNode;

TreapNode* newNode(int key) {
    TreapNode* node = (TreapNode*)malloc(sizeof(TreapNode));
    node->key = key;
    node->priority = rand();
    node->left = node->right = NULL;
    return node;
}

TreapNode* rotateRight(TreapNode* y) {
    TreapNode* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

TreapNode* rotateLeft(TreapNode* x) {
    TreapNode* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

TreapNode* insert(TreapNode* root, int key) {
    if (!root) return newNode(key);

    if (key <= root->key) {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority)
            root = rotateRight(root);
    } else {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority)
            root = rotateLeft(root);
    }
    return root;
}

TreapNode* deleteNode(TreapNode* root, int key) {
    if (!root) return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            TreapNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            TreapNode* temp = root->left;
            free(root);
            return temp;
        } else if (root->left->priority > root->right->priority) {
            root = rotateRight(root);
            root->right = deleteNode(root->right, key);
        } else {
            root = rotateLeft(root);
            root->left = deleteNode(root->left, key);
        }
    }
    return root;
}

int findMax(TreapNode* root) {
    while (root->right)
        root = root->right;
    return root->key;
}

void freeTreap(TreapNode* root) {
    if (!root) return;
    freeTreap(root->left);
    freeTreap(root->right);
    free(root);
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    TreapNode* root = NULL;
    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));

    for (int i = 0; i < k; i++)
        root = insert(root, nums[i]);
    result[0] = findMax(root);

    for (int i = k; i < numsSize; i++) {
        root = deleteNode(root, nums[i - k]);
        root = insert(root, nums[i]);
        result[i - k + 1] = findMax(root);
    }

    freeTreap(root);
    *returnSize = numsSize - k + 1;
    return result;
}