#include<iostream>
#include<vector>
#include<omp.h>
using namespace std;

int main()
{
    int n,sum=0;

    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
        cin>>a[i];

    int min=a[0],max=a[0];

    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<n;i++)
        sum+=a[i];

    #pragma omp parallel for reduction(min:min)
    for(int i=0;i<n;i++)
        if(a[i]<min)
            min=a[i];

    #pragma omp parallel for reduction(max:max)
    for(int i=0;i<n;i++)
        if(a[i]>max)
            max=a[i];

    float avg=(float)sum/n;

    cout<<"Sum = "<<sum<<endl;
    cout<<"Min = "<<min<<endl;
    cout<<"Max = "<<max<<endl;
    cout<<"Average = "<<avg;
}