#include<bits/stdc++.h>
using namespace std;

stack < pair < int, int > > st;  // start at rightend and move to left 

int N, K;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    
    for(int i  = 1; i <= N; i++){
        cin >> K;

        if(st.empty()){
            st.push({1, K});
            cout << "0 ";
        }
        else{
            while(!st.empty()){
                if(st.top().second > K){
                    cout << st.top().first << " ";
                    break;
                }
                else  st.pop();
            }
        }
        if(st.empty()) cout << "0 ";

        st.push({i, K});
    }

    return 0;
}