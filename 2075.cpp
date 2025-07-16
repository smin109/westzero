#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    
    priority_queue < int, vector < int >, greater < int > > pq;

    for(int i = 0; i < n * n; i++){
        int temp; cin >> temp; pq.push(temp);
        if(pq.size() > n) pq.pop();
    }

    cout << pq.top();

    return 0;
}