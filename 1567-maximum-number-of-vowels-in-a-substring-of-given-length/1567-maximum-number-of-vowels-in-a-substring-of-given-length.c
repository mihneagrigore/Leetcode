int maxVowels(char* s, int k) {

    int vowels = 0;
    for(int i = 0; i < k; i++)
        if(strchr("aeiou", s[i]))
            vowels++;

    int max_vowels = vowels;
    for(int i = 0, j = k-1; j < strlen(s) - 1; i++, j++)
    {
        if(strchr("aeiou", s[i]))
            vowels--;
        if(strchr("aeiou", s[j+1]))
            vowels++;
        
        if(max_vowels < vowels)
            max_vowels = vowels;
    }

    return max_vowels;
}