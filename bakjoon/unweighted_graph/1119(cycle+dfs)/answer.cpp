#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cmath>
#include <queue>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int n;

void dfs(vector<vector<bool>>& graph,vector<vector<bool>>& visited,int cur,int& edgeNum,int& nodeNum){
    if(!visited[cur][n]){
        nodeNum++;
        visited[cur][n] = 1;
    }
    visited[cur][n] = 1;
    for(int i=0; i<n; i++){
        if(!graph[cur][i]) continue; //같은 경우 및 연결이 안된 경우 스킵
        if(visited[cur][i] || visited[i][cur]) continue; // 이미 지난 간선인 경우 스킵
        edgeNum++;
        visited[cur][i] = 1;
        visited[i][cur] = 1; // 노드를 방문했어도 간선은 방문하지 않은 경우
        if(!visited[i][n]) dfs(graph,visited,i,edgeNum,nodeNum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    vector<vector<bool>> graph(n,vector<bool>(n,0));
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == 'Y') {
                graph[i][j] = 1;
            }
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(n+1,0)); 
    // n번째 자리에 해당 노드를 방문했는지, 그외는 간선을 방문했는지 기록
    int edgeNum,nodeNum;
    int ans = 0;
    vector<pair<int,int>> part;
    for(int i=0; i<n; i++){
        if(visited[i][n]) continue;
        edgeNum = 0;
        nodeNum = 0;
        dfs(graph,visited,i,edgeNum,nodeNum);
        part.push_back({edgeNum,nodeNum});
    }
    int sumCycle = 0;
    for(int i=0; i<part.size(); i++){
        if(part[i].first == 0 && part.size() > 1) {
            cout << -1;
            return 0;
        }
        sumCycle += (part[i].first - part[i].second + 1); //사이클 개수공식
    }
    if(sumCycle >= part.size() - 1) // 필요한 연결횟수,즉 연결요소의개수-1, 연결할때마다 사이클1씩감소
        cout << part.size()-1;
    else cout << -1;
}