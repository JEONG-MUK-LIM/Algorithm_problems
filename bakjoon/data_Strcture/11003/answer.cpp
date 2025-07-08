#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,L;
    cin >> n >> L;
    deque<pair<int,int>> dq;
    int a;
    for(int i=1; i<=n; i++){
        cin >> a;
        while(!dq.empty() && dq.back().first > a){
            dq.pop_back();
        }

        dq.push_back({a,i});
        if(dq.front().second < i-L+1) dq.pop_front();
        cout << dq.front().first << ' ';
    }
}