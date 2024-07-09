#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string L;
    for (int i = 0; i < N; i++) {
        list<char> lst(1, '\0');
        list<char>::iterator cur = lst.begin();
        cin >> L;
        for (int k = 0; k < L.length(); k++) {
            // 입력에 대한 커서는 항상 문자의 바로 오른쪽에 있다고 정의
            if (L[k] == '>') {
                if (cur != prev(lst.end(), 1)) cur++;
                else continue;
            }
            else if (L[k] == '<') {
                if (cur != lst.begin()) cur--;
                else continue;
            }
            else if (L[k] == '-') {
                if (cur != lst.begin()) {
                    cur = lst.erase(cur);
                    cur--;
                }
                else continue;
            }    
            else {
                if (cur == prev(lst.end(), 1)) {
                    lst.push_back(L[k]);
                    cur++;
                }
                else {
                    cur++;
                    cur = lst.insert(cur++, L[k]);
                }
            }
        }

        cur = next(lst.begin(), 1);
        while (cur != lst.end()) {
            cout << *cur;
            cur++;
        }

        cout << '\n';
    }
}