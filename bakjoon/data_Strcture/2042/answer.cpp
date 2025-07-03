#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> arr;
vector<ll> segment;

ll find(ll node, ll start, ll end,ll l, ll r){
    if(r < start || l > end) return 0;
    if(l <= start && r >= end) return segment[node];
    ll mid = (start + end)/2;
    return find(node*2,start,mid,l,r) + find(node*2 + 1,mid+1,end,l,r);
}
ll build(ll node, ll start, ll end){
    if(start == end) return segment[node] = arr[start];
    ll mid = (start + end)/2;
    return segment[node] = build(node*2,start,mid) +build(node*2 + 1,mid+1,end);
}
void update(ll node, ll start, ll end, ll idx, ll val){
    if(start > idx || end < idx) return; 
    if(start == end){ // idx가 start = end = idx일때 까지 구간이 나눠지게된다.
        segment[node] = val;   // 그 후 스택에 쌓여져 있는 segment[node]연산이 실행되며 bottom up
        return;
    }
    ll mid = (start + end)/2;
    update(node*2, start, mid,idx,val);
    update(node*2+1,mid+1,end,idx,val);
    segment[node] = segment[2*node] + segment[2*node + 1]; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k;
    cin >> n >> m >> k;
    arr.resize(n+1);
    for(ll i=1; i<=n; i++){
        cin >> arr[i];
    }
    segment.resize(4*arr.size());
    build(1,1,n);

    for(ll i=0; i<m+k; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            arr[b] = c;
            update(1,1,n,b,c);
        }
        else if(a == 2){
            cout << find(1,1,n,b,c) << '\n';
        }
    }
}       