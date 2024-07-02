#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    string T; cin >> T;

    map<char, double> dict;
    double x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        dict.insert({char(i+65), x});
    }

    vector<double> stack;
    for (int k = 0; k < T.length(); k++) {
        if (T[k] == '+') {
            int top = stack.size()-1;
            double x = stack[top-1], y = stack[top];
            for (int i = 0; i < 2; i++) stack.pop_back();
            stack.push_back(x + y);
        }
        else if (T[k] == '-') {
            int top = stack.size()-1;
            double x = stack[top-1], y = stack[top];
            for (int i = 0; i < 2; i++) stack.pop_back();
            stack.push_back(x - y);
        }
        else if (T[k] == '*') {
            int top = stack.size()-1;
            double x = stack[top-1], y = stack[top];
            for (int i = 0; i < 2; i++) stack.pop_back();
            stack.push_back(x * y);
        }
        else if (T[k] == '/') {
            int top = stack.size()-1;
            double x = stack[top-1], y = stack[top];
            for (int i = 0; i < 2; i++) stack.pop_back();
            stack.push_back(x / y);
        }
        else stack.push_back(dict[T[k]]);
    }

    cout << fixed << setprecision(2) << stack.back();
}