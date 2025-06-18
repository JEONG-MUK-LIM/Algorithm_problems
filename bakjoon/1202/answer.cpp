#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> jewels(n);
    vector<int> bags(k);
    for(int i=0; i<n; i++){
        cin >> jewels[i].first >> jewels[i].second;
    }
    for(int i=0; i<k; i++){
        cin >> bags[i];
    }
    sort(jewels.begin(),jewels.end());
    sort(bags.begin(),bags.end());

    unsigned long long maxVal = 0;
    priority_queue<int> pq;
    int j = 0;
    for(int i=0; i < k; i++){
        while( j < n && jewels[j].first <= bags[i] ){
            pq.push(jewels[j].second);
            j++;
        }
        if(!pq.empty()){
            maxVal += pq.top();
            pq.pop();   
        }
    }

    cout << maxVal;
}