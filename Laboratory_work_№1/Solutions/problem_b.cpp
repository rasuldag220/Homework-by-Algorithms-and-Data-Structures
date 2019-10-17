#include <iostream>
#include <fstream>
 
 
 
using namespace std;
 
int main()
{
    ifstream in;
    ofstream out;
 
    in.open("aplusbb.in");
    out.open("aplusbb.out");
 
    long long a, b;
 
    in >> a >> b;
    out << a + b * b;
}