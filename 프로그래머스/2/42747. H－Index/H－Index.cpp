#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int len = citations.size();
    sort(citations.begin(), citations.end());
    
    int s = 0, e = citations.back();
    int h;
    while (s <= e) {
        h = (s+e)/2;
        int up = 0, down = 0;
        for (int k = 0; k < citations.size(); k++) {
            if (citations[k] >= h) {
                up = citations.size()-k;
                down = citations.size()-up;
                cout << h << ' ' << up << ' ' << down << '\n';
                break;
            }
        }
        
        if (up >= h && down <= h) {
            answer = h;
            s = h+1;
        }
        else e = h-1;
    }

    return answer;
}