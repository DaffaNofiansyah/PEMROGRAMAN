#include <iostream>
using namespace std;

int main()
{
    int n, m, i, j;
    int *arr_n, *arr_m;
    cin >> n;
    cin >> m;
    arr_n = (int *)malloc(n * sizeof(int));
    arr_m = (int *)malloc(m * sizeof(int));
    
    for (i = 0; i < n; i++)
    {
        cin >> arr_n[i];
    }

    for (j = 0; j < m; j++)
    {
        cin >> arr_m[j];
    }

    i = 0;
    j = 0;
    while(i < n && j < m)
    {
        if (arr_n[i] <= arr_m[j])
        {
            cout << arr_n[i] << " ";
            i++;
        } 
        else if (arr_n[i] > arr_m[j])
        {
            cout << arr_m[j] << " ";
            j++;
        }
    }

    if (i == n)
    {
        for(j; j<m; j++)
        {
            cout << arr_m[j] << " ";
        }
    } 
    
    else if (j == m)
    {
        for(i; i<n; i++)
        {
            cout << arr_n[i] << " ";
        }
    }
    return 0;
}