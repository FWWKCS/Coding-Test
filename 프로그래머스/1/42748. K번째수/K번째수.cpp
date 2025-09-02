#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto v: commands) {
        int i = v[0]-1, j = v[1]-1, k = v[2]-1;
        vector<int> tmp;
        for (; i <= j; i++) {
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k]);
    }
    return answer;
}