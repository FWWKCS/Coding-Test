#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<char> st;
    for (auto c : s) {
        if (c == '(') st.push_back(c);
        else {
            if (st.empty() || st.back() != '(') {
                answer = false;
                break;
            }
            else st.pop_back();
        }
    }
    
    if (st.size() != 0) answer = false;

    return answer;
}