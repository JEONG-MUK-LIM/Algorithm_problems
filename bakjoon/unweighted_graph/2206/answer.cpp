#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<string> matrix(n);
    for(int i=0; i<n; i++){
        cin >>  matrix[i];
    }
    queue<tuple<int,int,int>> q;
    int dist[1001][1001][2]{0,};
    q.push({0,0,0});
    int ni[4] = { 0,0,-1,1};
    int nj[4] = {-1,1,0,0};    
    dist[0][0][0] = 1;
    while(!q.empty()){  
        int x,y,broken;
        tie(x,y,broken) = q.front(); q.pop();
        if(x == n-1 && y == m-1){
            cout << dist[x][y][broken];
            return 0;
        }
        for(int i=0; i<4; i++){
            int nx = x + ni[i];
            int ny = y + nj[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(matrix[nx][ny] == '0'){
                    if(dist[nx][ny][broken] == 0){
                        dist[nx][ny][broken] = dist[x][y][broken] + 1;
                        q.push({nx,ny,broken});
                    }
                }
                else{
                    if(broken == 0 && dist[nx][ny][1] == 0){
                        dist[nx][ny][1] = dist[x][y][0] + 1;
                        q.push({nx,ny,1});
                    }
                }
            }
        }  
    }
    cout << -1;
    return 0;
}   