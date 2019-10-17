#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
 
    ifstream in;
    ofstream out;
 
    in.open("sortland.in");
    out.open("sortland.out");
 
    long long n;
 
    in >> n;
 
    vector <double> v(n);
    vector <int> v1(n);
    vector <double> ans;
    for (int i = 0; i < n; i++){
        in >> v[i];
    }
 
    for (int i = 0; i < n; i++){
        v1[i] = v[i];
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
 
    int minn = ans[0];
    int mid =  ans[n / 2];
    int maxx = ans[n - 1];
 
    for (int i = 0; i < v1.size(); i++){
        if (v1[i] == minn) {
            out << i + 1<< ' ';
            break;
        }
    }
    for (int i = 0; i < v1.size(); i++){
        if (v1[i] == mid) {
            out << i + 1 << ' ';
            break;
        }
    }
    for (int i = 0; i < v1.size(); i++){
        if (v1[i] == maxx) {
            out << i + 1 << ' ';
            break;
        }
    }
 
 
}