#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<int> st;
    for (int i = 0; i < prices.size(); ++i) {
        if (st.empty() || prices[st.back()] <= prices[i]) st.push_back(i);
        else {
            while (!st.empty() && prices[st.back()] > prices[i]) {
                int idx = st.back();
                answer[idx] = i-idx;
                st.pop_back();
            }
            
            st.push_back(i);
        }
    }
    
    while (!st.empty()) {
        int idx = st.back();
        answer[idx] = prices.size() - 1 - idx;
        st.pop_back();
    }
    return answer;
}