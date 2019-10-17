#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const int maxn = 1e5 + 17;
 
void mergeSort(vector <int> &a, int start, int endd) {
 
    if (endd - start < 2) {
        return;
    }
    if (endd - start == 2) {
        if (a[start] > a[start + 1]){
            swap(a[start], a[start + 1]);
 
        }
        return;
    }
 
    mergeSort(a, start, (start + (endd - start) / 2));
    mergeSort(a, (start + (endd - start) / 2), endd);
    vector <int> b;
    int b1 = start;
    int e1 = (start + (endd - start) / 2);
    int b2 = e1;
    int e2 = endd;
 
    while (b.size() < endd - start) {
        if (b1 >= e1 || (b2 < endd && a[b1] > a[b2])) {
            b.push_back(a[b2]);
            b2++;
        } else {
            b.push_back(a[b1]);
            b1++;
        }
    }
 
    for (int i = start; i < endd; i++){
        a[i] = b[i - start];
    }
 
 
}
 
 
 
int main()
{
 
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
 
    int n;
    cin >> n;
    vector <int> v;
 
 
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
 
    mergeSort(v, 0, v.size());
 
    for (int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
 
 
}