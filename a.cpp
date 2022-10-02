#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Base class
class Shape {
public:
    // pure virtual function providing interface framework.
    virtual int getArea() = 0;
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

protected:
    int width;
    int height;
};

// Derived classes
class Rectangle: public Shape {
public:
    int getArea() {
        return (width * height);
    }
};

class Triangle: public Shape {
public:
    int getArea() {
        return (width * height)/2;
    }
};

int main(void) {

//    char * nazwisko = new char[1000];
//    char * abc = new char;
//    cout << (long long) abc << " " << (long long) nazwisko << endl;
//
//    cin >> nazwisko;
//    *abc = ' ';
//    cout << nazwisko << endl;
//



//    char c;             // stack       // 1B - stack
//    char* c = new char;  // heap        // 8B - stack, 1 - heap
////    char* c;                           // 8B - stack
//    cin >> *c;



    vector<unique_ptr<Shape>> V;
    {
//        Rectangle Rect;
//        Triangle Tri;
//
//        Rect.setWidth(5);
//        Rect.setHeight(7);
//        Tri.setWidth(5);
//        Tri.setHeight(7);

        V.emplace_back(new Rectangle());
        V.emplace_back(new Triangle());
    }
//    unique_ptr<Shape> x(new Rectangle());
    shared_ptr<Shape> x(nullptr);
    x = std::make_shared<Rectangle>();

    cout << V.size() << endl;
    for(auto &i: V)
        cout << "Total Area: " << i->getArea() << endl;

    return 0;
}