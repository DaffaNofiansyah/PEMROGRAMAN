import java.util.Scanner;
import java.lang.*;

interface AD {
    double tambah(double a, double b);

    double kurang(double a, double b);

    double kali(double a, double b);

    double bagi(double a, double b);

}

interface AL {
    double akarKuadrat(double a);

    double pangkat(double a, double b);
}

interface iKS extends AD, AL {
    double clear();
}

class KS implements iKS {
    double curVal;

    public KS() {
        curVal = 0.0;
    }

    public double tambah(double a, double b) {
        return curVal += b;
    }

    public double kurang(double a, double b) {
        return curVal -= b;
    }

    public double kali(double a, double b) {
        return curVal *= b;
    }

    public double bagi(double a, double b) {
        return curVal /= b;
    }

    public double akarKuadrat(double a) {
        return curVal = Math.sqrt(curVal);
    }

    public double pangkat(double a, double b) {
        return curVal = Math.pow(curVal, b);
    }

    public double clear() {
        curVal = 0;
        return curVal;
    }
}

public class programtes {
    public static void main(String[] args){
        KS obj = new KS(); 
        Scanner inp = new Scanner(System.in);
        String opr = inp.next(); 
        while(!opr.equals("~")){
            if(opr.equals("+")){
                double x = inp.nextDouble(); 
                System.out.printf("%.2f\n", obj.tambah(0, x)); 
            }
            else if(opr.equals("-")){
                double x = inp.nextDouble(); 
                System.out.printf("%.2f\n", obj.kurang(0, x));
            }
            else if(opr.equals("*")){
                double x = inp.nextDouble(); 
                System.out.printf("%.2f\n", obj.kali(0, x));
            }
            else if(opr.equals("/")){
                double x = inp.nextDouble(); 
                System.out.printf("%.2f\n", obj.bagi(0, x));
            } 
            else if(opr.equals("^")){
                double x = inp.nextDouble(); 
                System.out.printf("%.2f\n", obj.pangkat(0, x));
            }
            else if(opr.equals("#")){
                System.out.printf("%.2f\n", obj.akarKuadrat(0));
            }
            else if(opr.equals("C")){
                System.out.printf("%.2f\n", obj.clear());
            }
            opr = inp.next();
        }
    }
}
