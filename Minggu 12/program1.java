import java.util.*;


abstract class Bilangan
{
    public abstract void tambah();
}

class DuaBilangan extends Bilangan
{
    double a, b;
    DuaBilangan(double a, double b)
    {
        this.a = a;
        this.b = b;
    }

    public void tambah()
    {
        System.out.printf("%.2f\n", this.a + this.b);
    }
}

class EmpatBilangan extends Bilangan
{
    int a, b;
    int p, q, r, s;
    EmpatBilangan(int p, int q, int r, int s)
    {
        this.p = p;
        this.q = q;
        this.r = r;
        this.s = s;
        this.a = p * s + q * r;
        this.b = q * s;
    }

    public int fpb(int a, int b)
    {
        while (b != 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public void tambah()
    {
        int t = fpb(this.a, this.b);
        this.a /= t;
        this.b /= t;
        System.out.printf("%d %d\n", this.a, this.b);
    }
}

public class program1
{
    public static void main(String[] args)
    {
        ArrayList<Bilangan> bil = new ArrayList<Bilangan>();
        int i, j, n, jenis, p, q, r, s;
        double a, b;
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        for (i = 0; i < n; i++)
        {
            jenis = input.nextInt();
            if (jenis == 1)
            {
                a = input.nextDouble();
                b = input.nextDouble();
                bil.add(new DuaBilangan(a, b));
            }

            else if (jenis == 2)
            {
                p = input.nextInt();
                q = input.nextInt();
                r = input.nextInt();
                s = input.nextInt();
                bil.add(new EmpatBilangan(p, q, r, s));
            }
        }

        i = input.nextInt();
        j = input.nextInt();

        for (i--; i < j; i++)
        {
            bil.get(i).tambah();
        }
        input.close();
    }
}