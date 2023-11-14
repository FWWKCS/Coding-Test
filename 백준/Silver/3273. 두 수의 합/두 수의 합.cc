#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int>arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    // 정렬
    sort(arr.begin(), arr.end());

    int x;
    cin >> x;

    int count = 0, start = 0, end = N-1;
    while (start < end) {
        if (arr[start]+arr[end] < x) start++;
        else if (arr[start]+arr[end] > x) end--;
        else {
            count++;
            end--;
        }
    }

    cout << count;
}