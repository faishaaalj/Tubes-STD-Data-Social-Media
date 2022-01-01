#ifndef TUBESS_H_INCLUDED
#define TUBESS_H_INCLUDED
#include <iostream>
#define Nill NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(P) P.first
#define last(P) P.last

/*  TUGAS BESAR STRUKTUR DATA (SOAL NO.6 DATA SOSIAL MEDIA)
    ANGGOTA KELOMPOK : 1. AULIA ALIEF RACHMANDA (1301194109)
                       2. FAISHAL JANUARAHMAN (1301194049)
    KELAS            : IF-43-02

*/



using namespace std;

struct info_netizen {
    string nama;
    string nomor;
};

typedef struct elm_netizen *adr_netizen;

struct elm_netizen {
    info_netizen info;
    adr_netizen next;
    adr_netizen prev;
};

struct list_netizen {
    adr_netizen first;
    adr_netizen last;
};

struct info_group {
    string nama;
    string tahun;
};

typedef struct elm_group *adr_group;

struct elm_group {
    info_group info;
    adr_group next;
    adr_group prev;
    list_netizen listhub;
};

struct list_group {
    adr_group first;
    adr_group last;
};



void createGroup(list_group &lg);
void createNetizen(list_netizen &ln);
adr_netizen allocateNetizen(string nama, string nomor);
adr_group allocateGroup(string nama, string tahun);
bool cekGroup(list_group lg, string nama);
void insertFirstGroup(list_group &lg, adr_group P);
bool cekNetizen(list_netizen ln, string nama);
void insertFirstNetizen(list_netizen &ln, adr_netizen P);
adr_group findGroup(list_group lg, string nama);
adr_netizen findNetizen(list_netizen ln, string nama);
bool cekin(list_group lg, adr_netizen tmp, adr_group P);
void makeRelation(list_netizen &ln, list_group &lg, string a, string b);
void printGroup(list_group lg);
void printNetizen(list_netizen ln);
void printAll(list_group lg);
void printSebagian(list_group lg, string nama);
string printSebagianGroup(list_group lg,list_netizen ln, string nama);
adr_netizen findisi(adr_group P, string x);
void deleteNetizen(list_group lg, list_netizen ln, string x, string y);
void deleteGroup(list_group &lg, string x);
void BanyakSedikit(list_group lg);





#endif // TUBESS_H_INCLUDED
