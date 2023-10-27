#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double arr[2];
    cin >> arr[0];
    cin >> arr[1];
    double result = arr[0] / arr[1];
    cout << fixed << setprecision(12) << result << endl;
}