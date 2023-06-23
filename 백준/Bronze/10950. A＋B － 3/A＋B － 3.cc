#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    int num[T][2];
    for(int i=0;i<T;i++){
        cin >> num[i][0];
        cin >> num[i][1];
    }
    for(int i=0;i<T;i++){
        cout << num[i][0]+num[i][1] << endl;
    }
}