#include <iostream>
using namespace std;

class Complex
{
    float a=0,b=0;

    public:
    Complex()
    {
        a=1;
        b=0;
    }
    Complex(float a, float b)
    {
        this->a = a;
        this->b = b;
    }
    Complex(float a)
    {
        this->a = a;
        this->b = 0;
    }
    
    void print()
    {
        cout << a;
        if(b>=0)
        cout << " + " << b;
        else
        cout << " - " << -b;
        
        cout << "*i" << '\n';
    }

    Complex & operator-()
    {
        a = -a;
        b = -b;
        return *this;
    }

    Complex operator+(Complex y)
    {
        Complex r(a+y.a, b+y.b);
        return r;
    }
    
    Complex operator-(Complex y)
    {
        Complex r(a-y.a, b-y.b);
        return r;
    }
    
    Complex operator*(Complex y)
    {
        // a+bi * c+di = ac + adi + bci - bd
        // realen del = ac - bd , imaginaren del = i(ad+bc);
        Complex r(a*y.a-b*y.b, a*y.b+b*y.a);
        return r;
    }
    
    Complex& operator~()
    {
        // Konjugacija;
        b=-b;
        return *this;
    }
    
    Complex operator/(Complex y)
    {
        // delenje na kompleksni br a+bi , c+di so ovaa formula 
        // ac+bd + (bc-ad)i / (c^2 + d^2)
        
        Complex rez((a*y.a + b*y.b)/(y.a*y.a + y.b*y.b), (b*y.a - a*y.b)/(y.a*y.a + y.b*y.b));
        return rez;
    }
};

int main()
{
    Complex x(1,4);
    x.print();

    x = -x;
    x.print();
    Complex y(45,3);

    Complex r = x + y;

    r.print();
    
    Complex d = x-y;
    
    d.print();
    
    d=x*y;
    
    d.print();
    
    d=~d;
    d.print();
    
    Complex f(100,10), g(500,50);
    
    d = g/f;
    
    d.print();
}