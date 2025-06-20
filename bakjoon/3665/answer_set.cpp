#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> rank(n+1);
        vector<unordered_set<int>> edges(n+1);
        for(int i=1; i<=n; i++){
            cin >> rank[i];
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                edges[rank[i]].insert(rank[j]);
            }
        }
        cin >> m;
        while(m--){
            int a,b;
            cin >> a >> b;
            if(edges[a].find(b) != edges[a].end()){
                edges[a].erase(b);
                edges[b].insert(a);
            }
            else {
                edges[b].erase(a);
                edges[a].insert(b);
            }
        }
        vector<bool> check(n+1,0);
        bool state = true;
        for(int i=1; i<=n; i++){
            if(!check[n-edges[i].size()]){
                check[n-edges[i].size()] = true;
                rank[n-edges[i].size()] = i;
            }
            else{
                state = false;
                break;
            }
        }
        if(state){
            for(int i=1; i<=n; i++){
                cout << rank[i] << ' ';
            }
            cout << '\n';
        }
        else cout << "IMPOSSIBLE" << '\n';
    }
}   