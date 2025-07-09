#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int find(int a,vector<int>& setId){
    if(setId[a] == a) return a;
    return setId[a] = find(setId[a],setId);
}   
int unite(int a,int b,vector<int>& setId,vector<int>& count){
    a = find(a,setId);
    b = find(b,setId);
    if(a == b) return count[a];
    if(count[a] > count[b]){
        setId[b] = a;
        count[a] += count[b];
        return count[a];
    } 
    else {
        setId[a] = b;
        count[b] += count[a];
        return count[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int f;
        cin >> f;
        unordered_map<string,int> hash;
        int idx = 0;
        vector<int> setId(2*f+1);
        vector<int> count(2*f+1,1);
        for(int i=0; i<=2*f; i++){
            setId[i] = i;
        }
        for(int i=0; i<f; i++){
            string str1,str2;
            cin >> str1 >> str2;
            if(hash.find(str1) == hash.end()) {
                hash.insert({str1,idx++ });
            }
            if(hash.find(str2) == hash.end()) {
                hash.insert({str2,idx++});
            }
            cout << unite(hash[str1],hash[str2],setId,count) << '\n';
        }       
    }       
}