#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> array(9);
    int sum = 0;
    int n;

    for (int i = 0; i < 9; i++) {
        cin >> n;
        array[i] = n;
        sum += n;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - array[i] - array[j] == 100) {
                array.erase(array.begin()+i);
                array.erase(array.begin()+j-1);
                
                i += 9;
                break;
            }
        }
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < 7; i++) {
        cout << array[i] << '\n';
    }
}