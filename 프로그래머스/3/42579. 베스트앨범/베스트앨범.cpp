#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> total_play;
map<string, vector<pair<int, int>>> genres_info;

bool customSort(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) return a.first < b.first; // 기준2
    return a.second > b.second; // 기준3
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); ++i) {
        total_play[genres[i]] += plays[i];
        genres_info[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> play_info;
    for (auto t : total_play) {
        play_info.push_back({t.second, t.first});
    }
    
    sort(play_info.rbegin(), play_info.rend()); // 기준1
    
    for (auto t : play_info) {
        string genre = t.second;
        sort(genres_info[genre].rbegin(), genres_info[genre].rend(), customSort);
        answer.push_back(genres_info[genre][0].second);
        if (genres_info[genre].size() >= 2) {
            answer.push_back(genres_info[genre][1].second);
        }
    }
    
    return answer;
}