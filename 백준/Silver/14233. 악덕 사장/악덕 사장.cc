#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N; 
vector<int> A;

int binSearch(int k, int idx) {
    int s = 1, e = k;
    int p; // 가능한 값 중 최대를 계속 저장
    while (s <= e) {
        int m = (s+e)/2;
        
        if (idx*m <= A[idx-1]) {
            p = m;
            s = m+1;
        } else {
            e = m-1;
        }
    }

    return p;
}

int main() {
    FASTIO;

    cin >> N;
    A.resize(N);
    for (auto &a : A) cin >> a;
    sort(A.begin(), A.end());
    
    int answer = A[0];
    for (int i = 1; i < N; i++) {
        answer = binSearch(answer, i+1);
    }

    cout << answer;
}