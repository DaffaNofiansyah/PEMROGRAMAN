#include <iostream>
using namespace std;


class counter
{
    private:
        int count;
    public:
        counter() { count = 0; }
        counter(int c) { count = c; }
        //counter baru
        void set(int c) 
        { 
            if (c >= 0)
            {
                count = c;
            }
        }
        //menaikkan counter
        void add() { count++; }
        //menurunkan counter
        void sub() 
        { 
            if (count > 0){
                count--;
            }        
        }
        //mengembalikan nilai counter
        int get() { return count; }

};


int main()
{
    counter c1;
    int x = 0, temp;
    do
    {
        cin >> x;
        switch (x)
        {
        case 0:
            cin >> temp;
            c1.set(temp);
            break;

        case 1:
            c1.add();
            break;

        case -1: 
            c1.sub();
            break;

        case 9:
            cout << c1.get() << endl;
            break;

        case -9:
            break;

        default:
            break;
        }
    } while (x != -9);
    
}