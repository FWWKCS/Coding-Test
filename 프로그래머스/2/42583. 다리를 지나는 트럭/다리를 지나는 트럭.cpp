#include <string>
#include <vector>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<int> onBridge(bridge_length, 0);
    int target = 0;
    int capacity = bridge_length;
    int curW = 0;
    while (target < truck_weights.size()) {
        // 1초 진행
        bool moved = false;
        for (int i = 0; i < bridge_length-1; ++i) {
            if (onBridge[i] > 0 || onBridge[i+1] > 0) {
                moved = true;
                if (i == 0) {
                    curW -= onBridge[i];
                    capacity++;
                    onBridge[i] = onBridge[i+1];
                    onBridge[i+1] = 0;
                }
                else {
                    onBridge[i] = onBridge[i+1];
                    onBridge[i+1] = 0;
                }
            }    
        }
        
        // 수용 가능
        if (capacity > 0
            && curW + truck_weights[target] <= weight) {
            moved = true;
            onBridge[bridge_length-1] = truck_weights[target];
            capacity--;
            curW += truck_weights[target];
            target++;
        }
        
        if (moved) answer++;
    }
    
    // 나머지 트럭 처리
    int idx = 0;
    for (int i = 0; i < bridge_length; ++i) {
        if (onBridge[i] > 0) idx = i+1;
    }
    
    return answer + idx;
}