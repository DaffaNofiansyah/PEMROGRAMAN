#include <bits/stdc++.h>
using namespace std;

class makanan
{
    protected:
    string nama, jenis;
    int gula, karbohidrat;
    int totalkalori;
    public:
    makanan()
    {
        nama = jenis = "";
        gula = karbohidrat = totalkalori = 0;
    }
    string getnama()
    {
        return nama;
    }

};

class mkalori : makanan
{
    static int A;
    static int B;
    public:
    void setkalori(string nm, string jns, int gl, int karbo)
    {
        nama = nm;
        jenis = jns;
        gula = gl;
        karbohidrat = karbo;
    }

    static int getA()
    {
        return A;
    }

    static int getB()
    {
        return B;
    }

    string getnama()
    {
        return nama;
    }

    void settotalkalori()
    {
        totalkalori = (A*gula) + (B*karbohidrat);
    }

    int gettotalkalori()
    {
        return totalkalori;
    }

};

class mnutrisi : makanan
{
    static int A;
    static int B;
    public:
    void setnutrisi(string nm, string jns, int gl, int karbo)
    {
        nama = nm;
        jenis = jns;
        gula = gl;
        karbohidrat = karbo;
    }

    static int getA()
    {
        return A;
    }

    static int getB()
    {
        return B;
    }

    void settotalkalori()
    {
        totalkalori = (A*gula) + (B*karbohidrat);
    }

    int gettotalkalori()
    {
        return totalkalori;
    }
};

int mkalori::A = 50;
int mkalori::B = 20;

int mnutrisi::A = 20;
int mnutrisi::B = 10;

int main()
{
    int i, j, n, tempgula, tempkarbo, kalori = 0, temp;
    string tempnama, tempjenis;
    cin >> n;
    vector<mkalori> daftarkalori;
    vector<mnutrisi> daftarnutrisi;
    vector<string> kaloriprint;
    mkalori tempkalori;
    mnutrisi tempnutrisi;

    for ( i = 0; i < n; i++)
    {
        cin >> tempnama >> tempjenis >> tempgula >> tempkarbo;
        if (tempjenis == "Kalori")
        {
            temp = (mkalori::getA()*tempgula) + (mkalori::getB()*tempkarbo);
            if (temp > 1000)
            {
                kaloriprint.push_back(tempnama);
            }
            tempkalori.setkalori(tempnama, tempjenis, tempgula, tempkarbo);
            daftarkalori.push_back(tempkalori);  
        }
        else if (tempjenis == "Nutrisi")
        {
            temp = (mnutrisi::getA()*tempgula) + (mnutrisi::getB()*tempkarbo);
            if (temp > 1000)
            {
                kaloriprint.push_back(tempnama);
            }
            tempnutrisi.setnutrisi(tempnama, tempjenis, tempgula, tempkarbo);
            daftarnutrisi.push_back(tempnutrisi);
        }
    }

    for (auto it = daftarkalori.begin(); it != daftarkalori.end(); it++)
    {
        it->settotalkalori();
        kalori += it->gettotalkalori();
    }
    for (auto it = daftarnutrisi.begin(); it != daftarnutrisi.end(); it++)
    {
        it->settotalkalori();
        kalori += it->gettotalkalori();
    }
    
    cout << kalori << endl;
    for (auto it = kaloriprint.begin(); it != kaloriprint.end(); it++)
    {
        cout << *it << endl;
    }
    
}

