#include <iostream>
#include <cmath>
#include <cstdlib>

const double PI = 3.14159;

class Point {
private:
   double x;
   double y;

public:
   Point() {
      x = y = 0.0;
   }
   Point(double x1, double y1) {
      x = x1;
	  y = y1;
	  std::cout<<"Ponto em ("<<x<<", "<<y<<")"<<std::endl;
   }
   double distanceTo(Point* p2) {
     return std::sqrt(((x - p2->x)*(x - p2->x))+((y - p2->y))*(y - p2->y));
   }
};

class Circle {
private:
   Point p;
   double r;

public:
   Circle() {
      p = Point();
      r = 0;
   }
   Circle(double x, double y, double r1){
	  p = Point(x, y);
	  r = r1;
   }
   double area() {
      return PI * r * r;
   }
   void setRadius(double radius){
   	  r = radius;
   }
   double distanceTo(Circle* c2) {	
		std::cout<<"A distancia entre os circulos c1 e c2 eh: "<<((p.distanceTo(&(c2->p))) - (r + c2->r))<<std::endl;
   }

};


int main() {
   Circle* c1 = new Circle(0,0,10);
   Circle* c2 = new Circle(50,0,10);

   c1->distanceTo(c2);
    
}
