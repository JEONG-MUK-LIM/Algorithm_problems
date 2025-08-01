#include <iostream>

using namespace std;

void star(int i, int j,int n){
    if((i/n) % 3 == 1 && (j/n) % 3 == 1){
        cout << ' ';
    }
    else {
        if(n == 1){
            cout << '*';
            return;
        }
        else star(i,j,n/3);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            star(i,j,n);
        }
        cout << '\n';
    }
}

