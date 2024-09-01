#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = 0;
    long long accumulate = (count+1)*count/2;
    if (money < price * accumulate) answer = (price*accumulate)-money;
    else answer = 0;
    return answer;
}