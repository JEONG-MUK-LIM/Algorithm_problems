#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr;
vector<int> minSegment;
vector<int> maxSegment;

int build(int node,int start,int end,bool isMax){
    if(start == end){
        if(isMax) return maxSegment[node] = arr[start];
        else return minSegment[node] = arr[start];
    }
    int mid = (start + end)/2;
    if(isMax)
        return maxSegment[node] = max(build(node*2, start,mid,isMax),build(node*2+1,mid+1,end,isMax));
    else  return minSegment[node] = min(build(node*2, start,mid,isMax),build(node*2+1,mid+1,end,isMax));
}

int find(int node,int start,int end,int l,int r,bool isMax){
    if(l > end || r < start) return -1;
    if(l <= start && end <= r) {
        if(isMax) return maxSegment[node];
        else return minSegment[node];
    }
    int mid = (start+end)/2;
    int left = find(node*2,start,mid,l,r,isMax);
    int right = find(node*2 + 1, mid+1, end, l,r,isMax);
    if(left == -1) return right;
    if(right == -1) return left;

    if(isMax) return max(left,right);
    else return min(left,right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;
    arr.resize(n);
    maxSegment.resize(4*n);
    minSegment.resize(4*n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    build(1,0,n-1,true);
    build(1,0,n-1,false);

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        cout << find(1,0,n-1,a-1,b-1,0) << ' ' << find(1,0,n-1,a-1,b-1,1) << '\n';
    }
}