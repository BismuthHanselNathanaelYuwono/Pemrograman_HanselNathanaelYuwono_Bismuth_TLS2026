#include<iostream>

using namespace std;

void EliminasiIndex(int arr[], int &size, int targetIndex){
    for (int i = targetIndex; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
    size--;
}

int SisaBagi(int nomor, int pembagi){
    return nomor % pembagi;
}

int main(){
    int N, K;

    cout<<"Masukkan jumlah astronot (N): ";
    cin>>N;
    cout<<"Masukkan nilai awal K: ";
    cin>>K;

    int astronot[1000];
    int currentSize = N;

    for (int i = 0; i < N; i++){
        astronot[i] = i + 1;
    }

    int idx = 0;

    cout<<endl;
    cout<<"Urutan astronot yang dieliminasi:"<<endl;

    while (currentSize > 1){
        idx = SisaBagi(idx + K - 1, currentSize);

        int nomoreleminasi = astronot[idx];
        cout<<"Astronot "<<nomoreleminasi<<" tereliminasi"<<endl;

        EliminasiIndex(astronot, currentSize, idx);

        if (nomoreleminasi % 2 == 0){
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }
    }

    cout<<endl;
    cout<<"Astronot terakhir yang bertahan: Astronot "<<astronot[0]<<endl;

    return 0;
}