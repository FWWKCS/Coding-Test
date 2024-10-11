#include <iostream>
#include <vector>
using namespace std;
int age;
vector <int> v;
int main(){
    while(1){
        cin >> age;
        if(!age) return 0;
        vector <int> v(2*age);
        int leaves = 1;
        for(int i = 0; i < 2 * age; i++) cin >> v[i];
        for(int i = 0; i < age; i++) {
            int splitingFactor = v[i*2];
            int cut = v[i*2+1];
            leaves = leaves * splitingFactor - cut;
        }
        cout << leaves << '\n';
    }
}