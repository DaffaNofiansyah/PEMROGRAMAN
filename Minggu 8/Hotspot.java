import java.util.*;

class Titik
{
    private int x, y;

    public Titik(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
    public void getTitik()
    {
        System.out.print("(" + this.x + "," + this.y + ")");
    }
    public int getx()
    {
        return this.x;
    }
    public int gety()
    {
        return this.y;
    }
};



public class Hotspot
{
    public static void main(String[] args)
    {
        int i, j, n, x, y;
        ArrayList<Titik> Hotspot = new ArrayList<Titik>();
        Scanner input = new Scanner(System.in);
        n = input.nextInt();

        //input
        for(i = 0; i < n; i++)
        {
            x = input.nextInt();
            y = input.nextInt();
            Hotspot.add(new Titik(x, y));
        }


        for (i = 0; i < Hotspot.size(); i++)
        {
            for (j = i+1; j < Hotspot.size(); j++)
            {
                if (Hotspot.get(i).getx() == Hotspot.get(j).getx() && Hotspot.get(i).gety() == Hotspot.get(j).gety())
                {
                    Hotspot.remove(j);
                    j--;
                }
            }
        }

        Collections.sort(Hotspot, new Comparator<Titik>() {
            @Override
            public int compare(Titik o1, Titik o2)
            {
                if (o1.getx() < o2.getx())
                {
                    return 1;
                }
                else if (o1.getx() == o2.getx())
                {
                    if (o1.gety() < o2.gety())
                    {
                        return 1;
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }
            }
        });

        //print
        System.out.println(Hotspot.size());
        for (i = 0; i < Hotspot.size(); i++)
        {
            if (Hotspot.get(i).gety() > 0)
            {
                Hotspot.get(i).getTitik();
            }   
        }
        input.close();
    }

}