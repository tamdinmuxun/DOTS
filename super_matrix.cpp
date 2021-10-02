#include "super_matrix.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>

Matrix<T>:: Matrix(vector<vector<T> >& a){
    matr = a;
    n = a.size();
    m = a[0].size();
}

template<typename T>

Matrix<T> :: Matrix(int _n, int _m){
    n = _n;
    m = _m;
    vector<vector<T> > c(n, vector<T> (m));
    matr = c;
}
template<typename T>

Matrix<T> Matrix<T> ::operator+(Matrix<T> &a){
    if (a.n != n || a[0].size() != m){
        string s = "ERROR in addition! Matrixes' sizes are not equal";
        char const* res = s.c_str();
        throw res;
    }
    Matrix<T> c(matr);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            c[i][j] += a[i][j];
        }
    }
    return c;
}
template<typename T>

Matrix<T> Matrix<T> :: operator*(int k){
    Matrix<T> c(matr);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            c[i][j] *= k;
        }
    }
    return c;
}

template<typename T>

Matrix<T> Matrix<T> :: operator * (Matrix<T>& a){
    if (a.n != m){
        string s = "ERROR! cannot multiply matrix!";
        char const* res = s.c_str();
        throw res;
    }
    Matrix<T> c(n, a[0].size());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a[0].size(); j++){
            for (int k = 0; k < m; k++){
                c[i][j] += matr[i][k] * a[k][j];
            }
        }
    }
    return c;
}

template<typename T>

Matrix<T> Matrix<T> :: pow(int k){
    if (n != m){
        string s = "ERROR! Matrix is not squared!";
        char const* res = s.c_str();
        throw res;
    }
    if (k == 0){
        Matrix<T> one(n, m);
        for (int i = 0; i < n; i++){
            one[i][i] = 1;
        }
        return one;
    }else if (k % 2 == 0){
        Matrix<T> a = pow(k / 2);
        return a * a;
    }else{
        Matrix<T> a = *this;
        Matrix<T> b = pow(k - 1);
        Matrix<T> c = a * b;
        return c;
    }
}

template<typename T>

Matrix<T> Matrix<T> :: trans(){
    Matrix<T> res(m, n);
    for (int i = 0; i < n; i++){
        for (int j = 0;  j < m; j++){
            res[j][i] = matr[i][j];
        }
    }
    return res;
}
template<typename T>
long long opr(Matrix<T> &a, int i){
    long long answer = 0;
    if (a.size() != a[0].size()){
        string s = "ERROR! matrix is not squared";
        char const* c = s.c_str();
        throw c;
    }
    if (a.size() == a[0].size() && a.size() == 1){
        return a[0][0];
    }
    for (int j = 0; j < a[0].size(); j++){
        Matrix<T> c(a.size() - 1, a[0].size() - 1);
        for (int k = 0; k < i; k++){
            for (int u = 0; u < j; u++){
                c[k][u] = a[k][u];
            }
            for (int u = j + 1; u < a[0].size(); u++){
                c[k][u - 1] = a[k][u];
            }
        }
        for (int k = i + 1; k < a.size(); k++){
            for (int u = 0; u < j; u++){
                c[k - 1][u] = a[k][u];
            }
            for (int u = j + 1; u < a[0].size(); u++){
                c[k - 1][u - 1] = a[k][u];
            }
        }
        cout << c;
        if ((j + i) % 2 == 0){
            long long temp = opr(c, 0);
            answer += a[i][j] * temp;
            cout << temp << '*' << a[i][j] << '=' << temp * a[i][j] << '\n';
        }else{
            long long temp = opr(c, 0);
            answer -= a[i][j] * temp;
            cout << temp << '*' << a[i][j] << '=' << temp * a[i][j] << '\n';        }
    }
    return answer;
}
//
//template<typename T>
//
//typename Matrix<T>:: istream& operator>>(istream& in, Matrix<T>& a){
//    for (int i = 0; i < a.n; i++){
//        for (int j = 0; j < a[0].size(); j++){
//            in >> a[i][j];
//        }
//    }
//    return in;
//}
//template <typename T>
//
//Matrix<T> Matrix<T>:: ostream& operator<<(ostream& out, Matrix<T>& b){
//    for (int i = 0; i < b.n; i++){
//        for (int j = 0; j < b[0].size(); j++){
//            out << b[i][j];
//            out << ' ';
//        }
//        out << '\n';
//    }
//    return out;
//}