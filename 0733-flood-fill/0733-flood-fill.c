void dfs(int** image, int imageSize, int* imageColSize, int i, int j, int* seen, int startColor, int newColor) {
    if (i < 0 || i >= imageSize || j < 0 || j >= imageColSize[i])
        return;
    
    if (image[i][j] != startColor || seen[i * imageColSize[0] + j] == 1)
        return;

    seen[i * imageColSize[0] + j] = 1;

    image[i][j] = newColor;

    dfs(image, imageSize, imageColSize, i + 1, j, seen, startColor, newColor);
    dfs(image, imageSize, imageColSize, i - 1, j, seen, startColor, newColor);
    dfs(image, imageSize, imageColSize, i, j + 1, seen, startColor, newColor);
    dfs(image, imageSize, imageColSize, i, j - 1, seen, startColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int startColor = image[sr][sc];

    if (startColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    int** result = (int**)malloc(sizeof(int*) * imageSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);

    int* seen = (int*)calloc(imageSize * imageColSize[0], sizeof(int));

    dfs(image, imageSize, imageColSize, sr, sc, seen, startColor, color);

    for (int i = 0; i < imageSize; i++) {
        result[i] = (int*)malloc(sizeof(int) * imageColSize[i]);
        for (int j = 0; j < imageColSize[i]; j++) {
            result[i][j] = image[i][j];
        }
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    *returnSize = imageSize;

    free(seen);

    return result;
}