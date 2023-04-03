#include <iostream>

using namespace std;

/* Deklarasi variabel */
char giliran = 'X', konfirmasi, isi_papan[3][3] =   {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}, array_angka[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int gerakan, count = 0, kolom, baris, angka = 0;
bool run = true, cek = false, bermain = true;

class tic_tac_toe {
public:
    /* Method non-return type */
    void kolom_baris(){
        switch (gerakan)
        {
        case 1:
            baris = 0;
            kolom = 0;
            break;
        case 2:
            baris = 0;
            kolom = 1;
            break;
        case 3:
            baris = 0;
            kolom = 2;
            break;
        case 4:
            baris = 1;
            kolom = 0;
            break;
        case 5:
            baris = 1;
            kolom = 1;
            break;
        case 6:
            baris = 1;
            kolom = 2;
            break;
        case 7:
            baris = 2;
            kolom = 0;
            break;
        case 8:
            baris = 2;
            kolom = 1;
            break;
        case 9:
            baris = 2;
            kolom = 2;
            break;
        default:
        cout << "Angka tidak tersedia" << endl;
        break;
        }
    }

};
tic_tac_toe method;

/* Function non-return type */
void print_papan(){
    cout << isi_papan[0][0] << " | " << isi_papan[0][1] << " | " << isi_papan[0][2] << endl;
    cout << "--+---+--" << endl;
    cout << isi_papan[1][0] << " | " << isi_papan[1][1] << " | " << isi_papan[1][2] << endl;
    cout << "--+---+--" << endl;
    cout << isi_papan[2][0] << " | " << isi_papan[2][1] << " | " << isi_papan[2][2] << endl << endl;
}

/* Funtion return type tanpa parameter */
bool pengecekan(){
    for (int i = 0; i < 3; i++){
    if ((isi_papan[i][0] == isi_papan[i][1] && isi_papan[i][0] == isi_papan[i][2]) || (isi_papan[0][i] == isi_papan[1][i] && isi_papan[0][i] == isi_papan[2][i]))
    {
        return true;
    } 
    } if ((isi_papan[0][0] == isi_papan[1][1] && isi_papan[0][0] == isi_papan[2][2]) || (isi_papan[0][2] == isi_papan[1][1] && isi_papan[0][2] == isi_papan[2][0]))
    {
        return true;
    }
    return false;
}

/* Function non-return type */
void game(){
    while (run)
    {
        print_papan();
        cout << "Giliran " << giliran << endl;
        cout << "Silakan masukkan angka yang anda inginkan" << endl;
        cin >> gerakan;
        cout << endl;
        method.kolom_baris();
        if (isi_papan[baris][kolom] != 'X' && isi_papan[baris][kolom] != 'O') {
            isi_papan[baris][kolom] = giliran;
            count++;
            cout << "Pemain " << giliran << " memasukkan ke kotak " << gerakan << endl << endl;}
        else {
            cout << "Kotak sudah terisi, silakan pilih kotak lain" << endl;
            continue;
        }
        
        if (count >= 5){
            cek = pengecekan();
            if (cek) {
                print_papan();
                cout << "Selamat " << giliran << " menang!!!" << endl;
                run = false;
            }
        }
        
        if (giliran == 'X'){   
            giliran = 'O';} 
        else {
            giliran = 'X';}
        
        if (count == 9){
            cout << "Permainan seri!" << endl;
            run = false;}
    }
}

int main()
{
    
    return 0;
}
