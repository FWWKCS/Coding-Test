#include <iostream>
#include <set>
using namespace std;

int main() {
    string S; cin >> S;
    int dice[7] = {0, };
    set<int> s;
    int A, B, C; cin >> A >> B >> C;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    dice[A]++; dice[B]++; dice[C]++;

    int score = 0;
    for (int i = 0; i < 6; i++) 
        if (S[i] == 'Y') score = max(score, (i+1)*(dice[i+1]+2));
    
    if (S[6] == 'Y') {
        // Four of a Kind
        for (int i = 1; i <= 6; i++) 
            if (dice[i] >= 2) score = max(score, i*4);
    }
    if (S[7] == 'Y') {
        // Full House
        int is_two = 0, is_three = 0;
        if (s.size() == 1) { 
            is_three = *s.begin();
            if (is_three != 6) is_two = 6;
            else is_two = 5;
        }
        else if (s.size() == 2) {
            is_two = *s.begin();
            is_three = *prev(s.end());
        }

        score = max(score, 2*is_two + 3*is_three);
    }
    if (S[8] == 'Y') { // Little Straight
        if (s.size() == 3 && *prev(s.end()) != 6) score = max(score, 30);
    }
    if (S[9] == 'Y') { // Big Straight
        if (s.size() == 3 && *s.begin() != 1) score = max(score, 30);
    }
    if (S[10] == 'Y') { // Yacht
        if (s.size() == 1) score = max(score, 50);
    }
    if (S[11] == 'Y') { // Choice
        score = max(score, A+B+C+12);
    }

    cout << score;
}