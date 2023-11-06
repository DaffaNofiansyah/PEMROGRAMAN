import java.util.*;



interface Answerable
{
    boolean cekJawaban(String jawaban);
}

class SoalIsian implements Answerable
{
    private Soal soal;
    class Soal 
    {
        private String[] soal;
        private String[] jawaban;

        public Soal(String[] soal, String[] jawaban)
        {
            this.soal = soal;
            this.jawaban = jawaban;
        }

        public String[] getSoal()
        {
            return this.soal;
        }

        public String[] getJawaban()
        {
            return this.jawaban;
        }

        public boolean cekJawaban(String jawaban)
        {
            for (int i = 0; i < this.jawaban.length; i++)
            {
                if (this.jawaban[i].equals(jawaban))
                {
                    return true;
                }
            }
            return false;
        }
}



class Ujian
{   
    private ArrayList<SoalIsian> soalIsian = new ArrayList<SoalIsian>();
    private int jumlahSoal;
    private int jumlahBenar = 0;

    public Ujian(int jumlahSoal)
    {
        this.jumlahSoal = jumlahSoal;
    }

    public void addSoal(String soal, String jawaban)
    {
        this.soalIsian.add(new SoalIsian(soal, jawaban));
    }    

    public void cekBenar(int m, String jawaban)
    {
        if (this.soalIsian.get(m).cekJawaban(jawaban))
        {
            this.jumlahBenar++;
        }
    }

    public double getNilai()
    {
        return (double) this.jumlahBenar / this.jumlahSoal * 100;
    }
}



public class program2
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        Ujian ujian = new Ujian(n);

        for (int i = 0; i < n; i++)
        {
            String soal = input.next();
            String jawaban = input.next();
            ujian.addSoal(soal, jawaban);
        }

        int m = input.nextInt();

        for (int i = 0; i < m; i++)
        {
            int nomorsoal = input.nextInt();
            String jawaban = input.next();
            ujian.cekBenar(nomorsoal, jawaban);
        }

        System.out.println(ujian.getNilai());
        input.close();
    }
}