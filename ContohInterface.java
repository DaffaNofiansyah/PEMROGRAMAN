import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

interface Driveable
{
  void tambahKecepatan();
  // void kurangiKecepatan();
  // void belokKanan();
  // void belokKiri();  
}

interface Printable{
  void print();
}

abstract class Kendaraan implements Printable, Driveable
{
  public String nama;
  
  @Override
  public abstract void print();

  @Override
  public void tambahKecepatan(){
    System.out.println("Kendaraan " + nama + " meningkatkan kecepatannyaa!!");
  }
}

abstract class HewanTunggangan implements Printable, Driveable
{
  public String nama;
 
  @Override
  public abstract void print();

  @Override
  public void tambahKecepatan(){
    System.out.println("Hewan tunggangan " + nama + " mempercepat langkahnya!!");
  }
}

class Motor extends Kendaraan
{
  Motor(String nama)
  {
    this.nama = nama;
  }

  @Override
  public void print(){
    System.out.println("Saya naik motor: " + nama);
  }
}

class Mobil extends Kendaraan
{

  Mobil(String nama)
  {
    this.nama = nama;
  }

  @Override
  public void print()
  {
    System.out.println("Saya naik mobil: " + nama);
  }
}

class Kuda extends HewanTunggangan
{
  Kuda(String nama)
  {
    this.nama = nama;
  }

  @Override
  public void print(){
    System.out.println("Saya naik kuda: " + nama);
  }
}

class Banteng extends HewanTunggangan
{
  Banteng(String nama)
  {
    this.nama = nama;
  }

  @Override
  public void print(){
    System.out.println("Saya naik banteng: " + nama);
  }
}


public class ContohInterface
{
  public static void main(String args[]){
    Mobil mobil = new Mobil("Corola");
    Motor motor = new Motor("Supra");
    Kuda kuda = new Kuda("Poni");
    Banteng banteng = new Banteng("Lamborghini");

    ArrayList<Printable> partisipan = new ArrayList<Printable>();
    partisipan.add(mobil);
    partisipan.add(motor);
    partisipan.add(kuda);
    partisipan.add(banteng);
    ArrayList<Mobil> mobils = new ArrayList<Mobil>();
    while(true){
      Scanner sc = new Scanner(System.in);
      String temp = sc.next();
      mobils.add(new Mobil(temp));
    }
    for(Printable p : partisipan){
      p.print();
    }

    ArrayList<Driveable> driveables = new ArrayList<Driveable>();
    driveables.add(mobil);
    driveables.add(motor);
    driveables.add(kuda);
    driveables.add(banteng);

    for(Driveable d : driveables){
      d.tambahKecepatan();
    }

  }
}