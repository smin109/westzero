#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long N, M, ma = 0; cin >> N >> M;
    int tree[10000001];

    for(int i = 0; i < N; i++) cin >> tree[i];

    sort(tree, tree + N);

    long long low = 0, high = tree[N - 1];

    while(low <= high){
        long long sum = 0;
        long long mid = (low + high) / 2;

        for(int i = 0; i < N; i++) if(tree[i] - mid > 0) sum += tree[i] - mid;

        if(sum >= M){
            ma = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << ma;

    return 0;
}