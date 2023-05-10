#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class person
{
    private:
        string name;
        int age, height, sk, k, norm, g, sg;
        double weight, IMT;
    public: 
        person() { name = "", age = 0, height = 0, sk = 0, k = 0, norm = 0, g = 0, sg = 0, weight = 0, IMT = 0; }
        // person(string n, int a, int h, double w) { name = n, age = a, height = h, weight = w; }
        void setperson(string n, int a, int h, double w) { name = n, age = a, height = h, weight = w; }
        void getnameage() { cout << name << " " << age; }
        int getheight() { return height; }
        double getweight() { return weight; }
        double getIMT()
        {
            IMT = (double) weight / (height * height);
            return IMT;
        }
        void setIMT(double imt) { IMT = imt; }
        void printIMT()
        {
            cout << fixed << setprecision(2) << IMT << " ";
        }
        void getstatusgizi(double imt)
        {
            if (imt < 17.0)
            {
                cout << "sangat kurus" << endl;
                sk++;
            }
            else if (imt >= 17.0 && imt < 18.5)
            {
                cout << "kurus" << endl;
                k++;
            }
            else if (imt >= 18.5 && imt < 25.0)
            {
                cout << "normal" << endl;
                norm++;
            }
            else if (imt >= 25.0 && imt < 28.0)
            {
                cout << "gemuk" << endl;
                g++;
            }
            else if (imt >= 28.0)
            {
                cout << "sangat gemuk" << endl;
                sg++;
            }
        }
        void getjumlahstatusgizi()
        {
            cout << sk << " " << k << " " << norm << " " << g << " " << sg << endl;
        }
};

int main()
{
    person p;
    p.printIMT();
    p.setperson("A", 20, 170, 60);
    p.getIMT();
    p.setIMT(p.getIMT());
    p.printIMT();
}