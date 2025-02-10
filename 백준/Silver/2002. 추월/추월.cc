#include <iostream>
#include <map>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int result[1001];

int main() {
    FASTIO;

    int N; cin >> N;
    map<string, int> in;

    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        in[s] = i;
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        result[i] = in[s];
    }

    for (int i = 0; i <= N-1; i++) {
        for (int j = i+1; j <= N; j++) {
            if (result[i] > result[j]) {
                answer++;
                break;
            }
        }
    }

    cout << answer;
}