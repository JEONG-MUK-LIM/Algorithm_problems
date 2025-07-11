#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x,int y,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    if(dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;
    for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= 0 && nx <n && ny >= 0 && ny <n){
            if(matrix[nx][ny] > matrix[x][y]){
                dp[x][y] = max(dp[x][y],dfs(nx,ny,n,matrix,dp) + 1);
            }
        }           
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }   
    }
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer = max(answer,dfs(i,j,n,matrix,dp));
        }
    }

    cout << answer;
}