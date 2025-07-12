#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> segment; // 자신보다 작거나 같은 값의 개수의 누적합을 저장

void update(int node,int start,int end,int idx){
    if(idx < start || end < idx) return;
    if(start == end){
        segment[node]++;
        return;
    }
    int mid = (start+end)/2;    
    update(node*2, start,mid,idx);
    update(node*2+1,mid+1,end,idx);
    segment[node] = segment[node*2] + segment[node*2 + 1];
}
long long find(int node,int start, int end,int l,int r){
    if(l > end || r < start) return 0;
    if(l <= start && end <= r) return segment[node];
    int mid = (start+end)/2;
    return find(node*2, start,mid,l,r) + find(node*2+1,mid+1,end,l,r);
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr[i] = {num,i};
    }   
    sort(arr.begin(),arr.end());    
    vector<int> idxArr(n);
    int rank = 0;
    idxArr[arr[0].second] = rank;
    for(int i=1; i<n; i++){
        if(arr[i].first == arr[i-1].first) idxArr[arr[i].second] = rank;
        else idxArr[arr[i].second] = ++rank;
    }

    segment.resize(4*(rank+1),0);
    long long count = 0;    
    for(int i=0; i<n; i++){
        count += find(1,0,rank,idxArr[i]+1,rank); // 자신보다 큰 숫자들의 누적합 수
        update(1,0,rank,idxArr[i]);  
    }
    cout << count;  
}