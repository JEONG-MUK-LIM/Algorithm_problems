#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    cin >> N >> K;
    if(K < N){
        cout << N-K;
        return 0;
    }
    deque<int> dq;
    vector<int> dist(100001,100000);
    dq.push_front(N);
    dist[N] = 0;
    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();
        if(cur == K){
            cout << dist[cur];
            return 0;
        }
        if(cur*2 <= 100000 && dist[2*cur] > dist[cur]) {
            dq.push_front(cur*2);
            dist[2*cur]=dist[cur];
        }
        if(cur-1 >= 0 && dist[cur-1] > dist[cur] + 1) {
            dq.push_back(cur-1);
            dist[cur-1] = dist[cur] + 1;
        }
        if(cur+1 <= 100000 && dist[cur+1] > dist[cur] + 1) {
            dq.push_back(cur+1);
            dist[cur+1] = dist[cur] + 1;
        }
    }
} 