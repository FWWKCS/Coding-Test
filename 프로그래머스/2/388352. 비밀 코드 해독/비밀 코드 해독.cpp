#include <string>
#include <vector>

using namespace std;
int answer;
vector<int> seq;

void check(vector<vector<int>> &q, vector<int> &ans) {
    int m = q.size();
    
    for (int i = 0; i < m; i++) {
        int result = 0;
        int qi = 0, si = 0; 
        while (qi < 5 && si < 5) {
            if (seq[si] == q[i][qi]) {
                result++;
                si++; qi++;
            }
            else if (seq[si] > q[i][qi]) qi++;
            else si++;
        }
        
        if (result != ans[i]) return;
    }
    
    answer++;
}

void recursion(int n, int l, vector<vector<int>> &q, vector<int> &ans) {
    if (seq.size() == 5) {
        check(q, ans);
        return;
    }   
    
    for (int i = l+1; i <= n; i++) {
        seq.push_back(i);
        recursion(n, i, q, ans);
        seq.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    answer = 0;
    recursion(n, 0, q, ans);    
    
    return answer;
}