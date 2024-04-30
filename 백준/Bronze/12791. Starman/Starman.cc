#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<string>> album = {
    {1967, {"DavidBowie"}},
    {1969, {"SpaceOddity"}},
    {1970, {"TheManWhoSoldTheWorld"}},
    {1971, {"HunkyDory"}},
    {1972, {"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"}},
    {1973, {"AladdinSane", "PinUps"}},
    {1974, {"DiamondDogs"}},
    {1975, {"YoungAmericans"}},
    {1976, {"StationToStation"}},
    {1977, {"Low", "Heroes"}},
    {1979, {"Lodger"}},
    {1980, {"ScaryMonstersAndSuperCreeps"}},
    {1983, {"LetsDance"}},
    {1984, {"Tonight"}},
    {1987, {"NeverLetMeDown"}},
    {1993, {"BlackTieWhiteNoise"}},
    {1995, {"1.Outside"}},
    {1997, {"Earthling"}},
    {1999, {"Hours"}},
    {2002, {"Heathen"}},
    {2003, {"Reality"}},
    {2013, {"TheNextDay"}},
    {2016, {"BlackStar"}}
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int S, E; cin >> S >> E;
        int count = 0;
        for (int x = S; x <= E; x++) {
            if (album.find(x) != album.end()) count += album[x].size();
        }
        cout << count << '\n';

        for (int x = S; x <= E; x++) {
            if (album.find(x) != album.end()) {
                for (auto k : album[x]) cout << x << ' ' << k << '\n';
            }
        }
    }

}