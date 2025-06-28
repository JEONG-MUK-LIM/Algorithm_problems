#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        priority_queue<int,vector<int>,less<int>> maxHeap;
        cout << (n+1)/2 << '\n';
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(minHeap.empty() || minHeap.top() < x) 
                minHeap.push(x);
            else maxHeap.push(x);

            if(minHeap.size() > maxHeap.size() + 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            if(i%2 == 0){
                if(minHeap.size() > maxHeap.size()) cout << minHeap.top() << ' ';
                else cout << maxHeap.top() << ' ';
            }
        }
        cout << '\n';
    }
}