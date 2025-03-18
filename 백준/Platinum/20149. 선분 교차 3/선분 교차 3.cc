#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;

vector<pair<ll, ll>> L1, L2;
pair<ll, ll> A, B, C, D;

void intersection() {
    ld det, px, py;
    det = (A.x-B.x)*(C.y-D.y) - (A.y-B.y)*(C.x-D.x);
    px = ((A.x*B.y - A.y*B.x) * (C.x-D.x) - (A.x-B.x) * (C.x*D.y - C.y*D.x)) / det;
    py = ((A.x*B.y - A.y*B.x) * (C.y-D.y) - (A.y-B.y) * (C.x*D.y - C.y*D.x)) / det;
    
    if (det == 0) { // 평행
        if (B < C || D < A) cout << 0;
        else {
            cout << 1 << '\n';
            if (B == C) cout << B.x << ' ' << B.y;
            else if (A == D) cout << A.x << ' ' << A.y;
        }
    }
    else {
        cout << 1 << '\n';
        cout << px << ' ' << py;
    }
}

int CCW(pair<ll, ll> X, pair<ll, ll> Y, pair<ll, ll> Z) {
    ll ux = Y.x-X.x, uy = Y.y-X.y;
    ll vx = Z.x-X.x, vy = Z.y-X.y;
    
    ll result = (ux*vy)-(uy*vx);
    if (result < 0) return -1;
    else if (result > 0) return 1;
    else return 0;
}

int main() {
    cout << fixed << setprecision(9);

    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    A = {x1, y1};
    B = {x2, y2};
    C = {x3, y3};
    D = {x4, y4};

    L1 = {A, B};
    sort(L1.begin(), L1.end());
    A = L1[0], B = L1[1];

    L2 = {C, D};
    sort(L2.begin(), L2.end());
    C = L2[0], D = L2[1];

    int c1 = CCW(A, B, C);
    int c2 = CCW(A, B, D);
    int c3 = CCW(C, D, A);
    int c4 = CCW(C, D, B);

    if (c1*c2 <= 0 && c3*c4 <= 0) intersection();
    else cout << 0;
}