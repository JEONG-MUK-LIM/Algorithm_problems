#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> last_year(n);
        vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
        vector<int> indegree(n+1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> last_year[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                graph[last_year[i]][last_year[j]] = true;
                indegree[last_year[j]]++;
            }
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            if (graph[a][b]) {
                graph[a][b] = false;
                graph[b][a] = true;
                indegree[b]--;
                indegree[a]++;
            } else {
                graph[b][a] = false;
                graph[a][b] = true;
                indegree[a]--;
                indegree[b]++;
            }
        }

        queue<int> q;
        vector<int> result;
        bool certain = true, cycle = false;

        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        for (int i = 0; i < n; ++i) {
            if (q.empty()) {
                cycle = true;
                break;
            }
            if (q.size() > 1) {
                certain = false;
                break;
            }
            int now = q.front();
            q.pop();
            result.push_back(now);
            for (int j = 1; j <= n; ++j) {
                if (graph[now][j]) {
                    indegree[j]--;
                    if (indegree[j] == 0)
                        q.push(j);
                }
            }
        }

        if (cycle) cout << "IMPOSSIBLE\n";
        else if (!certain) cout << "?\n";
        else {
            for (int i = 0; i < n; ++i)
                cout << result[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}