#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(vector<vector<char>> &c, vector<vector<char>> &b){
    vector<vector<char>> temp(c.size(),vector<char> (c.size()));
    for (int k = 0; k < 3; k++) {
        bool f = 1;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                if (c[i][j] != b[i][j]){
                    f = 0;
                    break;
                }
            }
            if (f == 0){
                break;
            }
        }
        if (f){
            return true;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                temp[j][2 - i - 1] = c[i][j];
            }
        }
    }
    return false;
}

int main(){
    int k;
    cin >> k;
    vector<vector<vector<char>>> a(k, vector<vector<char>> (2, vector<char> (2)));
    for (int i = 0; i < k; i++){
        for (auto &j : a[i]){
            for (auto &u : j){
                cin >> u;
            }
        }
    }
    int n, m;
    cin >> n >> m;
    vector<vector<char>> p(n, vector<char> (m));
    for (auto &i : p){
        for (auto & j : i){
            cin >> j;
        }
    }
    for (int i = 0; i < n - 2; i += 2){
        for (int j = 0; j < m - 2; j += 2){
            vector<vector<char>> t(2, vector<char> (2));
            for (int u = i; u < i + 2; u++){
                for (int v = j; v < j + 2; v++){
                    t[u][v] =
                }
            }
            for (auto s : a){

            }
        }
    }
    return 0;
}
