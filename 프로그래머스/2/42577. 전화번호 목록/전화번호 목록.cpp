#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> heads;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for (auto x : phone_book) heads.insert(x);
    
    for (auto s : phone_book) {
        string h = "";
        for (int i = 0; i < s.length()-1; i++) {
            h += s[i];
            if (heads.find(h) != heads.end()) return false;
        }
    }
    
    return answer;
}