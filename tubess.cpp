#include <iostream>
#include "tubess.h"

/*  TUGAS BESAR STRUKTUR DATA (SOAL NO.6 DATA SOSIAL MEDIA)
    ANGGOTA KELOMPOK : 1. AULIA ALIEF RACHMANDA (1301194109)
                       2. FAISHAL JANUARAHMAN (1301194049)
    KELAS            : IF-43-02

*/

using namespace std;

void createGroup(list_group &lg) {
    first(lg) = NULL;
    last(lg) = NULL;
}
void createNetizen(list_netizen &ln) {
    first(ln) = NULL;
    last(ln) = NULL;
}

adr_netizen allocateNetizen(string nama, string nomor) {
    adr_netizen P;

    P = new elm_netizen;
    info(P).nama = nama;
    info(P).nomor = nomor;
    next(P) = NULL;
    prev(P) = NULL;
}

adr_group allocateGroup(string nama, string tahun) {
    adr_group P;

    P = new elm_group;
    info(P).nama = nama;
    info(P).tahun = tahun;
    next(P) = NULL;
    prev(P) = NULL;
}

bool cekGroup(list_group lg, string nama) {
    adr_group P;

    P = first(lg);
    if(first(lg) == NULL) {
        return true;
    } else {
        while ((P != last(lg))&& (info(P).nama != nama)) {
            P = next(P);
        }
    }
    if (info(P).nama == nama) {
        return true;
    } else {
        return false;
    }
}

void insertFirstGroup(list_group &lg, adr_group P) {
    bool cek = cekGroup(lg, info(P).nama);
    if (first(lg) != NULL) {
        if(cek==false) {
            next(P) = first(lg);
            prev(first(lg)) = P;
            first(lg) = P;
        } else {
            cout <<"Group sudah terdaftar"<<endl;
        }
    } else {
        first(lg) = P;
        last(lg) = P;
    }
}

bool cekNetizen(list_netizen ln, string nama) {
    adr_netizen P = first(ln);

    if(first(ln) != NULL) {
        while((P != last(ln)) && (info(P).nama != nama)) {
            P = next(P);
        }
    } else {
        return true;
    }
    if (info(P).nama == nama) {
        return true;
    } else {
        return false;
    }
}

void insertFirstNetizen(list_netizen &ln, adr_netizen P) {
    bool cek = cekNetizen(ln, info(P).nama);
    if (first(ln)!= NULL) {
        if (cek==true) {
            cout << "Netizen sudah terdaftar" << endl;
        } else {
            next(P) = first(ln);
            prev(first(ln)) = P;
            first(ln) = P;
        }
    } else {
        first(ln) = P;
        last(ln) = P;
    }
}

adr_group findGroup(list_group lg, string nama) {
    adr_group P = first(lg);

    if (first(lg) == NULL) {
        return NULL;
    } else {
        while ((info(P).nama != nama) && (P != last(lg))) {
            P = next(P);
        }
    }
    if (info(P).nama == nama) {
        return P;
    } else {
        return NULL;
    }
}

adr_netizen findNetizen(list_netizen ln, string nama) {
    adr_netizen P = first(ln);

    if (first(ln) == NULL) {
        return NULL;
    } else {
        while ((info(P).nama != nama) && (P != last(ln))){
            P = next(P);
        }
    }
    if (info(P).nama == nama) {
        return P;
    } else {
        return NULL;
    }
}

