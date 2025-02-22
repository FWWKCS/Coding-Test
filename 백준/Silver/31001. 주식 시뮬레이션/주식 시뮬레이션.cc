#include <iostream>
#include <vector>
#include <map>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

ll N, M, Q; 
map<int, vector<string>> group;
map<string, ll> company;
map<string, ll> my;

int main() {
    FASTIO;

    cin >> N >> M >> Q;
    ll G, P;
    string H;
    while (N--) {
        cin >> G >> H >> P;
        if (group.find(G) == group.end()) {
            group[G] = {};
        }

        group[G].push_back(H);

        company[H] = P;
        my[H] = 0;
    }

    int mode;
    string A;
    ll B, C, D, E;
    while (Q--) {
        cin >> mode;
        switch (mode) {
            case 1: { // A의 주식을 B주 구매
                cin >> A >> B; 
                if (company[A]*B <= M) {
                    M -= company[A]*B; 
                    my[A] += B;
                }

                break;
            }   
            case 2: { // A의 주식을 B주 판매
                cin >> A >> B;
                if (my[A] == 0) continue;

                if (B >= my[A]) { // 전부 매각
                    M += company[A] * my[A];
                    my[A] = 0;
                }
                else { // 부분 매각
                    M += company[A] * B;
                    my[A] -= B;
                }

                break;
            }
            case 3: { // A의 주가 C원 증가
                cin >> A >> C;
                company[A] = max(ll(0), company[A] + C);

                break;
            }
            case 4: { // D 그룹 회사의 주가 C원 증가
                cin >> D >> C;
                for (auto c : group[D]) {
                    company[c] = max(ll(0), company[c] + C);
                }

                break;
            }
            case 5: { // D 그룹 회사의 주가 E% 증가
                cin >> D >> E;
                for (auto c : group[D]) {
                    company[c] = company[c] * (100+E) / 100;
                    // 일의 자리 버림
                    company[c] -= company[c] % 10;
                }
                break;
            }
            case 6: { // 현재 소지금
                cout << M << '\n';
                break;
            }
            case 7: { // 보유하고 있는 모든 주식 매각 시 총액
                ll selled = 0;
                for (auto v : my) {
                    string c = v.first;
                    int w = v.second;

                    selled += company[c] * w;
                }

                cout << M + selled << '\n';
                break;
            }
        }
    }
}