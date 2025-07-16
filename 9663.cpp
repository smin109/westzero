#include<bits/stdc++.h>
using namespace std;

int co[16];
int N, to = 0;

bool che(int le){
    for(int i = 0; i < le; i++) if(co[i] == co[le] || abs(co[le] - co[i]) == le - i) return false;
    return true;
}

void nq(int x){
    if(x == N) to ++;
    else{
        for(int i = 0; i < N; i++){
            co[x] = i;
            if(che(x)) nq(x + 1);
        }
    }
}

int main(){
    cin >> N; nq(0);
    cout << to;
    return 0;
}