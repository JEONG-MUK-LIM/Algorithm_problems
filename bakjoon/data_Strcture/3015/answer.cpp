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
    int height;
    long long answer = 0;
    stack<pair<int,int>> st;
    for(int i=0; i<n; i++){
        cin >> height;
        int cnt = 1;
        while(!st.empty() && st.top().first <= height){
            if(st.top().first == height) cnt += st.top().second; 
            answer += st.top().second;
            st.pop();
        }
        if(!st.empty()) answer++;
        st.push({height,cnt});
    }
    cout << answer;
}