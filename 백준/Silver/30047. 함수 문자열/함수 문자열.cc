#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string S;
stack<int> st;

int main() {
    FASTIO;
    
    cin >> S;
    reverse(S.begin(), S.end());

    for (char c : S) {
        if (c == 'x') {
            st.push(0);
        }

        else if (c == 'g') {
            if (st.empty()) {
                cout << -1;
                return 0;
            }

            int s = st.top();
            st.pop();
            st.push(s+1);
        }

        else if (c == 'f') {
            if (st.size() < 2) {
                cout << -1;
                return 0;
            }

            int s = st.top();
            st.pop();

            int t = st.top();
            st.pop();

            st.push(min(s, t));
        }
    }

    if (st.size() != 1) cout << -1;
    else cout << st.top();
}