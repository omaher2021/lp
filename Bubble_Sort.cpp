#include<iostream>
#include<omp.h>
#include<vector>

using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector <int> a(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    double start = omp_get_wtime();

    for(int i = 0; i < n; i++)
    {
        #pragma omp parallel for
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    double end = omp_get_wtime();

    cout << "\nSorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\nExecution Time = " << end - start;

    return 0;
}