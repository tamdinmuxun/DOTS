#include <iostream>
#include "super_matrix.h"
#include "super_matrix.cpp"
#include <string>

using namespace  std;

int main(){
    cout << "Choose matrix size\n";
    int n, m;
    cin >> n >> m;
    Matrix<int> a(n, m);
    cout << "cin matrix\n";
    cin >> a;
    cout << a;
    cout << "do u want to transpose matrix?\n";
    string ans;
    cin >> ans;
    if (ans == "yes"){
        Matrix<int> t = a.trans();
        cout << t << '\n';
    }
    cout << "do you want to multiply matrix by number?\n";
    cin >> ans;
    if (ans == "yes"){
        int k;
        cin >> k;
        Matrix<int> c = a * k;
        cout << c << '\n';
    }
    cout << "do you want to elevate matrix?\n";
    cin >> ans;
    if (ans == "yes"){
        try {
            int k;
            cin >> k;
            Matrix<int> c = a.pow(k);
            cout << c << '\n';
        }catch (char const* s){
            cerr << s << '\n';
        }
    }
    cout << "do you want to count opredelitel of matrix?\n";
    cin >> ans;
    if (ans == "yes"){
        try {
            cout << opr(a, 0) << '\n';
        }catch (char const* s){
            cerr << s << '\n';
        }
    }
    cout << "choose other matrix size\n";
    int k, l;
    cin >> k >> l;
    Matrix<int> b(k, l);
    cout << "cin matrix\n";
    cin >> b;
    cout << "do u want to transpose matrix?\n";
    cin >> ans;
    if (ans == "yes"){
        Matrix<int> t = b.trans();
        cout << t << '\n';
    }
    cout << "do you want to multiply matrix by number?\n";
    cin >> ans;
    if (ans == "yes"){
        int k;
        cin >> k;
        Matrix<int> c = b * k;
        cout << c << '\n';
    }
    cout << "do you want to elevate matrix?\n";
    cin >> ans;
    if (ans == "yes"){
        try {
            int k;
            cin >> k;
            Matrix<int> c = a.pow(k);
            cout << c << '\n';
        }catch (char const* s){
            cerr << s << '\n';
        }
    }
    cout << "do you want to count opredelitel of matrix?\n";
    cin >> ans;
    if (ans == "yes"){
        try {
            cout << opr(a, 0) << '\n';
        }catch (char const* s){
            cerr << s << '\n';
        }
    }
    cout << "do you want to sum matrixes?\n";
    cin >> ans;
    if (ans == "yes"){
        try {
            Matrix<int> c = a + b;
            cout << c << '\n';
        }catch (char const* s){
            cerr << s << '\n';
        }
    }

    cout << "do you want to multiply matrixes?\n";
    cin >> ans;
    if (ans == "yes"){
        try {
            Matrix<int> c = a * b;
            cout << c << '\n';
        }catch (string s){
            cerr << s + '\n';
        }
    }

}
