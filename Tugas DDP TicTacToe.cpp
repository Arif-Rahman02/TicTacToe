#include <iostream>
using namespace std;
int main ( )
{

int L_tiktaktoe;
int T_tiktaktoe;

cout << "masukkan angka untuk menentukan lebar: ";
cin >> L_tiktaktoe;
cout << "masukkan angka untuk menentukan tinggi: ";
cin >> T_tiktaktoe;

for (int L = 1; L <= L_tiktaktoe ; L++)
{
	cout << " _ ";
}
cout << endl;
for (int T = 1; T <= T_tiktaktoe ; T++)
{
for (int L = 1; L <= L_tiktaktoe ; L++)
{

	cout << "|_|";
}
cout << endl;
}
return 0;
}
