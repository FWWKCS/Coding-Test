#include <iostream>
using namespace std;

int main() {
    int score[81] = {0, };
    int s1, s2, s3; cin >> s1 >> s2 >> s3;
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                score[i+j+k]++;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= 80; i++) {
        if (score[answer] < score[i]) {
            answer = i;
        } 
    } 

    cout << answer;
}