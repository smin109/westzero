#include<bits/stdc++.h>
using namespace std;
 
int main(){    
    int visited[104][104];
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    int N,M; cin >> N >> M;
    string line;
    int mp[104][104];
    
    for(int i = 0; i < N; i++){
        cin >> line;
        for(int j = 0; j < M;j++){
            mp[i][j] = line[j];
        }
    }
    
    queue<pair<int, int>> q;
    int x = 0;
    int y = 0;
    visited[x][y] = 1;
    q.push({x,y});
    while(q.size()){
        tie(x,y)= q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || mp[nx][ny] == '0' || visited[nx][ny] ) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    cout << visited[N-1][M-1];
    return 0;
}
