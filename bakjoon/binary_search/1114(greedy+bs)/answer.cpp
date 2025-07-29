#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <cmath>
#include <queue>
using namespace std;    

typedef unsigned long long ull; 
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L,K,C;
    cin >> L >> K >> C;
    vector<int> slice(K);
    for(int i=0; i<K; i++){
        cin >> slice[i];
    }
    slice.push_back(0);
    sort(slice.begin(),slice.end());
    slice.erase(unique(slice.begin(),slice.end()),slice.end());
    K = slice.size();

    int l,r;
    l = 0; r = L; 
    int ans,minCnt,pos;
    while(l <= r){
        int mid = (l+r)/2;

        int cnt = 0;
        int end = L;
        for(int i=K-1; i>0; i--){
            if(end - slice[i] > mid) break;
            if(end - slice[i-1] > mid && end - slice[i] <= mid){
                cnt++;
                end = slice[i];
            }
        }
        if(end - slice[0] <= mid && cnt <= C){
            minCnt = cnt;
            pos = end;
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if(minCnt < C){
        cout << ans << ' ' << slice[1];
    }
    else cout << ans << ' ' << pos;
}