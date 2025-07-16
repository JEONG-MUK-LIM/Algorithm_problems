#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isConnected(vector<pair<int,int>>& point){
queue<int> q;
int n = point.size();
vector<bool> visited(n,0);
q.push(0);
visited[0] = 1;
int count = 1;
while(!q.empty()){
    int cur = q.front();
    q.pop();
    auto [x,y] = point[cur];
    for(int j=0; j<n; j++){
        if(!visited[j]){
            auto [nx,ny] = point[j];            
            if((abs(nx - x) + abs(ny - y)) == 1){
                q.push(j);
                visited[j] = 1;
                count++;
            }
        }
    }
}    
return n == count;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);

int n = 0;
vector<pair<int,int>> base;
int baseMask = 0;
for(int i=0; i < 5; i++){
    string str;
    cin >> str;
    for(int j=0; j<5; j++){
        if(str[j] == '*') {
            n++;
            base.push_back({i,j});
            baseMask = baseMask | (1 << (5*i + j) );
        }
    }
}
queue<pair<vector<pair<int,int>>,int>> q;
unordered_set<int> hash;
hash.insert(baseMask);
q.push({base,0});
while(!q.empty()){
    auto [state,move] = q.front();
    q.pop();
    if(isConnected(state)){
        cout << move;
        break;
    }
    for(int i=0; i<n; i++){
        auto [x,y] = state[i];
        for(int j=0; j<4; j++){ 
            int nx = x + dx[j];
            int ny = y + dy[j];
            bool range_overlap = 0;
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) range_overlap = 1;
            auto next = state;
            next[i].first = nx;
            next[i].second = ny;
            for(int k=0; k<n; k++){
                if(k != i && next[i] == next[k]) range_overlap = 1;
            }
            if(!range_overlap){
                int mask = 0;
                for(int k=0; k<n; k++){
                    mask = mask | (1 << (5*next[k].first + next[k].second) );
                }
                if(!hash.count(mask)){
                    hash.insert(mask);
                    q.push({next,move+1});
                }
            }
        }
    }
}
}           