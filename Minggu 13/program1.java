import java.util.*;

interface AritmatikaDasar
{
    double tambah(double a);
    double kurang(double a);
    double kali(double a);
    double bagi(double a);
}

interface AritmatikaLanjut
{
    double akarKuadrat();
    double pangkat(double a);
}

interface KalkulatorSaintifik extends AritmatikaDasar, AritmatikaLanjut
{
    double clear();
}

class Kalkulator implements KalkulatorSaintifik
{
    double currentValue = 0;

    public double tambah(double a)
    {
        return this.currentValue += a;
    }

    public double kurang(double a)
    {
        return this.currentValue -= a;
    }

    public double kali(double a)
    {
        return this.currentValue *= a;
    }

    public double bagi(double a)
    {
        return this.currentValue /= a;
    }

    public double akarKuadrat()
    {
        return this.currentValue = Math.sqrt(this.currentValue);
    }

    public double pangkat(double a)
    {
        return this.currentValue = Math.pow(this.currentValue, a);
    }

    public double clear()
    {
        return this.currentValue = 0;
    }
}




public class program1
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        Kalkulator kalkulator = new Kalkulator();
        String command = "";
        while (!command.equals("~"))
        {
            command = input.next();
            if (command.equals("+"))
            {
                double a = input.nextDouble();
                System.out.printf("%.2f\n", kalkulator.tambah(a));
            }
            else if (command.equals("-"))
            {
                double a = input.nextDouble();
                System.out.printf("%.2f\n", kalkulator.kurang(a));
            }
            else if (command.equals("*"))
            {
                double a = input.nextDouble();
                System.out.printf("%.2f\n", kalkulator.kali(a));
            }
            else if (command.equals("/"))
            {
                double a = input.nextDouble();
                System.out.printf("%.2f\n", kalkulator.bagi(a));
            }
            else if (command.equals("#"))
            {
                System.out.printf("%.2f\n", kalkulator.akarKuadrat());
            }
            else if (command.equals("^"))
            {
                double a = input.nextDouble();
                System.out.printf("%.2f\n", kalkulator.pangkat(a));
            }
            else if (command.equals("C"))
            {
                System.out.printf("%.2f\n", kalkulator.clear());   
            }
        }
        input.close();
    }
}