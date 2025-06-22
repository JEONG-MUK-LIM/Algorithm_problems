#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXVAL 200001
vector<vector<pair<int,int>>> w_graph;

vector<int> dijkstra(int start,int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> fringe;
    vector<int> tree(V+1,MAXVAL);
    fringe.push({0,start});
    tree[start] = 0;
    while(!fringe.empty()){
            int curEdge = fringe.top().first;
            int curNode = fringe.top().second;
            fringe.pop();
            if(tree[curNode] < curEdge) continue;
            for(auto [w,v]:w_graph[curNode]){
                if(tree[v] > w + curEdge){
                    tree[v] = w + curEdge;
                    fringe.push({w+curEdge,v});
                }   
            }
    }
    return tree;
}       

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V,E,K,u,v,w; 
    cin >> V >> E >> K;
    w_graph.resize(V+1);
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        w_graph[u].push_back({w,v});
    }
    vector<int> minPath = dijkstra(K,V);
    for(int i=1; i<=V; i++){
        if(minPath[i] != MAXVAL) cout << minPath[i] << '\n';
        else cout << "INF\n";
    }
} 