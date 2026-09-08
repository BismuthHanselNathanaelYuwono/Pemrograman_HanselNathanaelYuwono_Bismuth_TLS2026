#include <iostream>

using namespace std;

int hitungPanjang(char teks[]){
    int panjang = 0;
    while (teks[panjang] != '\0'){
        panjang++;
    }
    return panjang;
}

int main(){
    char pesanAsli[100];
    char pesanSandi[100];

    cout<<"Masukkan pesan asli: ";
    cin>>pesanAsli;

    int panjang = hitungPanjang(pesanAsli);

    for (int i = 0; i < panjang; i++){
        if (i == 0){
            pesanSandi[i] = pesanAsli[i];
        } else {
            int nilaiSekarang = pesanAsli[i] - 'A' + 1;
            int nilaiSebelum = pesanAsli[i - 1] - 'A' + 1;
            int nilaiBaru = (nilaiSekarang + nilaiSebelum - 1) % 26 + 1;
            pesanSandi[i] = (nilaiBaru - 1) + 'A';
        }
    }

    pesanSandi[panjang] = '\0';

    cout<<endl;
    cout<<"Pesan yang telah di-sandi: "<<pesanSandi<<endl;

    return 0;
}