#include <iostream>
#include <string>

using namespace std ; 
class Shape 
{
    protected : 
    double width ; 
    double height ; 
    public : 
    Shape() : width(0),height(0) {} 
    Shape(double w,double h) :   width{w},height{h} {}
        
    
    double get_width() {return width ;}
    double get_height() {return height ; }
         
};
class Triangle : public Shape 
{
    public : 
        Triangle(double w,double h ) : Shape{w,h} {}
        double area()
        {
            double surface = (width*height)/2 ; 
            return surface ; 
        }


} ;
class Rectangle : public Shape 
{
    public : 
        Rectangle(double w,double h ) : Shape{w,h} {}
        double area()
        {
            double surface = (width*height) ; 
            return surface ; 
        }


} ;

int main()
{
    Triangle T1 {4.2,10.8}; 
    cout << T1.area() << endl;
    Rectangle R1{2.2,5.0} ;
    cout<< R1.area() ; 
    return 0 ; 
}
