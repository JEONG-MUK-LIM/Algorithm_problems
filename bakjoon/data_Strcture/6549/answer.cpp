#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        ull maxArea = 0;
        int i = 0;
        stack<int> st;
        while(i<n){
            if(st.empty() || arr[st.top()] <= arr[i]){
                st.push(i++);
            }
            else {
                ull height = arr[st.top()];
                st.pop();
                int width = st.empty() ?  i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
        }
        while(!st.empty()){
            ull height = arr[st.top()];
                st.pop();
                int width = st.empty() ?  i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
        }

        cout << maxArea << '\n';
    }
}