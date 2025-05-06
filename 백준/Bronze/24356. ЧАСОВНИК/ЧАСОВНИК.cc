#include <iostream>
using namespace std;

int main() {
    int t1, m1, t2, m2;
    cin >> t1 >> m1 >> t2 >> m2;

    if ((t1 > t2) || (t1 == t2 && m1 > m2)) t2 += 24;
    
    int start = t1*60 + m1, end = t2*60 + m2;
    cout << end-start << ' ' << (end-start)/30;
}