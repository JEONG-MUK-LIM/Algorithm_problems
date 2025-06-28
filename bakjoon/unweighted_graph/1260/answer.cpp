#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int cur,vector<bool>& visited, vector<vector<int>>& graph){
    visited[cur] = true;
    cout << cur << ' ';
    for(int i:graph[cur]){
        if(!visited[i]) dfs(i,visited,graph);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,v;
    cin >> n >> m >> v;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(),graph[i].end());
    }
    vector<bool> visited(n+1,0);
    dfs(v,visited,graph);
    cout << '\n';

    for(int i=0; i<n+1; i++){
        visited[i] = false;
    }
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout << v << ' ';
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i:graph[cur]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                cout << i << ' ';
            }
        }
    }
}