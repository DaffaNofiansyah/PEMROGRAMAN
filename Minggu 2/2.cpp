#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class person
{
    private:
        string name;
        int age, height;
        double weight;
    public: 
        person() { name = "", age = 0, height = 0, weight = 0; }
        // person(string n, int a, int h, double w) { name = n, age = a, height = h, weight = w; }
        void setperson(string n, int a, int h, double w) { name = n, age = a, height = h, weight = w; }
        void getnameage() { cout << name << " " << age << endl; }
        int getheight() { return height; }
};


int main()
{
    int i, x, height_sum = 0, height_counter = 0;
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
        number[i].getnameage();
    }
    cout << fixed << setprecision(2);
    cout << avg << endl;
    cout << height_counter << endl;
    
}