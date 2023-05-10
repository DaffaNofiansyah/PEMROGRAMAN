#include <bits/stdc++.h>
using namespace std;

class Ruang2D
{
    protected:
    double sisi1, sisi2, sisi3, sisi4;
    public:
    virtual double luas() = 0;
    virtual double keliling() = 0;
    void set(int s1=0, int s2=0, int s3=0, int s4=0) 
    {
        sisi1 = s1;
        sisi2 = s2;
        sisi3 = s3;
        sisi4 = s4;
    }
};

class Segiempat : public Ruang2D
{
    public:
    void set(int s1, int s2)
    {
        sisi1 = sisi3 = s1;
        sisi2 = sisi4 = s2;
    }
    double luas()
    {
        return sisi1*sisi2;
    }
    double keliling()
    {
        return (sisi1+sisi2+sisi3+sisi4);
    }
};

class Segitiga : public Ruang2D
{

    public:
    void set(int s1, int s2)
    {
        sisi1 = s1;
        sisi2 = s2;
        sisi3 = sqrt(sisi1*sisi1+sisi2*sisi2);
    }
    double luas()
    {
        return (sisi1*sisi2)/2;
    }
    double keliling()
    {
        return sisi1+sisi2+sisi3;
    }
}; 

// void sortvector(vector<Segiempat> &segi4, vector<Segitiga> &segi3)
// {
//     int i, j, n, m;
//     n = segi4.size();
//     m = segi3.size();
//     for(i=0; i<n; i++)
//     {
//         for(j=i+1; j<n; j++)
//         {
//             if(segi4[i].luas() < segi4[j].luas())
//             {
//                 swap(segi4[i], segi4[j]);
//             }
//             else if(segi4[i].luas() == segi4[j].luas())
//             {
//                 if(segi4[i].keliling() < segi4[j].keliling())
//                 {
//                     swap(segi4[i], segi4[j]);
//                 }
//             }
//         }
//     }
//     for(i=0; i<m; i++)
//     {
//         for(j=i+1; j<m; j++)
//         {
//             if(segi3[i].luas() < segi3[j].luas())
//             {
//                 swap(segi3[i], segi3[j]);
//             }
//             else if(segi3[i].luas() == segi3[j].luas())
//             {
//                 if(segi3[i].keliling() < segi3[j].keliling())
//                 {
//                     swap(segi3[i], segi3[j]);
//                 }
//             }
//         }
//     }
// }

bool compare(Segiempat &a, Segiempat &b)
{
    if(a.luas() > b.luas())
    {
        return true;
    }
    else if(a.luas() == b.luas())
    {
        if(a.keliling() > b.keliling())
        {
            return true;
        }
    }
    return false;
}

bool compare2(Segitiga &a, Segitiga &b)
{
    if(a.luas() > b.luas())
    {
        return true;
    }
    else if(a.luas() == b.luas())
    {
        if(a.keliling() > b.keliling())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int i, j, n, m;
    double tempsisi1, tempsisi2, tempsisi3, tempsisi4;
    cin >> n >> m;
    Segiempat tempsegi4;
    Segitiga tempsegi3;
    vector<Segiempat> segi4;
    vector<Segitiga> segi3;
    for(i=0; i<n; i++)
    {
        cin >> tempsisi1 >> tempsisi2;
        tempsegi4.set(tempsisi1, tempsisi2);
        segi4.push_back(tempsegi4);
    }
    for(i=0; i<m; i++)
    {
        cin >> tempsisi1 >> tempsisi2;
        tempsegi3.set(tempsisi1, tempsisi2);
        segi3.push_back(tempsegi3);
    }

    //sortvector(segi4, segi3);

    sort(segi4.begin(), segi4.end(), compare);
    sort(segi3.begin(), segi3.end(), compare2);

    cout << "SEGIEMPAT" << endl;
    for(i=0; i<n; i++)
    {
        cout << fixed << setprecision(1);
        cout << segi4[i].luas() << " ";
        cout << segi4[i].keliling() << endl;
    }
    cout << "SEGITIGA" << endl;
    for(i=0; i<m; i++)
    {
        cout << fixed << setprecision(1);
        cout << segi3[i].luas() << " ";
        cout << segi3[i].keliling() << endl;
    }

}


