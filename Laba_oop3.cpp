
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class Form {
public:
    Form() {
    }
    
};

class Point : public Form {
public:
    int x, y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point(Point &p) {
        x = p.x;
        y = p.y;
    }
    ~Point() {

    }

};

class Circle : public Form {
public:
    int x, y, rad;
    Circle() {
        x = 0;
        y = 0;
    }
    Circle(int x, int y, int rad) {
        this->x = x;
        this->y = y;
        this->rad = rad;
    }
    Circle(Circle& c) {
        x = c.x;
        y = c.y;
        rad = c.rad;
    }
    ~Circle() {

    }

};

class Storage {

};



int main()
{
    std::cout << "Hello World!\n";
}

