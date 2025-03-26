#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int n = schedules.size();
    
    for (int i = 0; i < n; i++) {
        int st = startday;
        bool pass = true;
        
        int deadline = schedules[i] + 10;
        if (deadline % 100 > 59) {
            deadline -= 60; deadline += 100;
        }

        for (int x : timelogs[i]) {
            if (st < 6 && x > deadline) {
                pass = false;
                break; 
            }
            
            if (st == 7) st = 1;
            else st++;
        }
        
        if (pass) answer++;
    }
    
    return answer;
}