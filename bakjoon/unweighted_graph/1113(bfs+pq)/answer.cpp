#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            matrix[i][j] = str[j] - '0';
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        visited[i][0] = 1;
        visited[i][m-1] = 1;
        pq.push({matrix[i][0],i,0});
        pq.push({matrix[i][m-1],i,m-1});
    }
    for(int j=1; j<m-1; j++){
        visited[0][j] = 1;
        visited[n-1][j] = 1; 
        pq.push({matrix[0][j],0,j});
        pq.push({matrix[n-1][j],n-1,j});
    }
    int sum = 0;
    while(!pq.empty()){
        int h,x,y;
        tie(h,x,y) = pq.top(); pq.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
            continue;
            visited[nx][ny] = 1;
            if(matrix[nx][ny] >= h) {
                pq.push({matrix[nx][ny],nx,ny});
            }
            else{
                sum += (h - matrix[nx][ny]);
                matrix[nx][ny] = h;
                pq.push({h,nx,ny});
            }
        }
    }
    cout << sum;
}