#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v,e;
    cin >> v >> e;
    vector<vector<pair<int,int>>> graph(v+1);
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<bool> visited(v+1,0);
    int sum = 0;
    while(!pq.empty()){
        int edge = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        sum += edge;
        for(auto [w,v]:graph[cur]){
            if(!visited[v]){
                pq.push({w,v});
            }
        }
    }
    cout << sum;
}       