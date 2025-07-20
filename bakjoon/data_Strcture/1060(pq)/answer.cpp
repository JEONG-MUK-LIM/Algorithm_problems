#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L,n;
    cin >> L;
    vector<ll> arr(L+1);
    for(int i=0; i<L; i++){
        cin >> arr[i];      // L,n,arr[i]의 입력은 항상 1보다 큼
    }
    arr[L] = 0; 
    cin >> n;
    sort(arr.begin(),arr.end()); // arr[0] = 0이 됨, 0부터 가장작은 집합의 원소까지의 구간도 포함

    vector<pair<ll,ll>> block(L);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    // 해당 점을 포함하는 구간의 개수가 작은 점부터 오름차순으로 정렬, (구간수,점)으로 저장
    for(int i=0; i<L; i++){
        ll end = arr[i+1]-1;
        ll start = arr[i] + 1;
        ll count = end-start;
        block[i] = {count,0};      //구간내 시작지점이 포함된 구간의 개수, 구간에서의 시작인덱스
        // 1 2 3 4 5 에 추가인덱스가 1이면 2와4 를 의미, 구간에서 점이 한개인경우 구간이 0개
    }
    for(int i=1; i<=L; i++){
        pq.push({0,arr[i]});
    }
    while(n>0){
        for(int i=0; i<L; i++){
            if(block[i].first < 0) continue; // 구간내 점이 없는 경우
            int end = arr[i+1]-1;
            int start = arr[i] + 1;
            int L = start + block[i].second;
            int R = end - block[i].second;
            if(L > R) continue;     // 구간에서 시작인덱스가 구간의 절반을 넘은경우
            pq.push({block[i].first,L});
            if(L != R){
                pq.push({block[i].first, R});
            }
            block[i].second++;
            ll j = block[i].second;
            block[i].first = j * (end - start - j) + j + (end - start - j);
        }                  //j를 포함하면서 양끝이 j가 아닌 좋은구간 + 양끝이 j인 좋은구간
        if(pq.empty()) break;
        cout << pq.top().second << ' ';
        pq.pop();
        n--;
    }
    for(int i=1; i<=n; i++){    //구간 내 점 수가 n개보다 작은 경우
        cout << arr[L] + i << ' ';
    }
}           