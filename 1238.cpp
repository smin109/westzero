#include<bits/stdc++.h>
#define pii pair < int, int >
using namespace std;
 
 
int N, M, X;
const int INF = INT_MAX;
vector < pii > graph[2][1001]; 
vector < int > dist[2];
int rdi[1001];
 
void input(){
    cin >> N >> M >> X;
    for(int i{0}, u, v, t; i < M; i++){
        cin >> u >> v >> t;
        graph[0][u].push_back({t, v});
        graph[1][v].push_back({t, u});
    }
    dist[0].resize(N + 1, INF);
    dist[1].resize(N + 1, INF);
}
 
void dijk(int k){
    dist[k][X] = 0;
    
    priority_queue < pii, vector < pii >, greater < pii > > pq;
    pq.push({0, X});
    
    while(!pq.empty()){
        auto [mc, now] = pq.top();
        pq.pop();
        
        if(mc > dist[k][now]) continue;
        
        for(int i{0}; i < graph[k][now].size(); i++){
            int next = graph[k][now][i].second;
            int next_cost = mc + graph[k][now][i].first;
            
            if(next_cost < dist[k][next]){
                dist[k][next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    input();
    
    dijk(1);
    dijk(0);
    
    int res = 0;
    for(int i{1}; i <= N; i++) res = max(res, dist[0][i] + dist[1][i]);
    
    cout << res;
    
    return 0;
}