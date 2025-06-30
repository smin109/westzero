#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int arr[N + 1];
    for(int i = 1; i <= N; i++) cin >> arr[i];

    int step[N + 1];
    step[1] = arr[1];
    step[2] = arr[1] + arr[2];
    step[3] = arr[3] + max(arr[1], arr[2]);

    for(int i = 4; i <= N; i++) step[i] = arr[i] + max(arr[i - 1] + step[i - 3], step[i - 2]);

    cout << step[N]; 

    return 0;
}