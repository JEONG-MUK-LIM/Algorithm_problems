#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int build(vector<int>& arr, vector<int>& segment, int node, int start,int end){
    if(start == end) return segment[node] = start;
    int mid = (start+end)/2;
    int left = build(arr,segment,node*2, start , mid);
    int right = build(arr,segment,node*2+1, mid + 1,end);
    return segment[node] = (arr[left] < arr[right]) ? left : right;
}

int findMin(vector<int>& arr, vector<int>& segment,int node, int start,int end,int l,int r){
    if(r < start || l > end) return -1;
    if(l<= start && r>= end) return segment[node];
    int mid = (start + end) / 2;
    int left = findMin(arr,segment,node*2,start,mid,l,r);
    int right = findMin(arr,segment,node*2 + 1,mid + 1,end,l,r);
    if(left == -1) return right;
    if(right == -1) return left;
    return (arr[left] < arr[right]) ? left : right;
}

ull divCon(vector<int>& arr,vector<int>& segment,int l,int r){
    if(l > r) return 0;
    int n = arr.size();
    int idx = findMin(arr,segment,1,0,n-1,l,r);
    ull area = (ull)arr[idx]*(r-l+1);    
    ull left = divCon(arr,segment,l,idx-1);
    ull right = divCon(arr,segment,idx+1,r);
    return max(area,max(left,right));  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n,h;
        cin >> n;
        if(n == 0) break;
        vector<int> arr(n);
        vector<int> segment(4*n);

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        build(arr,segment,1,0,n-1);
        cout << divCon(arr,segment,0,n-1) << '\n';
    }
}