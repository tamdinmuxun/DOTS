#include <iostream>
#include "super_matrix.h"
#include "super_matrix.cpp"
#include <vector>
using namespace std;

template<typename T>

vector<Matrix<T>> gauss(Matrix<T> &a){
    Matrix<T> one(a.size(), a.size());
    for (int i = 0; i < one.size(); i++){
        for (int j = 0; j < one.size(); j++){
            if (i == j) one[i][j] = 1;
            else one[i][j] = 0;
        }
    }
    cout << one << '\n' << "-----------------\n";
    Matrix<T> c(a);
    for (int i = 0; i < c.size() ; i++){
        if (c[i][i] == 0){
            for (int k = 0; k < c.size(); k++){
                if (c[k][i] != 0){
                    c[i] = sum(c[i], c[k]);
                    one[i] = sum(one[i], one[k]);
                    //one[j] = sum(one[j], t);
//                    cout << c << '\n';
//                    cout << one << "\n------------------------------\n";
                    break;
                }
            }
            cout << "матрица вырожденная\n";
            exit(0);
        }
        for (int k = 0; k <= i; k++){
            for (int j = k + 1; j < c.size(); j++) {
                if (c[j][k] == 0) continue;
                vector<T> t(c[0].size(), -c[j][k] / c[k][k]);
                vector<T> t1(one.size(), -c[j][k] / c[k][k]);
                for (int u = 0; u < c[0].size(); u++) {
                    t[u] *= c[k][u];
                }
                for (int u = 0; u < one.size(); u++) {
                    t1[u] *= one[k][u];
                }
                c[j] = sum(c[j], t);
                one[j] = sum(one[j], t1);
//                cout << c << '\n';
//                cout << one << "\n------------------------------\n";
            }
        }
    }
    for (int i = c.size() - 1; i >= 0; i--){
        for (int j = i - 1; j >= 0; j--){
            vector<T> t(c[0].size(), -c[j][i] / c[i][i]);
            vector<T> t1(one.size(), -c[j][i] / c[i][i]);
            for (int k = 0; k < c[0].size(); k++){
                t[k] *= c[i][k];
            }
            for (int k = 0; k < one.size(); k++){
                t1[k] *= one[i][k];
            }
            c[j] = sum(c[j], t);
            //cout << c << '\n';
            one[j] = sum(one[j], t1);
//            cout << c << '\n';
//            cout << one << "\n------------------------------\n";
        }
    }
    for (int i = 0; i < one.size(); i++){
        c[i][c[0].size() - 1] /= c[i][i];
        for (auto &k : one[i]){
            k /= c[i][i];
        }
        c[i][i] = 1;

//        cout << c << '\n';
//        cout << one << "\n------------------------------\n";
    }
    vector<Matrix<T>> res{c, one};
    return res;
}

int main(){
    int n, m;
    cin >> n >> m; // тут m включая столбец с свободными членами
    Matrix<double> a(n, m);
    cin >> a;
    vector<Matrix<double>> res = gauss(a);
    Matrix<double> one = res[1];
    Matrix<double> c = res[0];
    vector<double> ans(c.size());
    for (int i = 0; i < c.size(); i++){
        ans[i] = c[i].back();
    }
    cout << one << '\n';
    for (auto i : ans){
        cout << i << ' ';
    }cout << "\n\n";
    Matrix<double> temp(a.size(), a.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++){
            temp[i][j] = a[i][j];
        }
    }
    Matrix<double> t1 = one * temp;
    cout << t1 << '\n';// << '\n' << t2 << '\n' << t3 << '\n';

}
/*
 3 4
 6 1 2 21
 4 -6 16 2
 3 8 1 2

 3 4
 2 10 -3 38
 -3 -24 5 -86
 1 3 -5 27
*/
