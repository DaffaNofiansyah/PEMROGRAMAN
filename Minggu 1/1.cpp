#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i, n, k, nilai, sum = 0, pembagi = 0;
    double rata2;
    cin >> n;
    cin >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> nilai;
        if ( i % k == 0)
        {
            sum += nilai;
            pembagi++;
        }
    } 

    if (pembagi == 0 || n == 0 || n < k)
    {
        rata2 = 0;
    }
    else
    {
        rata2 = (double)sum / pembagi;
    }
    cout << fixed << setprecision(2);
    cout << rata2 << endl;
    return 0;
}