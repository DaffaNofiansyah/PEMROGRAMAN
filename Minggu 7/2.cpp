    #include <bits/stdc++.h>
    using namespace std;

    class Orang
    {
        protected:
        string nama;
        int usia;
        public:
        Orang()
        {
            nama = "";
            usia = 0;
        }
        void setData(string n, int u)
        {
            nama = n;
            usia = u;
        }
    };

    class Mahasiswa : public Orang
    {
        protected:
        string nim;
        public:
        Mahasiswa()
        {
            nim = "";
        }
        void setData(string n, int u, string nm)
        {
            nama = n;
            usia = u;
            nim = nm;
        }
    };

    class Nilai : Mahasiswa
    {
        protected:
        static int totalsks, totalNilai;
        static double IPK;
        string HurufMutu;
        public:
        Nilai()
        {
            HurufMutu = "";
        }
        void setData(string n, int u, string nm)
        {
            nama = n;
            usia = u;
            nim = nm;
        }
        void setNilai(string mk, int sk, string hm)
        {
            totalsks += sk;
            HurufMutu = hm;
            if (HurufMutu == "A")
            {
                totalNilai += 4*sk;
            }
            else if (HurufMutu == "B")
            {
                totalNilai += 3*sk;
            }
            else if (HurufMutu == "C")
            {
                totalNilai += 2*sk;
            }
            else if (HurufMutu == "D")
            {
                totalNilai += 1*sk;
            }
            else if (HurufMutu == "E")
            {
                totalNilai += 0*sk;
            }
            IPK = (double)totalNilai/totalsks;
        }
        void print()
        {   
            cout << fixed << setprecision(2);
            cout << nama << " " << "(" << nim << ")" << ":" << totalsks << ":" << IPK << endl;
        }
    };

    int Nilai::totalsks = 0;
    int Nilai::totalNilai = 0;
    double Nilai::IPK = 0;

    int main()
    {
        int i, Usia, tempsks;
        string Nama, NIM, tempMK, tempHM;
        Nilai tempNilai;
        cin >> Nama >> Usia >> NIM;
        tempNilai.setData(Nama, Usia, NIM);
        while (cin >> tempMK)
        {
            cin >> tempsks;
            cin >> tempHM;
            tempNilai.setNilai(tempMK, tempsks, tempHM);
        }
        tempNilai.print();
    }