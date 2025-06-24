#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{  
    int answer = 0;
    set<int> info;
    for (auto x : nums) info.insert(x);
    answer = min(info.size(), nums.size()/2);
    return answer;
}