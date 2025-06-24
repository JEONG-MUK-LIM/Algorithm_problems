#include <iostream>
#include <vector>
#include <queue>    
#include <algorithm>
using namespace std;

vector<int> dijkstra(int start,vector<vector<pair<int,int>>>& graph){
    int N = graph.size() - 1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    vector<int> dist(N+1,2000001);
    dist[start] = 0;
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        if(dist[curNode] < curDist) continue;
        for(auto [w,v]:graph[curNode]){
            int sumDist = w + dist[curNode];
            if(dist[v] > sumDist){
                pq.push({sumDist,v});
                dist[v] = sumDist;
            }
        }  
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int n,m,t,
    s,g,h,
    a,b,d;
    cin >> T;
    while(T--){
        cin >> n >> m >> t;
        vector<vector<pair<int,int>>> graph(n+1);
        cin >> s >> g >> h;
        while(m--){
            cin >> a >> b >> d;
            graph[a].push_back({d,b});
            graph[b].push_back({d,a});
        }
        vector<int> dist_s = dijkstra(s,graph);
        vector<int> dist_g = dijkstra(g,graph);
        vector<int> dist_h = dijkstra(h,graph);

        vector<int> suspect;
        for(int i=0; i<t; i++){
            int t_i;
            cin >> t_i;
            if(dist_s[t_i] == min(dist_s[g] + dist_g[h] + dist_h[t_i]
                ,dist_s[h] + dist_h[g] + dist_g[t_i]))
                suspect.push_back(t_i);
        }
        sort(suspect.begin(),suspect.end());
        for(int i:suspect){
            cout << i << ' ';
        }
        cout << '\n';
    }
}