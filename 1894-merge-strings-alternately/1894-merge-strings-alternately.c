char * mergeAlternately(char * word1, char * word2){

    char *sol = malloc(sizeof(char) * 202);
    sol[0]=='\0';
    int str1 = 0, str2 = 0, count = 0;

    while(str1 < strlen(word1) && str2 < strlen(word2))
    {
        if(count % 2 == 0) // first string
        {
            sol[str1+str2] = word1[str1];
            str1++;
        }
        else
        {
            sol[str1+str2] = word2[str2];
            str2++;        
        }
        count++;
    }

    while(str1 < strlen(word1))
    {
        sol[str1+str2] = word1[str1];
        str1++;
    }

    while(str2 < strlen(word2))
    {
        sol[str1+str2] = word2[str2];
        str2++;
    }

    sol[str1+str2] = '\0';

    return sol;
}