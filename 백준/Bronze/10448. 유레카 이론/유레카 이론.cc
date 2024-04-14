#include <iostream>
#include <vector>
using namespace std;

bool checkSum(vector<int>& tri, int target) {
    for (int a = 1; a < tri.size(); a++) {
        for (int b = 1; b < tri.size(); b++) {
            for (int c = 1; c < tri.size(); c++) {
                if (tri[a] + tri[b] + tri[c] == target) return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> tri(1, 0);
    int it = 1;
    while (tri.back() <= 1000) {
        tri.push_back(it*(it+1)/2);
        it++;
    }

    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (checkSum(tri, x)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}