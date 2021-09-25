#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Point{
    int x, y;
public:
    Point(){x = 0; y = 0;}
    Point(int a, int b){x = a; y = b;}
    int Getx(){return x;}
    int Gety(){return y;}
    void Setx(int a){x = a;}
    void Sety(int a){y = a;}
    Point operator+(Point) const;
    Point operator-(Point) const;
    Point operator*(int) const;
    Point operator/(int) const;
    int operator*(Point) const;
    int operator^(Point) const;
    int sqrlen() const;
    double angle(Point b) const;
    bool operator==(Point b) const;
    bool operator!=(Point b);
    friend ostream& operator<<(ostream&, Point&);
    friend istream& operator>>(istream&, Point&);
};

Point Point::operator+(Point b) const {
    Point res = Point(x + b.Getx(), y + b.Gety());
    return res;
}

Point Point::operator-(Point b) const {
    return Point(x, y) + Point(-b.Getx(), -b.Gety());
}

Point Point::operator*(int k) const {
    return Point(x * k, y * k);
}

Point Point::operator/(int k) const {
    return Point(x / k, y / k);
}

int Point::operator*(Point b) const {
    return x * b.Getx() + y * b.Gety()  ;
}

int Point::operator^(Point b) const {
    return x * b.Gety() - y * b.Getx();
}

int Point::sqrlen() const {
    return x * x + y * y;
}

double Point::angle(Point b) const {
    return acos((*this * b) / (sqrt(this->sqrlen() * b.sqrlen())));
}

bool Point::operator==(Point b) const {
    if (x == b.Getx() && y == b.Gety()){
        return true;
    }else{
        return false;
    }
}

bool Point::operator!=(Point b) {
    if (*this == b){
        return false;
    }else{
        return true;
    }
}

ostream &operator<<(ostream & out, Point & a) {
    out << '(' << a.x << ", " << a.y << ')';
    return out;
}

istream &operator>>(istream & in, Point & a){
    in >> a.x >> a.y;
    return in;
}


int main() {
    //cout << "Enter vector\n.......";
    Point v;
    //cin >> v;
    //cout << "your vector v " << v << " squared length is " << v.sqrlen() << '\n';
    //cout << "Enter second vector\n.......";
    Point v1;
    //cin >> v1;
    //cout << "your vector v1 " << v1 << " squared length is " << v1.sqrlen() << '\n';
    while (true) {
        cout << "choose command:\nenter vector1\nenter vector2\nGetx 1\nGety 1\nGetx 2\nGety 2\nSetx 1\nSety 1\nSetx 2\nSety 2\nsum\nsub\nmultiply by int\ndivide by int\nscalar\nkosoe\nangle\nsquared length\nequal\nexit\nBy default vectors are (0, 0)\n";
        string c;
        cin >> c;
        if (c == "exit"){
            break;
        }else if (c == "equal") {
            if (v1 == v) {
                cout << "your vectors are equal\n";
            } else {
                cout << "your vectors aren't equal\n";
            }
        }else if (c == "sum")
        Point sum = v + v1;
        cout << "v + v1 = " << sum << '\n';
        Point sub = v - v1;
        cout << "v - v1 = " << sub << endl;
        int scalar = v * v1;
        cout << "(v, v1) = " << scalar << endl;
        int kos = v ^v1;
        cout << "<v, v1> = " << kos << endl;
        double ang = v.angle(v1);
        cout << "angle between v and v1 is " << ang << endl;
        cout << "choose a number to multiply vector v with it\n";
        int k;
        cin >> k;
        Point mul = v * k;
        cout << "v * k = " << mul << endl;
        cout << "choose a number to divide vector v1 with it\n";
        cin >> k;
        Point div = v / k;
        cout << "v / k = " << div << endl;
    }
    return 0;
}
