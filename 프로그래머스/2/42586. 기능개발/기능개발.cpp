#include <string>
#include <vector>

using namespace std;

void accumulate(vector<int>& progresses, vector<int>& speeds) {
    for (int i = 0; i < progresses.size(); ++i) {
        progresses[i] = min(progresses[i] + speeds[i], 100);
    }
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    while (idx < progresses.size()) {
        int total = 0;
        while (progresses[idx] == 100) {
            total++;
            idx++;
        }
        if (total > 0) answer.push_back(total);
        accumulate(progresses, speeds);
    }
    return answer;
}