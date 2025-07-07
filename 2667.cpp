#include <bits/stdc++.h>
using namespace std;

int mp[25][25];
int vi[25][25];
vector<int> v;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int N;
int cnt;
 
void dfs(int r, int c){
 
    for(int i = 0; i<4; i++){
        
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr>=N || nr<0 || nc>=N || nc<0) continue;
        
        if(vi[nr][nc]==0 && mp[nr][nc]==1){  
            vi[nr][nc] = 1;                 
            cnt+=1;                                
            dfs(nr,nc);
        }
    }
 
}
 
 
int main(){
    
    int res=0;
    
    cin >> N;
    string str;
    
    for(int i = 0; i<N; i++){
        cin >> str;
        for(int j = 0; j<str.length(); j++){
            vi[i][j] = 0;
            
            if(str[j] == '1'){
             mp[i][j] = 1;
            }
            else mp[i][j] = 0;
        }
    }
    
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            
            if (mp[i][j]==1 && vi[i][j]==0){
                vi[i][j] = 1;
                cnt = 1;                    
                dfs(i,j);
                v.push_back(cnt);
                res++;                         
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout << res << "\n";
    
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
 
    return 0;
}