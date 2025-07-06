#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> change(int cur){
    vector<int> arr(4,0);
    arr[0] = (cur / 1000) % 10; 
    arr[1] = (cur / 100) % 10;
    arr[2] = (cur / 10) % 10;
    arr[3] = cur % 10;
    return arr;
}

int LeftShift(int cur){
    vector<int> arr = change(cur);
    int result = 0;
    result += arr[0];
    result += arr[3]*10;
    result += arr[2]*100;
    result += arr[1]*1000;
    return result;
}
int RightShift(int cur){
    vector<int> arr = change(cur);
    int result = 0;
    result += arr[2];
    result += arr[1]*10;
    result += arr[0]*100;
    result += arr[3]*1000;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int x,y;
        cin >> x >> y;
        
        queue<int> q;
        q.push(x);
        vector<int> prev(10000,-1);
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if(cur == y) {
                string result = "";
                while(cur != x){
                    int temp = cur;
                    cur = prev[cur];
                    int next[4] = {(2*cur) % 10000,((cur-1)+10000)% 10000,LeftShift(cur),RightShift(cur)};
                    char nextC[4] = {'D','S','L','R'};
                    for(int i=0; i<4; i++){
                        if(temp == next[i]) {
                            result.push_back(nextC[i]);
                            break;
                        }
                    }
                }
                for(int i=result.size()-1; i>=0; i--){
                    cout << result[i];
                }
                cout << '\n';
                break;
            }
            int next[4] = {(2*cur) % 10000,((cur-1)+10000)% 10000,LeftShift(cur),RightShift(cur)};
            for(int i=0; i<4; i++){
                if(prev[next[i]] == -1){
                    q.push(next[i]);
                    prev[next[i]] = cur;
                }
            }
        }        
    }
}