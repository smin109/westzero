#include<bits/stdc++.h>
using namespace std;

int R, C;
char arr[105][105];
bool vi[105][105];
int dir[4][2]{{1,0}, {0,1}, {-1, 0}, {0, -1}};
int res, tim;

bool bfs() {
    vi[0][0] = true;
    int cnt{0};
    queue < pair < int, int > > q;
    q.push({0, 0});
    tim++;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int i{0}; i < 4; i++) {
            int nr{r + dir[i][0]}, nc{c + dir[i][1]};
            if (nr >= 0 && nc >= 0 && nr < R && nc < C && !vi[nr][nc]) {
                if (arr[nr][nc] == '0')  q.push({nr, nc});
                else {
                    arr[nr][nc] = '0';
                    cnt++;
                }
                vi[nr][nc] = true;  
            }
        }
    }

    if (cnt == 0) {
        cout << --tim << endl << res;
        return true;
    } else {
        res = cnt;
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;

    for (int i{0}; i < R; i++) for (int j{0}; j < C; j++) cin >> arr[i][j];

    while (true) {
        if(bfs()) break;
        memset(vi, false, sizeof(vi));
    }

    return 0;
}