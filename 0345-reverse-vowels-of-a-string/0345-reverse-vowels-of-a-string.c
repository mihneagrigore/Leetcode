char* reverseVowels(char* s) {
    
    int i = 0, j = strlen(s) - 1;

    while(i < j)
    {
        while(!strchr("AEIOUaeiou", s[i]))
        {
            if(i >= j)
                goto EXIT;
            i++;
        }
        while(!strchr("AEIOUaeiou", s[j]))
        {
            if(i >= j)
                goto EXIT;
            j--;
        }
        char aux = s[i];
        s[i] = s[j];
        s[j] = aux;
        i++;
        j--;
    }

EXIT:
    return s;
}