#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cmath>
#include <unordered_set>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;
int ans = 0;
vector<vector<int>> memo;
void dfs(int cnt, vector<vector<int>>& matrix, vector<vector<int>>& memo,unordered_set<int>& path,int x,int y){
    if(memo[x][y] >= cnt) return;
    memo[x][y] = cnt;
    for(int i=0; i<4; i++){
        int nx = x + dx[i]*matrix[x][y];
        int ny = y + dy[i]*matrix[x][y];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != -1){
            if(path.count(nx*50 + ny)) {
                ans = 1e9;
                return;
            } 
            path.insert(nx*50+ny);
            dfs(cnt+1,matrix,memo,path,nx,ny);
            path.erase(nx*50+ny);
        }
    }
    ans = max(cnt + 1,ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            if(str[j] != 'H') matrix[i][j] = str[j] - '0';
            else matrix[i][j] = -1;
        }
    }
    memo.resize(n,vector<int>(m,-1));
    unordered_set<int> path;
    path.insert(0);
    dfs(0,matrix,memo,path,0,0);
    if(ans == 1e9) cout << -1;
    else cout << ans;
}