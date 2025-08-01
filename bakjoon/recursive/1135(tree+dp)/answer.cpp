#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cmath>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int recursive(const vector<vector<int>>& child, int cur){
    if(child[cur].size() == 0) return 0; // 리프노드는 더 진행할 필요없으므로 0초걸림
    vector<int> time;
    for(int next:child[cur]){
        int t = recursive(child,next); //자식이 루트노드인 서브트리에서의 시간을 구함
        time.push_back(t);
    }
    sort(time.begin(),time.end(),greater<int>());
    int ret = -1;   
    for(int i=0; i<time.size(); i++){
        ret = max(ret,time[i]+i+1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> child(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num == -1) continue;
        child[num].push_back(i);
    }   
    cout << recursive(child,0);
}   