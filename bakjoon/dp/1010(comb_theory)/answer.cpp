#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        ull ans = 1;

        for(int i=0; i<n; i++){
            ans *= m-i;
            ans /= (i+1);
        }
        cout << ans << '\n';
    }
}       