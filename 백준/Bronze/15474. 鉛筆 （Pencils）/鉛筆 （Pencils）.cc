#include <iostream>
using namespace std;

int main() {
    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;

    int X, Y;
    if (N % A == 0) X = B * (N / A);
    else X = B * ((N / A)+1);

    if (N % C == 0) Y = D * (N / C);
    else Y = D * ((N / C) + 1); 

    cout << (X < Y ? X : Y);
}