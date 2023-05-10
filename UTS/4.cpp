#include <bits/stdc++.h>
using namespace std;

class murid
{
    string nama, kelamin;
    double ipk;
    public:
    murid()
    {
        nama = kelamin = "";
        ipk = 0;
    }
    void set(string nm, string klm, double ipkk)
    {
        nama = nm;
        kelamin = klm;
        ipk = ipkk;
    }

    double getipk()
    {
        return ipk;
    }

    string getkelamin()
    {
        return kelamin;
    }

};

int main()
{
    //variables
    int i, n, m, L = 0, P = 0;
    string tempnim, tempnama, tempklmn;
    double tempipk, totalipk = 0;
    murid tempmurid;
    map<string,murid> mapmurid;

    //seluruh murid
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cin >> tempnim >> tempnama >> tempklmn >> tempipk;
        tempmurid.set(tempnama, tempklmn, tempipk);
        mapmurid.insert({tempnim, tempmurid});
    }

    //murid kelas
    cin >> m;
    for ( i = 0; i < m; i++)
    {
        cin >> tempnim;
        auto it = mapmurid[tempnim];
        totalipk += it.getipk();
        if (it.getkelamin() == "L")
        {
            L++;
        }
        else
        {
            P++;
        }
    }

    //output
    cout << L << " " << P << endl;
    totalipk /= m;
    cout << fixed << setprecision(2);
    cout << totalipk;
}