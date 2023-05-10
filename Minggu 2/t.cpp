#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int start, end, i, k, n, q, j;
    cin >> n >> q;
    int **arr_n;
    arr_n = new int*[n];
    for (i = 0; i < n; i++) 
    {
        cin >> k;
        arr_n[i] = new int[k];
        for ( j = 0; j < k; j++)
        {
            cin >> arr_n[i][j];
        }
    }

    for ( start = 0; start < q; start++) 
    {
        cin >> i >> j;
        cout << arr_n[i][j] << endl;
    }
    
    return 0;
}