#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, vector<string>> info;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    for (auto v : clothes) {
        info[v[1]].push_back(v[0]);
    }
    
    int total = 1;
    for (auto d : info) {
        total *= d.second.size()+1;
    }
    
    answer = total - 1;
    return answer;
}