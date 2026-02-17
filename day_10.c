Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int start = 0;
    int end = strlen(s) - 1;
    int flag = 1;   // assume palindrome

    while(start < end) {
        if(s[start] != s[end]) {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    if(flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}

