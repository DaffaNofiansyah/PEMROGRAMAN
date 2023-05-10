#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class person
{
    private:
        string name;
        int age, height;
        double t, weight, IMT;
    public: 
        person() { name = "", age = 0, height = 0, weight = 0; }
        person(string n, int a, int h, double w) { name = n, age = a, height = h, weight = w; }
        void setperson(string n, int a, int h, double w) { name = n, age = a, height = h, weight = w; }
        void getnameage() { cout << name << " " << age << " " << height << " " << weight << " "; }
        int getheight() { return height; }
        double getweight() { return weight; }
        void setIMT(int h, double w) { IMT = (double) (w) / ((h/100.0) * (h/100.0)); }
        double getIMT()
        {
            setIMT(height, weight);
            return IMT;
        }
        void printIMT()
        {
            cout << fixed << setprecision(2) << IMT << " ";
        }
        string getstatusgizi()
        {
            t = getIMT();
            if (getIMT() < 17.0)
            {
                return "sangat kurus";
            }
            else if (getIMT() >= 17.0 && getIMT() < 18.5)
            {
                return "kurus";
            }
            else if (getIMT() >= 18.5 && getIMT() < 25.0)
            {
                return "normal";
            }
            else if (getIMT() >= 25.0 && getIMT() < 28.0)
            {
                return "gemuk";
            }
            else if (getIMT() >= 28.0)
            {
                return "sangat gemuk";
            }
        }
};


int main()
{
    int i, x, height_sum = 0, height_counter = 0, temp;
    double avg = 0;
    cin >> x;
    person* number = (person*) malloc(x * sizeof(person));
    for (i = 0; i < x; i++)
    {
        string name;
        int age, height;
        double weight;
        cin >> name >> age >> height >> weight;
        number[i].setperson(name, age, height, weight);
        height_sum += height;
    }

    avg = (double)height_sum / x;
    
    for (i = 0; i < x; i++)
    {
        if (number[i].getheight() > avg)
        {
            height_counter++;
        }
    }
    
    for (i = 0; i < x; i++)
    {
        string name;
        int age, height;
        double weight;
        cout << fixed << setprecision(2);
        number[i].getnameage();
        temp = number[i].getIMT();
        cout << fixed << setprecision(2);
        cout << number[i].getIMT() << " ";
        cout << number[i].getstatusgizi() << endl;   

    }
    cout << fixed << setprecision(2);
    cout << avg << endl;
    cout << height_counter << endl;
    int sk = 0, k = 0, norm = 0, g = 0, sg = 0;
    for ( i = 0; i < x; i++)
    {
        if (number[i].getstatusgizi() == "sangat kurus")
        {
            sk++;
        }
        else if (number[i].getstatusgizi() == "kurus")
        {
            k++;
        }
        else if (number[i].getstatusgizi() == "normal")
        {
            norm++;
        }
        else if (number[i].getstatusgizi() == "gemuk")
        {
            g++;
        }
        else if (number[i].getstatusgizi() == "sangat gemuk")
        {
            sg++;
        } 
    }
    cout << sk << " " << k << " " << norm << " " << g << " " << sg << endl;
    
    
}