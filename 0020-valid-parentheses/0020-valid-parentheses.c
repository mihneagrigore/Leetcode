bool isValid(char * s) {
    char stack[10000];
    int top = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];
        
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } else {
            if (top == -1) return 0;
            
            char topChar = stack[top--];
            if (current == ')' && topChar != '(') return 0;
            if (current == '}' && topChar != '{') return 0;
            if (current == ']' && topChar != '[') return 0;
        }
    }
    
    return top == -1;
}