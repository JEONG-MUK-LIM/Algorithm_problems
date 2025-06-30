#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>& matrix,vector<int>& color){
    for(int i=1; i<color.size(); i++){
        if(color[i] == 0){ // 연결되지 않은 경우가 존재할 수 있으니 반복문으로 탐색
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int iter:matrix[cur]){
                    if(color[iter] == 0) {
                        q.push(iter);
                        color[iter] = 3-color[cur];
                    }
                    else if(color[iter] == color[cur]) return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k,v,e;
    cin >> k;
    while(k--){
        cin >> v >> e;
        vector<vector<int>> matrix(v+1);
        for(int i=0; i<e; i++){
            int a,b;
            cin >> a >> b;
            matrix[a].push_back(b);
            matrix[b].push_back(a);
        }
        vector<int> color(v+1,0); 
        if(bfs(matrix,color)) cout << "YES\n";
        else cout  << "NO\n";
    }
}