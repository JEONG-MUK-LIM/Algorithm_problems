#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n+1,vector<int>(m+1));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> matrix[i][j];
        }
    }
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int islandNum = 0;
    vector<vector<bool>> visited(n+1,vector<bool>(m+1,0));
    for(int x=1; x<=n; x++){
        for(int y=1; y<=m; y++){
            if(matrix[x][y] == 0 || visited[x][y]) continue;
            islandNum++;
            queue<pair<int,int>> q;
            q.push({x,y});
            visited[x][y] = 1;
            matrix[x][y] = islandNum;
            while(!q.empty()){
                auto [cx,cy] = q.front();
                q.pop();
                
                for(int i=0; i<4; i++){
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if(nx >= 1 && nx <=n && ny >=1 && ny<=m){
                        if(!visited[nx][ny] && matrix[nx][ny] != 0){
                            q.push({nx,ny});
                            visited[nx][ny] = 1;
                            matrix[nx][ny] = islandNum;
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> graph(islandNum + 1,vector<int>(islandNum+1,101));
    for(int i=0; i<=islandNum; i++){
        graph[i][i] = 0;
    }
    for(int x=1; x<=n; x++){
        for(int y=1; y<=m; y++){
            if(matrix[x][y] == 0) continue;
            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                int dist = 0;
                while(nx >= 1 && nx <=n && ny >= 1 && ny <= m 
                    && matrix[nx][ny] != matrix[x][y] && matrix[nx][ny] == 0){
                        nx = nx + dx[k];
                        ny = ny + dy[k];
                        dist++;
                }
                if(nx >= 1 && nx <=n && ny >= 1 && ny <= m && dist > 1 && graph[matrix[x][y]][matrix[nx][ny]] > dist) graph[matrix[x][y]][matrix[nx][ny]] = dist;
            }
        }
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> treeSet(islandNum+1,0);
    bool canBuild = 1;
    pq.push({0,1});
    int sum = 0;
    while(!pq.empty()){
        auto [d,cur] = pq.top();
        pq.pop();
        if(treeSet[cur]) continue;
        treeSet[cur] = true;
        sum += d;
        for(int i=1; i<=islandNum; i++){
            if(cur == i || graph[cur][i] == 101) continue;
            if(!treeSet[i]) pq.push({graph[cur][i],i});
        }
    }
    for(int i=1; i<=islandNum; i++){
        if(!treeSet[i]) {
            canBuild = false;
            break;
        }
    }
    if(canBuild) {
        cout << sum;
    } 
    else cout << -1;
}