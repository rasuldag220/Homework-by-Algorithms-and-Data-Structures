#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
int main()
{
 
 
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
 
    int n;
    cin >> n;
    vector <int> v(n + n);
 
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        swap(v[i] , v[i / 2]);
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
}