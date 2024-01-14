#include<iostream>
using namespace std;

char baris, kolom;
int no_kotak;
char pemain = 'X';
char nomor[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string pemain1, pemain2;
bool seimbang;

void papan_game(){
	
	cout << " _______________" << endl;
	cout << "|    |     |    |" << endl;
	cout << "|  " << nomor[0][0] << " |  " << nomor[0][1] << "  | " << nomor[0][2] << "  |" << endl;
	cout << "|____|_____|____|" << endl;
	cout << "|    |     |    |" << endl;
	cout << "|  " << nomor[1][0] << " |  " << nomor[1][1] << "  | " << nomor[1][2] << "  |" << endl;
	cout << "|____|_____|____|" << endl;
	cout << "|    |     |    |" << endl;
	cout << "|  " << nomor[2][0] << " |  " << nomor[2][1] << "  | " << nomor[2][2] << "  |" << endl;
	cout << "|____|_____|____|" << endl;
}

void angka_ke_baris_dan_kolom(){
	
	if(pemain == 'X'){
		cout << pemain1 << " silahkan pilih nomor kotak! : ";
		cin >> no_kotak;
	}
	
	if(pemain == 'O'){
		cout << pemain2 << " silahkan pilih nomor kotak! : ";
		cin >> no_kotak;
	}
	
	if(no_kotak == 1){
		baris = 0;
		kolom = 0;
		nomor[0][0];
	}else if(no_kotak == 2){
		baris = 0;
		kolom = 1;
		nomor[0][1];
	}else if(no_kotak == 3){
		baris = 0;
		kolom = 2;
		nomor[0][2];
	}else if(no_kotak == 4){
		baris = 1;
		kolom = 0;
		nomor[1][0];
	}else if(no_kotak == 5){
		baris = 1;
		kolom = 1;
		nomor[1][1];
	}else if(no_kotak == 6){
		baris = 1;
		kolom = 2;
		nomor[1][2];
	}else if(no_kotak == 7){
		baris = 2;
		kolom = 0;
		nomor[2][0];
	}else if(no_kotak == 8){
		baris = 2;
		kolom = 1;
		nomor[2][1];
	}else if(no_kotak == 9){
		baris = 2;
		kolom = 2;
		nomor[2][2];
	}else{
		cout << "Masukkan angka yang diminta!!!" << endl;
		angka_ke_baris_dan_kolom();
	}
	
	if(pemain == 'X' && nomor[baris][kolom] != 'X' && nomor[baris][kolom] != 'O'){
		nomor[baris][kolom] = 'X';
		pemain = 'O';
	}else if(pemain == 'O' && nomor[baris][kolom] != 'X' && nomor[baris][kolom] != 'O'){
		nomor[baris][kolom] = 'O';
		pemain = 'X';
	}else{
		cout << "Kotak sudah terisi! Pilih kotak lain!" << endl;
		angka_ke_baris_dan_kolom();
	}
}

bool cek_menang_atau_seimbang(){
	
	//kondisi apabila salah satu pemain mendapat satu baris atau satu kolom yang sama
	for(int a = 0; a < 3; a++){
		if(nomor[a][0] == nomor[a][1] && nomor[a][1] == nomor[a][2] || nomor[0][a] == nomor[1][a] && nomor[1][a] == nomor[2][a]){
		seimbang = true;
		return true;
		}
	}
	//cek kondisi apabila salah satu pemain mendapat satu 
	if(nomor[0][0] == nomor[1][1] && nomor[1][1] == nomor[2][2] || nomor[0][2] == nomor[1][1] && nomor[1][1] == nomor[2][0]){
		seimbang = true;
		return true;
	}
	else{
		//cek kondisi apabila masih terdapat kotak yang masih kosong untuk lanjut bermain
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(nomor[i][j] != 'X' && nomor[i][j] != 'O'){
					return false;				
				}
			}
		}
		seimbang = false;
		return true;
	}
}

int main(){
	
	cout << "Masukkan nama pemain 1 : ";
	getline(cin, pemain1);
	cout << "Masukkan nama pemain 2 : ";
	getline(cin, pemain2);
	
	cout << pemain1 << " bermain sebagai 'X' dan " << pemain2 << " bermain sebagai 'O'\n" << endl;
	
	while(!cek_menang_atau_seimbang()){
		papan_game();
		angka_ke_baris_dan_kolom();
		cek_menang_atau_seimbang();
	}
	
	papan_game();
	if(pemain == 'X' && seimbang == true){
		cout << "SELAMAT " << pemain2 << " MENANG" << endl;
	}else if(pemain == 'O' && seimbang == true){
		cout << "SELAMAT " << pemain1 << " MENANG" << endl;
	}else{
		cout << "PERMAINAN SERI" << endl;
	}
	return 0;
}
