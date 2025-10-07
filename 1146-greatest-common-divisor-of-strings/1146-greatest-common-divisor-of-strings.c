char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char *concat1 = malloc(len1 + len2 + 1);
    char *concat2 = malloc(len1 + len2 + 1);
    strcpy(concat1, str1);
    strcat(concat1, str2);
    strcpy(concat2, str2);
    strcat(concat2, str1);
    if (strcmp(concat1, concat2) != 0) {
        free(concat1);
        free(concat2);
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }
    free(concat1);
    free(concat2);

    int a = len1, b = len2;
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    int gcd_len = a;

    char *res = malloc(gcd_len + 1);
    strncpy(res, str1, gcd_len);
    res[gcd_len] = '\0';
    return res;
}