#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist(int a,int b,vector<pair<int,int>>& cases,int n){
    auto [x1,y1] = cases[a];
    auto [x2,y2] = cases[b];
    if(a == 0) return abs(1-x2) + abs(1-y2);
    if(b == 0) return abs(x1-n) + abs(y1-n);
    return abs(x1-x2) + abs(y1-y2); 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,w;
    cin >> n >> w;
    vector<pair<int,int>> cases(w+1);
    vector<vector<int>> dp(w+1,vector<int>(w+1,1e6));
    vector<vector<pair<int,int>>> record(w+1,vector<pair<int,int>>(w+1));

    for(int i=1; i<=w; i++){
        cin >> cases[i].first >> cases[i].second;
    }
    dp[0][0] = 0;
    dp[0][1] = dist(1,0,cases,n); // 경찰차 2번이 이동, 1,0순
    dp[1][0] = dist(0,1,cases,n); // 경찰차 1번이 이동, 0,1순
    for(int i=0; i<=w; i++){
        for(int j=0; j<=w; j++){
            if(i==j) continue;
            int k = max(i,j) + 1;
            if(k > w) continue;

            int isChange = dp[i][k];
            dp[i][k] =  min(dp[i][k],dp[i][j] + dist(k,j,cases,n)); //두번째 경찰차가 j에서 k -> k,j순
            if(isChange != dp[i][k]) record[i][k] = {i,j};
            isChange = dp[k][j];
            dp[k][j] = min(dp[k][j],dp[i][j] + dist(i,k,cases,n)); //첫번째 경찰차가 i에서 k -> i,k순
            if(isChange != dp[k][j]) record[k][j] = {i,j};
        }
    }
    int answer = 1e6;
    int x,y;
    for(int i=0; i<=w-1; i++) {
        if(answer > dp[w][i] && dp[i][w] >= dp[w][i]) {
            x = w; y = i;
            answer = dp[w][i];
        }
        else if(answer > dp[i][w] && dp[i][w] < dp[w][i]){
            x = i; y = w;
            answer = dp[i][w];
        }
    }
    cout << answer << '\n';
    vector<int> police;
    for(int i=w; i>=1; i--){
        if(x == i) police.push_back(1);
        else police.push_back(2);
        auto [px,py] = record[x][y];
        x = px;
        y = py;
    }
    for(int i=w-1; i>=0; i--) cout << police[i] << '\n'; 
}