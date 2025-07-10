#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n+1,vector<int>(n+1,1e9));
    vector<vector<int>> record(n+1,vector<int>(n+1,-1));

    for(int i=1; i<=n; i++){
        matrix[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(matrix[a][b] > c){ // 중복가능한 입력
            matrix[a][b] = c;
            record[a][b] = b;
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                if(tmp > matrix[i][j]) record[i][j] = record[i][k]; 
                //누적된 결과인 matrix[i][j]를 이용했으니 다음에 경유하는 k는 맨처음 경유하는 노드의 번호이다.
            }   
        }   
    }
    auto get_path = [&](int u,int v){
        vector<int> path;
        if(record[u][v] == -1) return path;
        path.push_back(u);
        while(u!=v){
            u = record[u][v];
            path.push_back(u);
        }
        return path;
    };
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(matrix[i][j] < 1e9) cout << matrix[i][j];
            else cout << 0;
            cout << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vector<int> path = get_path(i,j);
            if(path.size() == 0){
                cout << 0 << '\n';
                continue;
            }
            else {
                cout << path.size() << ' ';
                for(int i:path) cout << i << ' ';
                cout << '\n';
            }
        }
    }
}