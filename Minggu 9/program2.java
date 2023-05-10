import java.util.*;
import java.io.*;


interface tanah
{
    public double keliling();
}

class Persegi implements tanah
{
    private double panjang, lebar;

    public Persegi(double panjang, double lebar)
    {
        this.panjang = panjang;
        this.lebar = lebar;
    }

    public double keliling()
    {
        return ( 2 * (panjang + lebar) );
    }
}

class Lingkaran implements tanah
{
    private double jari;

    public Lingkaran(double jari)
    {
        this.jari = jari;
    }

    public double keliling()
    {
        return ( ( 2 * 3.14 * jari ) );
    }
}


public class program2
{


    public static void main(String[] args)
    {
        ArrayList <Persegi> arr_persegi = new ArrayList<Persegi>();
        ArrayList <Lingkaran> arr_lingkaran = new ArrayList<Lingkaran>();
        Scanner input = new Scanner(System.in);
        Persegi temp_persegi;
        Lingkaran temp_lingkaran;
        int i, n, shape;
        double panjang, lebar, jari, total = 0, avg = 0, pagar = 0;
        n = input.nextInt();

        for (i = 0; i < n; i++)
        {
            shape = input.nextInt();
            if (shape == 0)
            {
                panjang = input.nextDouble();
                lebar = input.nextDouble();
                temp_persegi = new Persegi(panjang, lebar);
                total += temp_persegi.keliling();
                
                arr_persegi.add(temp_persegi);
            }
            else if (shape == 1)
            {
                jari = input.nextDouble();
                temp_lingkaran = new Lingkaran(jari);
                total += temp_lingkaran.keliling();
                arr_lingkaran.add(temp_lingkaran);
            }
        }
        avg = (double)total/(arr_persegi.size() + arr_lingkaran.size());

        for (i = 0; i < arr_persegi.size(); i++)
        {
            if (arr_persegi.get(i).keliling() > avg)
            {

                pagar += arr_persegi.get(i).keliling();
            }
        }

        for (i = 0; i < arr_lingkaran.size(); i++)
        {
            if (arr_lingkaran.get(i).keliling() > avg)
            {
                pagar += arr_lingkaran.get(i).keliling();
            }
        }

        System.out.printf("%.2f\n", pagar);
        input.close();

    }
}