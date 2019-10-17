#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
 
    ifstream in;
    ofstream out;
 
    in.open("smallsort.in");
    out.open("smallsort.out");
 
    long long n;
 
    in >> n;
 
    vector <int> v(n);
    vector <int> ans;
 
    for (int i = 0; i < n; i++){
        in >> v[i];
    }
 
    int k = n;
    while (k--){
        int maxx = -1;
        int posMaxx = -1;
 
        for (int j = 0; j < n; j++){
            if (maxx < v[j]){
                maxx = v[j];
                posMaxx = j;
            }
 
        }
        ans.push_back(maxx);
        v[posMaxx] = -1;
 
    }
    reverse(ans.begin(), ans.end());
 
    for (int i = 0; i < ans.size(); i++){
        out << ans[i] << ' ';
    }
 
 
 
}