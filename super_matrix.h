#ifndef DOTS_SUPER_MATRIX_H
#define DOTS_SUPER_MATRIX_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>

class Matrix{
    int n, m;
    vector<vector<T> > matr;
public:
    Matrix(vector<vector<T> >&);
    Matrix(int, int);
    Matrix operator+(Matrix&);
    Matrix operator*(int);
    Matrix operator*(Matrix&);
    Matrix pow(int);
    vector<T>& operator[](int i){
        return matr[i];
    }
    Matrix trans();
    template<typename Type> friend istream& operator>>(istream&, Matrix<Type>&);
    template<typename Type> friend ostream& operator<<(ostream&, Matrix<Type>&);
};

template<typename Type>
ostream &operator<<(ostream & out, Matrix<Type> &a) {
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < a.m; j++){
            out << a[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

template<typename Type>
istream &operator>>(istream &in, Matrix<Type> &a) {
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < a.m; j++){
            in >> a[i][j];
        }
    }
    return in;
}

#endif //DOTS_SUPER_MATRIX_H
