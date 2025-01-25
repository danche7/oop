#include <iostream>
#include <cmath>
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
    Complex(const Complex& y)
    {
        a = y.a;
        b = y.b;
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
    
    Complex& operator=(Complex orig)
    {
        this->a = orig.a;
        this->b = orig.b;
        
        return *this;
    }
    
    bool operator==(Complex y)
    {
        if(a==y.a and b==y.b)
        return true;
        
        return false;
    }
    
    bool operator!=(Complex y)
    {
        if(a!=y.a)
        return true;
        
        if(b!=y.b)
        return true;
        
        return false;
    }
    
    float operator!()
    {
        // modul
        
        float m = sqrt(a*a+b*b);
        return m;
    }
    
    Complex& operator++()
    {
        //prefix
        a++;
        return *this;
    }
    
    Complex& operator++(int)
    {
        //postfix
        a++;
        return *this;
    }
    
    Complex& operator--()
    {
        //prefix
        a--;
        return *this;
    }
    
    Complex& operator--(int)
    {
        //postfix
        a--;
        return *this;
    }
    
    float get_a()
    {
        return a;
    }
    
    float get_b()
    {
        return b;
    }
    
};

Complex operator+(Complex x, float k)
{
    Complex r(x.get_a() + k, x.get_b());
    return r;
}

Complex operator+(float k, Complex x)
{
    Complex r(x.get_a() + k, x.get_b());
    return r;
}

int main()
{
    Complex x(1,4);
    x.print();
    Complex l(x);
    
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
    
    Complex f(100,10), g(509,50);
    
    d = g/f;
    
    d.print();
    
    d=x;
    d.print();
    
    if(d==x)
    cout << true << "\n";
    
    if(d==y)
    cout << true;
    
    if(d!=y)
    cout << "da" << '\n';
    
    if(d!=x)
    cout << "lele";
    
    cout << !d << '\n';
    l.print();
    
    cout << '\n';
    
    x.print();
    x=++x;
    x.print();
    
    x=x++;
    x.print();
    
    x.print();
    x=--x;
    x.print();
    
    x=x--;
    x.print();
   
    d = x+5.3;
    d.print();
    
    d=5+x;
    d.print();
    
}