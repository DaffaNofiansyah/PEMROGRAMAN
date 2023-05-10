#include <bits/stdc++.h>
using namespace std;

class Pegawai
{
    protected:
    string id;
    int usia, tipe;
    int income;
    public:
    void set(string pid, int u, int t ) 
    {
        id=pid; usia=u; tipe=t;
    }
    string getID() 
    {
        return id; 
    }
    void print()
    {
        cout << id << " " << tipe << " " << income << endl;
    }
};

class Tetap : public Pegawai
{
    int lembur;
    public:
    Tetap()
    {
        id = "";
        income = lembur = 0;
        tipe = 1;
    }
    void setIncome (int inc)
    {
        income = inc;
    }
    void setLembur (int l)
    {
        lembur = l;
        income += lembur;
    }

};

class Harian : public Pegawai
{
    int upah;
    public:
    Harian()
    {
        id = "";
        income = upah = 0;
        tipe = 2;
    }
    void setUpah (int uph)
    {
        upah = uph;
        income = upah;
    }
};

class daftar
{
    vector<Tetap> T;
    vector<Harian> H;
    public:
    void addTetap(Tetap t)
    {
        T.push_back(t);
    }
    void addHarian(Harian h)
    {
        H.push_back(h);
    }
    void checkidLembur(string i, int tmp)
    {
        for (auto it = T.begin(); it != T.end(); it++)
        {
            if (i == it->getID())
            {
                it->setLembur(tmp);
            }
        }
    }
    void checkidUpah(string i, int tmp)
    {
        for (auto it = H.begin(); it != H.end(); it++)
        {
            if (i == it->getID())
            {
                it->setUpah(tmp);
            }
        }
    }
    void printTetap()
    {
        vector<Tetap>::iterator it;
        for (it = T.begin(); it != T.end(); it++)
        {
            it->print();
        }
    }
    void printHarian()
    {
        vector<Harian>::iterator it;
        for (it = H.begin(); it != H.end(); it++)
        {
            it->print();
        }
    }
};

int main()
{
    int i, j, n, usia, tipe, income, temp;
    string id;
    string ch = "";
    Tetap tempTetap;
    Harian tempHarian;
    daftar daftarPegawai;
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cin >> id >> usia >> tipe;
        if (tipe == 1)
        {
            cin >> income;
            tempTetap.set(id, usia, tipe);
            tempTetap.setIncome(income);
        	daftarPegawai.addTetap(tempTetap);
        }
        else if (tipe == 2)
        {
            tempHarian.set(id, usia, tipe);
            daftarPegawai.addHarian(tempHarian);
        }
    }
    while (ch != "END")
    {
        cin >> ch;
        if (ch != "END")
        {
            cin >> temp;
            daftarPegawai.checkidLembur(ch, temp);
            daftarPegawai.checkidUpah(ch, temp);
        }
    }
    daftarPegawai.printTetap();
    daftarPegawai.printHarian();
}