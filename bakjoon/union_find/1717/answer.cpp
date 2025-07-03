#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> setId;

int find(int cur){
    if(cur == setId[cur]) return cur;
    return setId[cur] = find(setId[cur]); //path compression
}
void unite(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    setId[b] = a;   // 최적화시 각 집합의 원소 수를 기록한 벡터를 이용해 더 작은 쪽을 더 큰 쪽에 추가
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    setId.resize(n+1);
    for(int i=1; i<=n; i++) setId[i] = i;

    for(int i=0; i<m; i++){
        int c,a,b;
        cin >> c >> a >> b;
        if(c == 0){
            unite(a,b);
        }
        else if(c == 1){
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}       