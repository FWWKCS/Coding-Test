#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void solve(vector<int> &preorder, vector<int> &inorder, vector<int> &inorder_idx, vector<int> &postorder, int p_s, int p_e, int i_s, int i_e) {
    if (i_s == i_e) {
        postorder.push_back(preorder[p_s]);
        return;
    }

    int mid = inorder_idx[preorder[p_s]];
    int p_L = mid - i_s;
    int p_R = i_e - mid;

    if (p_L != 0) solve(preorder, inorder, inorder_idx, postorder, p_s+1, p_s+p_L, i_s, mid-1);
    if (p_R != 0) solve(preorder, inorder, inorder_idx, postorder, p_s+p_L+1, p_e, mid+1, i_e);
    postorder.push_back(preorder[p_s]);
}

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> preorder(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            preorder[i] = x;
        }

        vector<int> inorder(n);
        vector<int> inorder_idx(n+1);
        for (int i = 0; i < n; i++) {
            int x ; cin >> x;
            inorder[i] = x;
            inorder_idx[x] = i;
        }

        vector<int> postorder;
        int start = 0, end = n-1;
        solve(preorder, inorder, inorder_idx, postorder, start, end, start, end);

        for (auto x : postorder) cout << x << ' ';
        cout << '\n';
    }
}