package first;
import java.util.*;


class bil
{
    private int a, b, c;
    public bil() { a = b = 0; c = 1; }
    public int fpb(int b1, int c1)
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
    public void simplify()
    {
        int t;
        a = a + b/c;
        b = b%c;
        t = fpb(b,c);
        b = b/t;
        c = c/t;    
    }
    public void set (int a1, int b1, int c1) 
    { 
        a = a1; 
        b = b1; 
        c = c1;
        simplify();
    }

    public bil add (bil p)
    {
        bil temp = new bil();
        temp.a = a + p.a;
        temp.b = b*p.c + p.b*c;
        temp.c = c * p.c;
        temp.simplify();
        return temp;
    }
    
    public bil mul (bil p)
    {
        int t;
        bil temp = new bil();
        temp.b = (a*c + b) * (p.a*p.c + p.b);
        temp.c = c*p.c;
        temp.a = temp.b/temp.c;
        temp.b = temp.b%temp.c;
        t = fpb(temp.b,temp.c);
        temp.b = temp.b/t;
        temp.c = temp.c/t;
        return temp;
    }

    public void inc() { a++; }
    public void dec() { a--; }

    public void print()
    {
        if (a == 0)
        {
            if (b == 0)
            {
                System.out.println("0");
            }
            else
            {
                System.out.println(b + "/" + c);
            }
        }
        else
        {
            if (b == 0)
            {
                System.out.println(a);
            }
            else
            {
                System.out.println(a + " " + b + "/" + c);
            }
        }
    }
};
