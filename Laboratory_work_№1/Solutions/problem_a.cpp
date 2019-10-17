#include <iostream>
#include <fstream>
 
 
 
using namespace std;
 
int main()
{
    ifstream in;
    ofstream out;
 
    in.open("aplusb.in");
    out.open("aplusb.out");
 
    int a, b;
 
    in >> a >> b;
    out << a + b;
}