#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <queue>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N;
    long double W; 
    cin >> N >> W;

    vector<int> tree(N+1, 0);
    for (int i = 0; i < N-1; i++) {
        int U, V; cin >> U >> V;
        
        tree[U]++;
        tree[V]++;
    }

    long double count = 0;
    for (int i = 2; i <= N; i++) {
        if (tree[i] == 1) count++;
    }
    
    cout << fixed << setprecision(10) << W/count;
}