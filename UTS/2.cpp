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
        void setBarang(string idd, string klmpk, string nm, int jmlh)
        {
            id = idd;
            kelompok = klmpk;
            nama = nm;
            jumlah = jmlh;
        }
        string getkelompok()
        {
            return kelompok;
        }
        string getid()
        {
            return id;
        }
        string getnama()
        {
            return nama;
        }
        int getjumlah()
        {
            return jumlah;
        }
    };

    class Kelompok
    {
        string namakelompok;
        int jumlah;
        public:
        Kelompok()
        {
            namakelompok = "";
            jumlah = 0;
        }
        void setKelompok (string klmpk , int jmlh)
        {
            namakelompok = klmpk;
            jumlah = jmlh;
        }
        string getKelompok()
        {
            return namakelompok;
        }
        int getjumlah()
        {
            return jumlah;
        }
    };


    bool cmp1(Kelompok &a, Kelompok &b)
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
        else
        {
            return false;
        }
    }

    bool cmp2(Barang &a, Barang &b)
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

    bool cmp3(Barang &a, Barang &b)
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


    int main()
    {
        int i, n, m, jumlah, counter = 0;
        string id, kelompok, nama, tempkelompok;
        vector<Barang> daftar;
        vector<Kelompok> daftarkelompok;
        Barang temp;
        Kelompok tempdaftarkelompok;
        cin >> n;
        for ( i = 0; i < n; i++)
        {
            cin >> id >> kelompok >> nama >> jumlah;
            temp.setBarang(id, kelompok, nama, jumlah);
            daftar.push_back(temp);
        }

        sort(daftar.begin(), daftar.end(), cmp3);

        tempkelompok = daftar.begin()->getkelompok();
        for (auto it = daftar.begin(); it != daftar.end(); it++)
        {
            if (it->getkelompok() == tempkelompok)
            {
                counter++;
            }
            else
            {
                tempdaftarkelompok.setKelompok(tempkelompok, counter);
                daftarkelompok.push_back(tempdaftarkelompok);
                counter = 1;
                tempkelompok = it->getkelompok();
            }
        }

        tempdaftarkelompok.setKelompok(tempkelompok, counter);
        daftarkelompok.push_back(tempdaftarkelompok);
        

        sort(daftarkelompok.begin(), daftarkelompok.end(), cmp1);

        for (auto it = daftarkelompok.begin(); it != daftarkelompok.end(); it++)
        {
            cout << it->getKelompok() << " " << it->getjumlah() << endl;
        }

        sort(daftar.begin(), daftar.end(), cmp2);

        cin >> m;
        for ( i = 0; i < m; i++)
        {

            cin >> tempkelompok;
            cout << "*****" << endl;
            cout << "Daftar Barang " << tempkelompok << endl;
            for (auto it = daftar.begin(); it != daftar.end(); it++)
            {
                if (it->getkelompok() == tempkelompok)
                {
                    cout << it->getnama() << " " << it->getjumlah() << endl;
                }
            }
        }
    }