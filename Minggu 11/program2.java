import java.util.*;


interface Shape2D
{
    public void set(int n, double x[], double y[]);
    public void print();
    public void keliling();
}

class Poligon implements Shape2D
{
    int n;
    double x[], y[];
    
    public void set( int n , double x[] , double y[])
    {
        this.n = n;
        this.x = x;
        this.y = y;
    }
    public void print()
    {
        System.out.printf("[%.2f,%.2f]-[%.2f,%.2f]\n", x[0], y[0], x[n-1], y[n-1]);
    }

    public void keliling()
    {
        double total = 0;
        for (int i=0; i<n-1; i++)
        {
            total += Math.sqrt(Math.pow(x[i]-x[i+1], 2) + Math.pow(y[i]-y[i+1], 2));
        }
        total += Math.sqrt(Math.pow(x[n-1]-x[0], 2) + Math.pow(y[n-1]-y[0], 2));
        System.out.printf("%.2f\n", total);
    }
}







public class program2
{
    public static void main(String[] args)
    {
        Poligon poligon = new Poligon();
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        if (n > 3)
        {
            double x[] = new double[n];
            double y[] = new double[n];
            
            for (int i=0; i<n; i++)
            {
                x[i] = input.nextDouble();
                y[i] = input.nextDouble();
            }
    
            poligon.set(n, x, y);
            poligon.print();
            poligon.keliling();
        }

    }
}