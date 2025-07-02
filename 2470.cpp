#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    pair < int, int > res;
    vector < int > v;

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }

    sort(v.begin(), v.end());
    
    int le = 0, ri = n - 1;
    int mi = INT_MAX;

    while(le < ri){
        int s = v[le] + v[ri];

        if(mi > abs(s)){
            mi = abs(s);
            res = {v[le], v[ri]};
        }

        if(s > 0) ri--;
        else le++;
    }

    cout << res.first << ' ' << res.second;

    return 0;
}