#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void print(const vector<vector<int>>& m){
    for (const auto& i: m){
        for (auto f: i){
            cout << setw(3) << f;
        }
        cout << endl;
    }
    cout << endl;
}

void FloydAlg(vector<vector<int>> &m){
    for (int k = 0; k < m.size(); k++) {
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.size(); j++) {
                if (i != j && m[i][k] != -1 && m[k][j] != -1) {
                    if (m[i][j] == -1) {
                        m[i][j] = m[i][k] + m[k][j];
                    }
                    else m[i][j] = max(m[i][j], m[i][k] + m[k][j]);
                }
            }
        }
    }
}

int main() {
    int INF = -1;
    vector<vector<int>> adjMatrix = {
            {  0,   3,   5,   2, INF, INF, INF, INF, INF},
            {INF,   0, INF, INF,   4, INF, INF, INF, INF},
            {INF, INF,   0, INF, INF,   3, INF, INF, INF},
            {INF, INF, INF,   0, INF,   1, INF, INF, INF},
            {INF, INF, INF, INF,   0, INF,   4,   3, INF},
            {INF, INF, INF, INF, INF,   0, INF,   3, INF},
            {INF, INF, INF, INF, INF, INF,   0, INF,   2},
            {INF, INF, INF, INF, INF, INF, INF,   0,   5},
            {INF, INF, INF, INF, INF, INF, INF, INF,   0}
    };
    print(adjMatrix);
    FloydAlg(adjMatrix);
    print(adjMatrix);
}
