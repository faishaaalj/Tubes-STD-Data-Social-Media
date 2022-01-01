#include <iostream>
#include "tubess.h"
#include <stdlib.h>

/*  TUGAS BESAR STRUKTUR DATA (SOAL NO.6 DATA SOSIAL MEDIA)
    ANGGOTA KELOMPOK : 1. AULIA ALIEF RACHMANDA (1301194109)
                       2. FAISHAL JANUARAHMAN (1301194049)
    KELAS            : IF-43-02

*/

using namespace std;

int main()
{
    int i;
    string nama, nama2, tahun, nomor,found, max;
    bool cek;
    list_group lg;
    list_netizen ln;
    adr_group P, Y;
    adr_netizen q;


    createGroup(lg);
    createNetizen(ln);

    while (i!=10) {
        cout << "================================================" << endl;
        cout << "1. Penambahan data group" << endl;
        cout << "2. Penambahan data netizen" << endl;
        cout << "3. Penentuan relasi group dan netizen " << endl;
        cout << "4. Menghapus data group" << endl;
        cout << "5. Manghapus data netizen" << endl;
        cout << "6. Menampilkan data keseluruhan group beserta data membernya" << endl;
        cout << "7. Menampilkan data group yang memiliki member tertentu." << endl;
        cout << "8. Menampilkan data netizen yang menjadi member di suatu group tertentu" << endl;
        cout << "9. Menampilkan data group yang memiliki member paling banyak dan sedikit" << endl;
        cout << "10. EXIT" << endl;
        cout << endl;
        cout << "Masukkan Pilihan : ";
        cin >> i;

        switch(i){
        case(1):
            cout << "Masukkan Nama Group : ";
            cin >>nama;
            cout << "Masukkan tahun dibentuk : ";
            cin >>tahun;
            P = allocateGroup(nama,tahun);
            insertFirstGroup(lg,P);
            break;
        case(2):
            cout << "Masukkan Nama Anda : ";
            cin >> nama2;
            cout << "Masukkan Nomor HP : ";
            cin >> nomor;
            q = allocateNetizen(nama2,nomor);
            insertFirstNetizen(ln,q);
            break;
        case(3):
            cout << "Nama Group : ";
            cin >> nama;
            cout << "Nama Netizen : ";
            cin >> nama2;
            makeRelation(ln,lg,nama,nama2);
            break;
        case(4):
            cout << "Masukkan Nama Group : ";
            cin >> nama;
            deleteGroup(lg,nama);
            break;
        case(5):
            cout << "Masukkan nama Group dari netizen yang ingin dihapus : ";
            cin >> nama;
            cout << "Masukkan nama netizen yang ingin dihapus : ";
            cin >> nama2;
            deleteNetizen(lg,ln,nama,nama2);
            break;
        case(6):
            printAll(lg);
            break;
        case(7):
            cout << "Masukkan Nama Netizen : ";
            cin >> nama2;
            found = printSebagianGroup(lg,ln,nama2);
            cout << "Berada pada grup : " << found <<  endl;
            break;
        case(8):
            cout << "Masukkan Nama Group : ";
            cin >> nama;
            cek = cekGroup(lg, nama);
            if (cek==true) {
                cout << "========== DATA NETIZEN ===========" << endl;
                printSebagian(lg,nama);
            } else {
                cout << "Group tidak terdaftar" << endl;
            }
            break;
        case(9):
            BanyakSedikit(lg);

        }
    }

}
