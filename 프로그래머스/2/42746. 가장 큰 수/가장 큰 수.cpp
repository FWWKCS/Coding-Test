#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> num;
    for (int x : numbers) {
        num.push_back(to_string(x));
    }
    
    sort(num.begin(), num.end(), [](string a, string b) {
       return a+b > b+a; 
    });
    
    for (string s : num) answer += s;
    
    if (answer == string(answer.length(), '0')) 
        answer = '0';
    
    return answer;
}