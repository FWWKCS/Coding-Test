#include <bits/stdc++.h>
using namespace std;

struct question {
    int score, num;
};

bool compare(const question& a, const question& b) {
    return a.score > b.score;
}

int main(void) {

    vector<question> lst(8); 
    for (int i = 1; i <= 8; i++) {
        cin >> lst[i-1].score;
        lst[i-1].num = i;
    }

    sort(lst.begin(), lst.end(), compare);

    int sum = 0;
    vector<int> number(5);
    for (int i = 0; i < 5; i++) {
        sum += lst[i].score;
        number[i] = lst[i].num;
    }
    cout << sum << '\n';

    sort(number.begin(), number.end());
    for (int i = 0; i < 5; i++) cout << number[i] << ' ';
}