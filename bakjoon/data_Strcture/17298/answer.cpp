#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> nge(n,-1);
    stack<pair<int,int>> st;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        while(!st.empty() && st.top().first < arr[i]){
            nge[st.top().second] = arr[i];
            st.pop();
        }
        st.push({arr[i],i});
    }


    for(int i:nge){
        cout << i << ' ';
    }
}