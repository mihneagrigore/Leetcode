int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    char *final_result = malloc(sizeof(char) * max(len1, len2) + 1);
    final_result[0] = '\0';

    if(len1 < len2) // use str1 to start the gcd
    {
        for(int i = 1; i <= len1; i++)
        {
            char *result = malloc(sizeof(char) * len2 + 1);
            strncpy(result, str1, i);
            result[i] = '\0';

            // cannot be gcd if is not dividing the word
            if(len1 % strlen(result) != 0)
                goto NEXT;
            if(len2 % strlen(result) != 0)
                goto NEXT;

            int j;

            // test gcd in str1
            for(j = 0; j < len1; j += strlen(result))
                if(strncmp(str1 + j, result, strlen(result)) != 0)
                    goto NEXT;

            // test gcd in str2
            for(j = 0; j < len2; j += strlen(result))
                if(strncmp(str2 + j, result, strlen(result)) != 0)
                    goto NEXT;

            strcpy(final_result, result);

            NEXT:
        }
    }

    if(len1 >= len2) // use str2 to start the gcd
    {
        for(int i = 1; i <= len2; i++)
        {
            char *result = malloc(sizeof(char) * len1 + 1);
            strncpy(result, str2, i);
            result[i] = '\0';

            // cannot be gcd if is not dividing the word
            if(len1 % strlen(result) != 0)
                goto NEXT2;
            if(len2 % strlen(result) != 0)
                goto NEXT2;

            int j;

            // test gcd in str1
            for(j = 0; j < len1; j += strlen(result))
                if(strncmp(str1 + j , result, strlen(result)) != 0)
                    goto NEXT2;

            // test gcd in str2
            for(j = 0; j < len2; j += strlen(result))
                if(strncmp(str2 + j, result, strlen(result)) != 0)
                    goto NEXT2;

            strcpy(final_result, result);

            NEXT2:
        }
    }

    return final_result;
}