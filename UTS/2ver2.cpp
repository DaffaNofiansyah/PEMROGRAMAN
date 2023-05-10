#include <bits/stdc++.h>
using namespace std;

class Barang
{
    string id, kelompok, nama;
    int jumlah;
    public:
    Barang()
    {
        id = kelompok = nama = "";
        jumlah = 0;
    }
    void setBarang(string tempid, string tempkelompok, string tempnama, int tempjumlah)
    {
        id = tempid;
        kelompok = tempkelompok;
        nama = tempnama;
        jumlah = tempjumlah;
    }
    string getid()
    {
        return id;
    }
    string getkelompok()
    {
        return kelompok;
    }
    string getnama()
    {
        return nama;
    }
    int getjumlah()
    {
        return jumlah;
    }
    void print()
    {
        cout << nama << " " << jumlah << endl;
    }
};

class kelompok
{
    string nama;
    int jumlah;
    public:
    kelompok()
    {
        nama = "";
        jumlah = 0;
    }
    void setkelompok(string tempnama, int tempjumlah)
    {
        nama = tempnama;
        jumlah = tempjumlah;
    }
    string getKelompok()
    {
        return nama;
    }
    int getjumlah()
    {
        return jumlah;
    }
    void print()
    {
        cout << nama << " " << jumlah << endl;
    }
};

bool compare1 (Barang a, Barang b)
{
    if (a.getkelompok() < b.getkelompok())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compare2 (kelompok a, kelompok b)
{
    if (a.getjumlah() > b.getjumlah())
    {
        return true;
    }
    else if (a.getjumlah() == b.getjumlah())
    {
        if (a.getKelompok() < b.getKelompok())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool compare3 (Barang a, Barang b)
{
    if (a.getnama() < b.getnama())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n, m, tempjumlah;
    string tempid, tempkelompok, tempnama;
    vector<Barang> daftarbarang;
    vector<kelompok> daftarkelompok;
    Barang tempbarang;
    kelompok tempobjekkelompok;
    cin >> n;

    // Input barang
    for (int i = 0; i < n; i++)
    {
        cin >> tempid >> tempkelompok >> tempnama >> tempjumlah;
        tempbarang.setBarang(tempid, tempkelompok, tempnama, tempjumlah);
        daftarbarang.push_back(tempbarang);
    }

    // Sort barang
    sort(daftarbarang.begin(), daftarbarang.end(), compare1);

    // Input kelompok
    tempjumlah = 0;
    auto it = daftarbarang.begin()->getkelompok();
    tempkelompok = it;
    for (auto it = daftarbarang.begin(); it != daftarbarang.end(); it++)
    {
        if (it->getkelompok() == tempkelompok)
        {
            tempjumlah++;
        }
        else
        {
            tempobjekkelompok.setkelompok(tempkelompok, tempjumlah);
            daftarkelompok.push_back(tempobjekkelompok);
            tempkelompok = it->getkelompok();
            tempjumlah = 1;
        }
    }
    tempobjekkelompok.setkelompok(tempkelompok, tempjumlah);
    daftarkelompok.push_back(tempobjekkelompok);

    // Sort kelompok
    sort(daftarkelompok.begin(), daftarkelompok.end(), compare2);

    // Sort barang
    sort(daftarbarang.begin(), daftarbarang.end(), compare3);

    // Print kelompok
    for (auto it = daftarkelompok.begin(); it != daftarkelompok.end(); it++)
    {
        it->print();
    }

    // Print barang
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tempkelompok;
        cout << "*****" << endl;
        cout << "Daftar Barang " << tempkelompok << endl;
        for (auto it = daftarbarang.begin(); it != daftarbarang.end(); it++)
        {
            if (it->getkelompok() == tempkelompok)
            {
                it->print();
            }
        }
    }
}