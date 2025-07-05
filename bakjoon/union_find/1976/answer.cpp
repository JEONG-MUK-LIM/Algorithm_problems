#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> setId;

int find(int a){
    if(setId[a] == a) return a;
    return setId[a] = find(setId[a]);
}

void unite(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    setId[b] = a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    graph.resize(n+1,vector<int>(n+1));
    setId.resize(n+1);
    for(int i=1; i <= n; i++){
        setId[i] = i;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1) unite(i,j);
        }
    }
    int x;
    int id;
    cin >> x;
    id = find(x);
    while(--m){
        cin >> x;
        int temp = id;
        id = find(x);
        if(temp != id) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}