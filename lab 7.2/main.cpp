#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Switch(int** a, const int n, int& max, int& min);
int Sum(int min, int max);
int main(){
    
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    int max = 0, min = 100;
    cout << "n = "; cin >> n;
    int **a = new int*[n];
    for (int i=0; i<n; i++)
        a[i] = new int[n];
    
    Create(a, n, Low, High);
    Print(a, n);
    Switch(a, n, max, min);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    Print(a, n);
    cout << "Сума: "<< Sum(min, max);
    cout << endl;
    
    for (int i=0; i<n; i++)
            delete [] a[i];
        delete [] a;
    
    return 0;
}
void Create(int** a, const int n, const int Low, const int High) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
a[i][j] = Low + rand() % (High-Low+1);
}
void Print(int** a, const int n)
{
    cout << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
void Switch(int** a, const int n, int& max, int& min)
{
    int Imin, Jmin, Imax, Jmax;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1 - i; j++)
            if(a[i][j] < min){
                min = a[i][j];
                Imin = i;
                Jmin = j;
            }
   
   for(int i = 0; i < n ; i++)
        for(int j = n - 1; j > n - 1 - i; j--)
            if(a[i][j] > max){
                max = a[i][j];
                Imax = i;
                Jmax = j;
            }
    int tmp = a[Imin][Jmin];
    a[Imin][Jmin]=a[Imax][Jmax];
    a[Imax][Jmax]=tmp;
}
int Sum(int min, int max)
{
    return min + max;
}
