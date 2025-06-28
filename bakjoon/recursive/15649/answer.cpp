#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<bool>& used,int m,vector<int>& sequence){
    if(m == 0) {
        for(auto i:sequence){
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for(auto i:used){
        if(used[i]) {
            used[i] = false;
            sequence.push_back(i+1);
            backtrack(used,m-1,sequence);
            used[i] = true;
            sequence.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<bool> used(n,1);
    vector<int> seq;
    backtrack(used,m,seq);
}