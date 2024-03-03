#include <bits/stdc++.h>
using namespace std;

int main() {
    int month, day;
    cin >> month >> day;

    if (month < 2) cout << "Before";
    else if (month == 2 && day < 17) cout << "Before";
    else if (month == 2 && day > 18) cout << "After";
    else if (month > 2) cout << "After";
    else cout << "Special"; 
}