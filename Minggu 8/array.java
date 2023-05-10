import java.util.*;
import java.io.*;

class bilangan
{
    private ArrayList<Integer> arr = new ArrayList<Integer>();
    private int deleted = 0;
    public bilangan()
    {
        arr = new ArrayList<Integer>();
    }
    public void add(int x)
    {
        arr.add(x);
    }
    public void delete(int x)
    {
        arr.remove(x-1-deleted);
        deleted++;
    }
    public int getsize()
    {
        return arr.size();
    }
    public double getavg()
    {
        int sum = 0;
        int size = arr.size();
        double avg;
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                sum += arr.get(i);
            }
            avg = (double)sum/size;
            return avg;
        }
        else 
        {
            avg = -9.99;
            return avg;
        }
    }
}



public class array 
{
    public static void main(String[] args) 
    {
        bilangan arr_angka = new bilangan();
        double avg1 = 0, avg2 = 0;
        int size1 = 0, size2 = 0;
        Scanner input = new Scanner(System.in);
        int x = 0;
        while (x != -9)
        {
            x = input.nextInt();
            if (x != -9)
            {
                arr_angka.add(x);
            }
        }
        size1 = arr_angka.getsize();
        avg1 = arr_angka.getavg();
        
        x = 0;
        while (x != -9)
        {
            x = input.nextInt();
            if (x != -9)
            {
                arr_angka.delete(x);
            }
        }
        size2 = arr_angka.getsize();
        avg2 = arr_angka.getavg();
        System.out.printf("%d %d\n", size1, size2);
        System.out.printf("%.2f %.2f\n", avg1, avg2);
    }
}

