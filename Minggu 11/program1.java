import java.util.*;

interface iLingkaran
{
    public void setLingkaran(double diameter);
    public double luasLingkaran();
}

interface iSegiempat
{
    public void setSegiempat(double lebar, double tinggi);
    public double luasSegiempat();
}

interface iSilinder extends iLingkaran, iSegiempat
{
    public double volumeSilinder();
}

class Silinder implements iSilinder
{
    double diameter, tinggi, lebar;
    
    public void setLingkaran(double diameter)
    {
        this.diameter = diameter;
    }

    public double luasLingkaran()
    {
        return Math.PI * Math.pow(diameter/2, 2);
    }

    public void setSegiempat(double lebar, double tinggi)
    {
        this.tinggi = tinggi;
        this.lebar = lebar;
    }

    public double luasSegiempat()
    {
        return tinggi * lebar;
    }

    public double volumeSilinder()
    {
        return luasLingkaran() * tinggi;
    }

}

public class program1
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        ArrayList <Silinder> silinder = new ArrayList <Silinder>();
        int n, aboveavg=0;
        double diameter, tinggi, lebar, totalvolume=0, avgvolume;
        n = input.nextInt();
        
        for(int i=0; i<n; i++)
        {
            Silinder s = new Silinder();
            diameter = input.nextDouble();
            lebar = input.nextDouble();
            tinggi = input.nextDouble();
            s.setLingkaran(diameter);
            s.setSegiempat(lebar, tinggi);
            totalvolume += s.volumeSilinder();
            silinder.add(s);
        }

        avgvolume = totalvolume / n;

        for (Silinder s : silinder)
        {
            if(s.volumeSilinder() > avgvolume)
            {
                aboveavg++;
            }
        }

        System.out.printf("%.2f %d\n", avgvolume, aboveavg);
        input.close();
    }
}