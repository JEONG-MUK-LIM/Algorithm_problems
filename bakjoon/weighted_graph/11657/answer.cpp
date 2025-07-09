#include <iostream>
#include <vector>
using namespace std;

struct edge{
    int u,v,w;
    edge(){
        w = 1e9;
    }
    edge(int u,int v ,int w){
        this->u = u;
        this-> v = v;
        this->w = w;
    }
};

vector<edge> edges;

pair<vector<long long>,bool> bellmanford(int n,int start){
    vector<long long> dist(n+1,1e9);
    bool check = 0;
    dist[start] = 0;
    for(int i=1; i<n; i++){
        for(const auto& e:edges){
            if(dist[e.u] != 1e9 && dist[e.v] > dist[e.u] + e.w){
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    for(const auto& e:edges){
        if(dist[e.u] != 1e9 && dist[e.v] > dist[e.u] + e.w){
            check = 1;
            break;
        }
    }
    return {dist,check};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    pair<vector<long long>,bool> dist = bellmanford(n,1);
    if(dist.second) {
        cout << -1 << '\n';
    }
    else{
        for(int i=2; i<=n; i++){
            if(dist.first[i] == 1e9) cout << -1;
            else cout << dist.first[i];
            cout << '\n';
        }
    }
}