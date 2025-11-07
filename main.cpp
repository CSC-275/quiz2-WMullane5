#include <iostream>
#include <cmath>

class Circle {
// complete declaration for Circle class here
    private:
    double m_radius = 0;
    protected:
    const double m_pi = M_PI;
    double m_area = 0;
     void calcArea(double radius) {
        m_area = m_pi * pow(radius, 2);}

public:
Circle() {
m_radius = 1;
m_area = m_pi;}

Circle(double radius) {
m_radius = radius;
calcArea(m_radius);
}


virtual void display() {
std::cout <<"The area of a circle with...";
std::cout <<"\na radius of " <<m_radius << " inches";
std::cout <<"\nhas a area of " <<m_area << " square inches\n\n";}


};

class Cylinder : public Circle {
// complete declaration for Cylinder class here
private:
double m_height = 0;
double m_volume = 0;

void calcVolume(double radius, double height) {
    calcArea(radius);
    m_volume = m_area * height;
}
public:
    Cylinder();
    Cylinder(double r, double h):Circle(r){
        m_height = h;
        calcVolume(r, h);
    }
    void display() {
        Circle::display();
        std::cout <<"AND the volume of cylinder with...";
        std::cout<<"\na circular end area of " << Circle::m_area << " square inches";
        std::cout<<"\nand a height of "<< m_height << " inches";
        std::cout<<"\nhas a volume of "<< m_volume << " cubic inches\n\n";
    }
};

int main() {
    Circle c1, c2(5.25);
    c1.display();
    c2.display();
    Circle *cl1 = new Cylinder(3.5,8.65);
    cl1->display();
    return 0;
}
