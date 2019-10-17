#include <bits/stdc++.h>
#include <fstream>
 
using namespace std;
 
int main()
{
     ifstream in;
     ofstream out;
 
     in.open("turtle.in");
     out.open("turtle.out");
 
    int n, m;
    in >> n >> m;
 
    int mass[n + 10][m + 10];
    int dp[n + 10][m + 10]{};
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            in >> mass[i][j];
        }
    }
 
 
 
 
    int dpp[n + 10][m + 10]{};
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= m; j++){
            dpp[i][j] = mass[i][j - 1];
        }
    }
 
    for (int i = n - 1; i != -1; i--){
        for (int j = 1; j <= m; j++){
            dpp[i][j] += max(dpp[i + 1][j], dpp[i][j - 1]);
        }
 
    }
 
 
    out << dpp[0][m];
 
 
 
 
 
 
 
 
}