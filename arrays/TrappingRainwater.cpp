#include<bits/stdc++.h>
using namespace std;

int trappingRainwater(int, int []);

int main()
{
    int n, ar[50];
    cout << "Enter the size of the bars: ";
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cout << "ar[" << i << "] = ";
        cin >> ar[i];
    }
}

int trappingRainwater(int size, int b[])
{
    int water = 0, rmax[size], lmax[size];
    lmax[0] = b[0];
    for(int i = 0; i<size; i++)
    {
        lmax[i]= max(b[i], lmax[i-1]);
    }
    rmax[size - 1] = b[size - 1];
    for (int j=size-2 ;j>=0; j--)
    {
        rmax[j] = max(b[j], rmax[j+1]);
    }
    for(int i = 1; i<size-1; i++)
    {
        water += (min(rmax[i], lmax[i]) - b[i]);
    }
    return water;
}