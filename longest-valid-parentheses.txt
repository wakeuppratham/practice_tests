#include<stdio.h>

int longestValidParentheses(char* s) {
    int stack[100000];
    int top = -1;
    int count = 0;

    stack[++top] = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                count = i - stack[top] > count ? i - stack[top] : count;
            }
        }
    }

    return count;
}

int main() {
    char arr[100];
    fgets(arr, sizeof(arr), stdin);

    int ans = longestValidParentheses(arr);
    printf("%d", ans);

    return 0;
}
