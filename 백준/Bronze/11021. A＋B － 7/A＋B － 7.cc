#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    int AB[T][2];
    for(int i=0;i<T;i++){
        cin >> AB[i][0];
        cin >> AB[i][1];
    }
    for (int i=0;i<T;i++){
        cout << "Case #" << i+1 << ": " << AB[i][0]+AB[i][1] << endl;
    }
}