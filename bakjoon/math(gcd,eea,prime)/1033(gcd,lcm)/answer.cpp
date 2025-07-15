#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct edge{
    int dst;
    ll p,q;
};

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

vector<bool> visited;
void dfs(vector<vector<edge>>& graph,int n,int cur,vector<ll>& amount){
    visited[cur] = true;
    for(auto& e:graph[cur]){
        if(!visited[e.dst]){
            amount[e.dst] = amount[cur] * e.q / e.p;
            dfs(graph,n,e.dst,amount);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<edge>> graph(n);
    visited.resize(n,0);
    vector<ll> amount(n);
    int a,b;
    ll lcm = 1;
    for(int i=0; i<n-1; i++){
        ll p,q;
        cin >> a >> b >> p >> q;
        ll d = gcd(p,q);
        p = p/d;
        q = q/d;
        graph[a].push_back({b,p,q});
        graph[b].push_back({a,q,p});
        lcm = lcm * p * q;             
    }   
    amount[0] = lcm;
    dfs(graph,n,0,amount);
    ll mgcd = lcm;
    for(int i=0; i<n; i++){
        mgcd = gcd(mgcd,amount[i]);
    }
    for(int i=0; i<n; i++){
        cout << amount[i]/mgcd << ' ';
    }
}       