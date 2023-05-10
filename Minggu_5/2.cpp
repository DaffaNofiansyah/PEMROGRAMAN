#include <bits/stdc++.h>
using namespace std;

class akun
{
    int transaksi;
    public:
    akun() {transaksi = 0; }
    void set(int t) {transaksi = t; }
    int getTransaksi() { return transaksi; }
    void incTransaksi() { transaksi++; }
};

int main()
{
    int n, m, i, j;
    string noAkun;
    cin >> m;
    for (i = 0; i < m; i++)
    {
        map<string, akun> m1;
        map<string, akun>::iterator it;
        cin >> n;
        scanf(" ");
        for(j = 0; j < n; j++)
        {
            getline(cin, noAkun);
            if(m1.find(noAkun) == m1.end())
            {
                m1[noAkun].set(1);
            }
            else m1[noAkun].incTransaksi();
        }
        for(it = m1.begin(); it != m1.end(); it++)
        {
            cout << it->first<< " " << it->second.getTransaksi() << endl;
        }
        m1.clear();
        cout << endl;
    }
    return 0;
}