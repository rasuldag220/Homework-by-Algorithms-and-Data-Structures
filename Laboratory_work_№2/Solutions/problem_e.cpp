#include <iostream>
#include <vector>
using namespace std;
 
int partitionn(vector<int> &mas, int l, int r) {
    if (l != r)
        swap(mas[l + rand() % (r - l)], mas[r]);
    int x = mas[r];
    int i = l - 1;
    for (int j = l; j <= r; j++) {
        if (mas[j] < x)
            swap(mas[++i], mas[j]);
        }
    swap(mas[++i], mas[r]);
    return i;
}
int nth (vector<int> mas, int n) {
    int l = 0, r = mas.size() - 1;
    while(true) {
        int pos = partitionn(mas,l,r);
        if (mas[pos] == mas[r] && n >= pos) {
            return mas[pos];
        }
        if (pos < n)
            l = pos + 1;
        else if (pos > n)
            r = pos - 1;
        else return mas[n];
    }
}
int main(){
 
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
 
 
 
    int n;
    int k;
    cin >> n >> k;
    k--;
    vector <int> v(n);
    int A, B, C, a1, a2;
    cin >> A >> B >> C >> a1 >> a2;
    v[0] = a1;
    v[1] = a2;
    for (int i = 2; i < n; i++) {
        v[i] = A * v[i - 2] + B * v[i - 1] + C;
    }
 
    cout << nth(v, k);
 
 
 
}