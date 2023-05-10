#include <bits/stdc++.h>
using namespace std;

class bil
{
    int a, b, c;
    public:
    bil() { a = b = 0; c = 1; }
    int fpb(int b1, int c1)
    {
        int t = b1 % c1;
        while(t != 0)
        {
            b1 = c1;
            c1 = t;
            t = b1 % c1;
        }
        return c1;
    }
    void simplify()
    {
        int t;
        a = a + b/c;
        b = b%c;
        t = fpb(b,c);
        b = b/t;
        c = c/t;    
    }
    void set (int a1, int b1, int c1) 
    { 
        a = a1; 
        b = b1; 
        c = c1;
        simplify();
    }

    bil operator+ (bil const &p)
    {
        bil temp;
        temp.a = a + p.a;
        temp.b = b*p.c + p.b*c;
        temp.c = c * p.c;
        temp.simplify();
        return temp;
    }
    
    bil operator* (bil const &p)
    {
        int t;
        bil temp;
        temp.b = (a*c + b) * (p.a*p.c + p.b);
        temp.c = c*p.c;
        temp.a = temp.b/temp.c;
        temp.b = temp.b%temp.c;
        t = fpb(temp.b,temp.c);
        temp.b = temp.b/t;
        temp.c = temp.c/t;
        return temp;
    }

    void inc() { a++; }
    void dec() { a--; }

    void print()
    {
        if ( b == 0 )
        {
            cout << a << endl;
        }
        else
        cout << a << " " << b << "/" << c << endl;
    }
};

int main()
{
    bil pecahan;
    int a, b, c;
    string cmd = "";
    while (cmd != "end")
    {
        cin >> cmd;
        if (cmd == "set")
        {
            cin >> a >> b >> c;
            pecahan.set(a,b,c);
        }
        if (cmd == "p")
        {
            pecahan.print();
        }
        if (cmd == "add")
        {
            bil temp1;
            cin >> a >> b >> c;
            temp1.set(a,b,c);
            pecahan = pecahan + temp1;
        }
        if (cmd == "mul")
        {
            bil temp1;
            cin >> a >> b >> c;
            temp1.set(a,b,c);
            pecahan = pecahan * temp1;
        }
        if (cmd == "inc")
        {
            pecahan.inc();
        }
        if (cmd == "dec")
        {
            pecahan.dec();
        }
    }
}