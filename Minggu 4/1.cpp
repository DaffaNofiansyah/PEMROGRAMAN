#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class vect
{
    private:
    vector<int> v;
    int deleted = 0;
    public:
    vect() {v.clear();}
    void add(int x) 
    {
        v.push_back(x);
    }
    void del(int x)
    {
        v.erase(v.begin() + (x-1) - deleted);
        deleted++;
    }
    int getsize()
    {
        int size = v.size();
        return size;
    }
    float getavg()
    {
        int sum = 0;
        int size = v.size();
        float avg;
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                sum += v[i];
            }
            avg = (float)sum/size;
            return avg;
        }
        else 
        {
            avg = -9.99;
            return avg;
        }
        
        
    }
};

int main()
{
    vect bilangan;
    float avg1, avg2;
    int x = 0;
    while (x != -9)
    {
        cin >> x;
        if (x != -9)
        {
            bilangan.add(x);
        }
    }
    cout << bilangan.getsize() << " ";
    avg1 = bilangan.getavg();
    x = 0;
    while (x != -9)
    {
        cin >> x;
        if (x != -9)
        {
            bilangan.del(x);
        }
    }
    cout << bilangan.getsize() << endl;
    avg2 = bilangan.getavg();
    cout << fixed << setprecision(2);
    cout << avg1 << " " << avg2 << endl;  
}