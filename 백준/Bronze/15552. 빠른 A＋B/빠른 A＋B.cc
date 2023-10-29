#include <stdio.h>

int main() {
    int testcase, a, b;
    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
}