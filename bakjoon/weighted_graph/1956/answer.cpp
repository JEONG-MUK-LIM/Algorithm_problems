#include <iostream>
#include <vector>

using namespace std;
#define MAXVAL 4000001

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(v+1,vector<int>(v+1,MAXVAL)); 
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    for(int i=1; i<=v; i++){
        graph[i][i] = 0;
    }
    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    int minPath = MAXVAL;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i != j && minPath > graph[i][j] + graph[j][i]) minPath = graph[i][j] + graph[j][i];
        }
    }
    if(minPath < MAXVAL) cout << minPath;
    else cout << -1; 
}