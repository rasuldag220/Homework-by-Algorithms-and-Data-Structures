#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
 
void mergee (pair <string, string>  a[], int l, int mid, int r) {
 
    pair <string, string> ans[r - l + 1];
 
    for (int i = 0; i < r - l + 1; i++) {
        ans[i].first = a[l + i].first;
        ans[i].second = a[l + i].second;
    }
 
    int i = 0, j = 0;
    while (i + l <= mid && j + mid + 1 <= r){
 
        if(ans[i].first > ans[j + (r - l) / 2 + 1].first) {
            a[l + i + j].first = ans[j + (r - l) / 2 + 1].first;
            a[l + i + j].second = ans[j + (r - l) / 2 + 1].second;
            j++;
 
        } else {
            a[l + i + j].first = ans[i].first;
            a[l + i + j].second = ans[i].second;
            i++;
        }
 
    }
 
    while (i + l <= mid){
        a[i + j + l].first = ans[i].first;
        a[i + j + l].second = ans[i].second;
        i++;
    }
    while (j + mid + 1 <= r){
        a[i + j + l].first = ans[j + (r - l) / 2 + 1].first;
        a[i + j + l].second = ans[j + (r - l) / 2 + 1].second;
        j++;
    }
 
}
 
void mergeSort(pair <string, string> a[], int l, int r) {
 
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        mergee (a, l, mid, r);
    }
}
 
 
 
int main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
 
    int n;
    cin >> n;
 
    pair <string, string> pi[n];
 
    for (int i = 0; i < n; i++) {
        cin >> pi[i].first >> pi[i].second;
    }
 
    mergeSort(pi, 0, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout << "=== " << pi[i].first << " ===" << '\n';
        cout << pi[i].second << "\n";
        while (i + 1 < n && pi[i].first == pi[i + 1].first) {
            i++;
            cout << pi[i].second << "\n";
 
        }
 
    }
    return 0;
}