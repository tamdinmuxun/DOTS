#include <iostream>
#include <cmath>

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
    Point res = Point(max(x, b.Getx()), max(y, b.Gety()));
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
    return x * b.Gety() + y * b.Getx()  ;
}

int Point::operator^(Point b) const {
    return x * b.Gety() - y * b.Getx();
}

int Point::sqrlen() const {
    return x * x + y * y;
}

double Point::angle(Point b) const {
    return asin((*this ^ b) / (sqrt(this->sqrlen() * b.sqrlen())));
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
    cout << "Enter vector\n.......";
    Point v;
    cin >> v;
    cout << "Enter second vector\n.......";
    Point v1;
    cin >> v1;

    return 0;
}
