void createSpace(char* x, int n)
{
    for(int i = 0; i < n; i++)
    {
        int l = strlen(x);
        for(int j = l - 1; j >= 0; j--)
            x[j+1] = x[j];
        x[l+1]='\0';
    }

}

char* reverseWords(char* s) {
    char *result = malloc(sizeof(char) * 10000);
    result[0]='\0';
    char *p = strtok(s, " ");
    int count = 0;
    while(p != NULL)
    {
        count += strlen(p);
        count++;
        createSpace(result, strlen(p) + 1);
        int i;
        for(i = 1; i <= strlen(p); i++)
            result[i] = p[i-1];
        result[0] = ' ';
        p = strtok(NULL, " ");
    }
    strcpy(result, result+1);
    result[count-1] = '\0';
    return result;
}