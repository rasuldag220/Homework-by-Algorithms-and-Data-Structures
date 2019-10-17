#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
const int maxn = 1e5 + 17;
 
long long mergee(vector <int> &v, int l, int m, int r) {
    long long counter = 0;
 
    vector <int> b(r - l + 1);
 
    int pos1 = l;
    int pos2 = m + 1;
    int posB = 0;
 
    while (pos1 <= m && pos2 <= r) {
        if (v[pos1] <= v[pos2]) {
            b[posB] = v[pos1];
            pos1++;
            posB++;
        } else {
            b[posB] = v[pos2];
            pos2++;
            posB++;
            counter += m - pos1 + 1;
        }
    }
 
    while (pos1 <= m) {
        b[posB] = v[pos1];
        posB++;
        pos1++;
 
    }
 
    while (pos2 <= r) {
        b[posB] = v[pos2];
        posB++;
        pos2++;
 
    }
 
    copy(b.begin(), b.end(), v.begin() + l);
 
    return counter;
}
 
long long mergeSort(vector<int> &v, int l, int r) {
    long long counter = 0;
 
    if (l == r) {
        return counter;
    }
    int m = (l + r) / 2;
 
    counter += mergeSort(v, l, m);
    counter += mergeSort(v, m + 1, r);
 
    counter += mergee(v, l, m, r);
 
    return counter;
}
 
 
 
int main(){
 
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
 
    int n;
    cin >> n;
    vector <int> v(n);
 
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    cout << mergeSort(v, 0, n - 1);
 
}