#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    deque<int> deq = {-1};
    deque<int> L, R;
    for (int i = 1; i <= 26; i++) deq.push_back(i); 

    int N; cin >> N;
    cin.ignore();
    while (N--) {
        for (int i = 0; i < 13; i++) {
            L.push_back(deq.front());
            deq.pop_front();
        }

        for (int i = 0; i < 14; i++) {
            R.push_back(deq.front());
            deq.pop_front();
        }

        string str;
        int buffer; 
        getline(cin, str);
        istringstream iss(str);
        int count = 1;
        while (iss >> buffer) {
            if (count % 2 == 1) {
                // R에서 가져오기
                while (buffer--) {
                    deq.push_back(R.front());
                    R.pop_front();
                }
            }
            else {
                // L에서 가져오기
                while (buffer--) {
                    deq.push_back(L.front());
                    L.pop_front();
                }
            }

            count++;
        }
    }

    int answer = -1;
    for (int i = 0; i < 27; i++) {
        if (deq[i] == -1) {
            answer = i+1;
            break;
        }
    }

    cout << answer;
}