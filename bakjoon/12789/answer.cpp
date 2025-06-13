#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> side;
    bool sad = 0;
    int num = 1;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x != num) {
            while(!side.empty()){
                if(side.top() == num){
                    side.pop();
                    num++;
                }
                else break;
            }
            side.push(x);
        }
        else num++;
    }
    while(!side.empty()){
        if(side.top() != num) {
            sad = 1;
            break;
        }
        else { 
            side.pop();
            num++;
        }
    }
    if(sad) cout << "Sad";
    else cout << "Nice";
}