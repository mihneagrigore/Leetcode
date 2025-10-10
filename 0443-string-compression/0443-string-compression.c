int compress(char* chars, int charsSize) {
    int write = 0;
    int read = 0;  

    while (read < charsSize) {
        char currentChar = chars[read];
        int count = 0;

        while (read < charsSize && chars[read] == currentChar) {
            read++;
            count++;
        }

        chars[write++] = currentChar;

        if (count > 1) {
            char temp[12]; 
            int len = sprintf(temp, "%d", count);
            for (int j = 0; j < len; j++) {
                chars[write++] = temp[j];
            }
        }
    }

    return write;
}
