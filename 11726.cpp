#include<bits/stdc++.h>
using namespace std;
    
int dp[1005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    dp[1] = 1; dp[2] = 2;

    for(int i = 3; i <= N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    cout << dp[N];

    return 0;
}