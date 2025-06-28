#include <iostream>
#include <vector>

using namespace std;

bool rowNum[9][10]{0,};
bool colNum[9][10]{0,};
bool squareNum[9][10]{0,};

bool sudoku(int idx,vector<pair<int,int>>& zeroij, vector<vector<int>>& matrix){
    if (idx == zeroij.size()) return true;
    int i = zeroij[idx].first;
    int j = zeroij[idx].second;
    for(int k=1; k<10; k++){
        if(!rowNum[i][k] && !colNum[j][k] && !squareNum[i/3 + (j/3) * 3][k]){
            matrix[i][j] = k;
            rowNum[i][k] = true;
            colNum[j][k] = true;
            squareNum[i/3 + (j/3) * 3][k] = true;
            if(sudoku(idx+1,zeroij,matrix)) return true;
            matrix[i][j] = 0;
            rowNum[i][k] = false;
            colNum[j][k] = false;
            squareNum[i/3 + (j/3) * 3][k] = false;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> matrix(9,vector<int>(9));
    vector<pair<int,int>> zeroij;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) {
            zeroij.push_back({i,j});
            }
            else {
                rowNum[i][matrix[i][j]] = true;
                colNum[j][matrix[i][j]] = true;
                squareNum[i/3 + (j/3)*3][matrix[i][j]] = true;
            }
        }
    }
    if(sudoku(0,zeroij,matrix)){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}