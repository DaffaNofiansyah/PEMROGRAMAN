#include <bits/stdc++.h>
using namespace std;

class Titik
{
    int x, y;
    public:
    Titik() 
    {
        x = 0; 
        y = 0;
    }

    void setTitik(int a, int b)
    {
        x = a;
        y = b;
    }

    void getTitik()
    {
        cout << "(" << x << "," << y << ")";
    }

    int getx()
    {
        return x;
    }

    int gety()
    {
        return y;
    }
};

bool cmp (Titik &a, Titik &b)
{
    if (a.getx() > b.getx())
    {
        return true;
    }
    else if (a.getx() == b.getx())
    {
        if (a.gety() > b.gety())
        {
            return true;
        } 
        else return false;
    }
    else return false; 
}

int main()
{
    int i, n, x, y;
    vector<Titik> hotspot;
    Titik temp;
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cin >> x >> y;
        temp.setTitik(x, y);
        hotspot.push_back(temp);
    }

    for ( i = 1; i < hotspot.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (hotspot.at(i).getx() == hotspot.at(j).getx() && hotspot.at(i).gety() == hotspot.at(j).gety())
            {
                hotspot.erase(hotspot.begin()+i);
                i--;
            }
        }
    }

    cout << hotspot.size() << endl; 
    for (auto it = hotspot.begin(); it != hotspot.end(); it++)
    {
        if (it->gety() > 0)
        {
            it->getTitik();
            cout << " ";
        }
    }

}