bool cekin(list_group lg, adr_netizen tmp, adr_group P) {
    adr_netizen q = P->listhub.first;

    if(P->listhub.first != NULL) {
        while (q!=NULL) {
            if(info(q).nama == info(tmp).nama) {
                q = q->next;
            } else {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

void makeRelation(list_netizen &ln, list_group &lg, string a, string b) {
    bool cek = false;

    adr_group P = findGroup(lg,a);
    adr_netizen q = findNetizen(ln, b);

    if((P!=NULL)&&(q!=NULL)) {
        adr_netizen tmp = allocateNetizen(info(q).nama, info(q).nomor);
        cek = cekin(lg,tmp,P);
        if (cek != true) {
            if (P->listhub.first != NULL) {
                tmp->next = P->listhub.first;
                prev(P->listhub.first) = tmp;
                P->listhub.first = tmp;
            } else {
                P->listhub.first = tmp;
                P->listhub.last = tmp;
            }
            cout << "==== RELASI BERHASIL ===="  << endl;
        } else {
            cout << "Data invalid" << endl;
        }
    } else if ((P != NULL) && (q==NULL)) {
        cout << "Netizen tidak ditemukan" << endl;
    } else if ((P==NULL) && (q!=NULL)) {
        cout << "Grup tidak ditemukan" << endl;
    } else {
        cout << "List Kosong" << endl;
    }
}

void printGroup(list_group lg) {
    adr_group P = first(lg);

    if (first(lg)!=NULL) {
        while(P!=NULL) {
            cout << "Nama : " << info(P).nama << endl;
            cout << "Tahun dibentuk : " << info(P).tahun << endl;
            P = next(P);
        }
    } else {
        cout << "List Kosong" << endl;
    }
}

void printNetizen(list_netizen ln) {
    adr_netizen P = first(ln);

    if (first(ln)!=NULL) {
        while (P!=NULL) {
            cout << "Nama : " << info(P).nama << endl;
            cout << "Nomor HP : " << info(P).nomor << endl;
        }
    } else {
        cout << "List Kosong" << endl;
    }
}

void printAll(list_group lg) {
    adr_group P = first(lg);

    if (first(lg)!=NULL) {
        while (P!=NULL) {
            adr_netizen q = P->listhub.first;
            cout << "======= LIST GROUP ======== " << endl;
            cout << "Nama Group : " << info(P).nama << endl;
            cout << "Tahun Dibentuk : " << info(P).tahun << endl;
            if (P->listhub.first != NULL) {
                cout << "-ANGGOTA- " << endl;
                while(q!=NULL) {
                    cout << "---" << endl;
                    cout << "Nama : " << info(q).nama << endl;
                    cout << "Nomor HP : " << info(q).nomor << endl;
                    q = q->next;
                }
            }
            P = next(P);
        }
    } else {
        cout << "List Kosong" << endl;
    }
}

void printSebagian(list_group lg, string nama) {
    adr_group P = findGroup(lg,nama);

    if (P!=NULL) {
        adr_netizen q = P->listhub.first;
        while (q!=NULL) {
            cout << "Nama : " << info(q).nama << endl;
            cout << "Nomor HP : " << info(q).nomor << endl;
            q = q->next;
        }
    } else {
        cout << "Data Invalid" << endl;
    }
}
string printSebagianGroup(list_group lg,list_netizen ln, string nama) {
    adr_netizen q = findNetizen(ln,nama);
    adr_group P = first(lg);
    while (P!=NULL) {
        adr_netizen z = P->listhub.first;
        while((info(z).nama != info(q).nama) && (z != NULL)) {
            z = z->next;
        }
        if (info(z).nama == info(q).nama) {
            return info(P).nama;
        } else {
             P = P->next;
        }

    }
    return "TIDAK DITEMUKAN";

}



adr_netizen findisi(adr_group P, string x) {
    if(P->listhub.first == NULL) {
        return NULL;
    } else{
        adr_netizen q = P->listhub.first;
        while((q!=NULL) && (info(q).nama!=x)) {
            q = q->next;
        }
        if(info(q).nama==x){
            return q;
        } else {
            return NULL;
        }
    }
}

void deleteNetizen(list_group lg, list_netizen ln, string x, string y){
    adr_group P =  findGroup(lg,x);

    if(P!=NULL) {
        adr_netizen q = findisi(P,y);
        if(q!=NULL) {
            if((q == P->listhub.first) && (q == P->listhub.last)) {
                P->listhub.first = NULL;
                P->listhub.last = NULL;
            } else if(q == P->listhub.first) {
                P->listhub.first = q->next;
                prev(P->listhub.first) = NULL;
                q->next = NULL;
            } else if(q == P->listhub.last) {
                P->listhub.last = prev(q);
                next(P->listhub.last) = NULL;
                prev(q) = NULL;
            } else {
                next(prev(q)) = next(q);
                q->next->prev = q->prev;
                next(q) = NULL;
                prev(q) = NULL;
            }
        } else {
            cout << "Netizen Invalid" << endl;
        }
    } else {
        cout << "Data Invalid" << endl;
    }
}
void deleteGroup(list_group &lg, string x) {
    adr_group P = findGroup(lg,x);

    if(P!=NULL) {
        if((P == first(lg)) && (P == last(lg))) {
            first(lg) = NULL;
            last(lg) = NULL;
        } else if (P == first(lg)) {
            first(lg) = next(P);
            prev(first(lg)) = NULL;
            next(P) = NULL;
        } else if (P == last(lg)) {
            last(lg) = prev(P);
            next(last(lg)) = NULL;
            prev(P) = NULL;
        } else {
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    } else {
        cout << "Data Invalid" << endl;
    }


}

void BanyakSedikit(list_group lg){
    string banyak, sedikit;
    adr_group P = first(lg);
    adr_netizen q;
    int recBanyak, recSedikit, i;
    recBanyak = 0;
    recSedikit = 0;
    while(P != NULL){
        i = 0;
        q = P->listhub.first;
        while(q != NULL){
            i++;
            q = q->next;
        }
        if(i > recBanyak){
            recBanyak = i;
            banyak = info(P).nama;
        } else if(i <= recSedikit){
            recSedikit = i;
            sedikit = info(P).nama;
        }

        P = next(P);
    }
    cout<<"Group yang memiliki member paling banyak : "<<banyak<<endl;
    cout<<"Group yang memiliki member paling sedikit : "<<sedikit<<endl;
}
