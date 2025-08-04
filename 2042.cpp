#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll *tree;
ll arr[1000001];

ll init(int no, int st, int ed) {
    if (st == ed) return tree[no] = arr[st];
    int mid{(st + ed) / 2};
    return tree[no] = init(2 * no, st, mid) + init(2 * no + 1, mid + 1, ed);
}

ll sum(int no, int st, int ed, int le, int ri) {
    if (le > ed || ri < st) return 0;
    if (le <= st && ed <= ri) return tree[no];
    int mid{(st + ed) / 2};
    return sum(no * 2, st, mid, le, ri) + sum(no * 2 + 1, mid + 1, ed, le, ri);
}


void upd(int no, int st, int ed, int idx, ll diff) {
    if (idx < st || idx > ed) return;
    tree[no] += diff;
    if (st == ed) return;
    int mid{(st + ed) / 2};
    upd(no * 2, st, mid, idx, diff);
    upd(no * 2 + 1, mid + 1, ed, idx, diff);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int num, M, K, a, b; ll c; cin >> num >> M >> K;
    int height{ceil(log2(num))};
    
    tree = new ll[1 << (height + 1)];
    
    for (int i{0}; i < num; i++) cin >> arr[i];
    init(1, 0, num - 1);
    
    for (int i{0}; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            ll diff{c - arr[b - 1]};
            arr[b - 1] = c;
            upd(1, 0, num - 1, b - 1, diff);
        } else {
             cout << sum(1, 0, num - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}