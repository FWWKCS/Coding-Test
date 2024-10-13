#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        string a, b; cin >> a >> b;
        if (a == "0" && b == "0") return 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int lA = a.length(), lB = b.length();

        if (lA > lB) {
            // b 채우기
            for (int i = 0; i < lA-lB; i++) b += '0';
        }
        else if (lA < lB) {
            // a 채우기
            for (int i = 0; i < lB-lA; i++) a += '0';
        }

        int count = 0;
        int carry = 0;
        for (int i = 0; i < a.length(); i++) {
            if ((a[i]-'0')+(b[i]-'0')+carry >= 10) {
                count++;
                carry = 1;
            }
            else carry = 0;
        }

        cout << count << '\n';
    }
}