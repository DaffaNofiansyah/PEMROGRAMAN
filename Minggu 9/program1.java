import java.util.*;
import java.io.*;

class Pegawai {
    protected String id;
    protected int usia;
    protected int tipe;
    protected int income;

    public Pegawai()
    {
        id = "";
        usia = income = 0;
        tipe = 1;
    }

    public void set(String pid, int u, int t) 
    {
        id = pid;
        usia = u;
        tipe = t;
    }

    public String getID() 
    {
        return id;
    }

    public void show() 
    {
        System.out.printf("%s %d %d\n", id, tipe, income);
    }
};


class Tetap extends Pegawai 
{
    private int lembur;

    public Tetap() 
    {
        id = "";
        usia = income = lembur = 0;
        tipe = 1;
    }

    public void setIncome(int i) 
    {
        income = i;
    }

    public void setLembur(int l) 
    {
        lembur = l;
        income += lembur;
    }
};

class Harian extends Pegawai
{
    public Harian()
    {
        id = "";
        income = 0;
        tipe = 2;
    }
    public void setIncome (int i)
    {
        income = i;
    }
};

public class program1 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        ArrayList<Tetap> arr_tetap = new ArrayList<Tetap>();
        ArrayList<Harian> arr_harian = new ArrayList<Harian>();
        int i, j, n, usia, tipe, income, temp;
        String id, cmd = "";
        Tetap temp_tetap;
        Harian temp_harian;

        n = input.nextInt();
        for ( i = 0; i < n; i++)
        {
            id = input.next();
            usia = input.nextInt();
            tipe = input.nextInt();
            if ( tipe == 1)
            {
                income = input.nextInt();
                temp_tetap = new Tetap();
                temp_tetap.set(id, usia, tipe);
                temp_tetap.setIncome(income);
                arr_tetap.add(temp_tetap);
            }
            else if ( tipe == 2)
            {
                temp_harian = new Harian();
                temp_harian.set(id, usia, tipe);
                arr_harian.add(temp_harian);
            }

            while (cmd.equals("END"))
            {
                cmd = input.next();
                if ( cmd.equals("END"))
                {
                    income = input.nextInt();
                    for (i = 0; i < arr_tetap.size(); i++)
                    {
                        if (arr_tetap.get(i).getID().equals(cmd))
                        {
                            arr_tetap.get(i).setLembur(income);
                        }
                    }
                    for (i = 0; i < arr_harian.size(); i++)
                    {
                        if (arr_harian.get(i).getID().equals(cmd))
                        {
                            arr_harian.get(i).setIncome(income);
                        }
                    }
                }
            }

            System.out.println(arr_harian.size() + arr_tetap.size());

            //print
            for (i = 0; i < arr_tetap.size(); i++)
            {
                arr_tetap.get(i).show();
            }

            for (i = 0; i < arr_harian.size(); i++)
            {
                arr_harian.get(i).show();
            }

        }
        
    }
}