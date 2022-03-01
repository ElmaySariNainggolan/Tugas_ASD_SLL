#include <iostream>
#include<conio.h>
#include<windows.h>
#include <stdio.h>
using namespace std;

int pil;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();

struct simpul{
 char npm[8], nama[80];
 int umur;
 struct simpul *next;
}mhs, *baru, *awal=NULL, *akhir=NULL, *hapus, *bantu;

void clrscr(){
 system("cls");
}

int main(){
 do{
  clrscr();
  cout << "Menu Single Linked List\n" << endl;
  cout << "1. Tambah data awal" << endl;
  cout << "2. Tambah data akhir" << endl;
  cout << "3. Hapus data awal" << endl;
  cout << "4. Hapus data akhir" << endl;
  cout << "5. Tampil" << endl;
  cout << "6. Selesai\n" << endl;
  cout << "Pilihan anda: ";
  cin>>pil;
  pilih();
 }
 while (pil!=6);
 return 0;
}

void pilih(){
 if(pil==1){
  tambah_depan();
 }
 else if(pil==2){
  tambah_belakang();
 }
 else if(pil==3){
  hapus_depan();
 }
 else if(pil==4){
  hapus_belakang();
 }
 else if(pil==5){
  tampil();
 }
}

void buat_baru(){
 baru=(simpul*)malloc(sizeof(struct simpul));
 cout << "Input Nama : ";
 cin >> baru->npm;
 cout << "Input NPM : ";
 cin >>baru->nama;
 cout << "Input Usia : ";
 cin >> baru->umur;
 baru->next=NULL;
}

void tambah_belakang(){
 buat_baru();
 if(awal==NULL){
  awal=baru;
 }
 else{ 
  akhir->next=baru;
 }
 akhir=baru;
 akhir->next=NULL;
 cout << endl << endl;
 tampil();
}

void tambah_depan(){
 buat_baru();
 if(awal==NULL){
  awal=baru;
  akhir=baru;
  akhir->next=NULL;
 }
 else{
  baru->next=awal;
  awal=baru;
 }
 cout << endl << endl;
 tampil();
}

void hapus_depan(){
 if(awal==NULL){
  cout<<"kosong";
 }
 else{
  hapus = awal;
  awal=awal->next;
  free(hapus);
 }
 cout << endl << endl;
 tampil();
}

void hapus_belakang(){
 if(awal==NULL){
  cout << "Kosong";
 }
 else if(awal==akhir){
  hapus = awal;
  awal=awal->next;
  free(hapus);
 }
 else{
  hapus = awal;
  while(hapus->next != akhir){
   hapus = hapus->next;
   akhir=hapus;
   hapus=akhir->next;
   akhir->next=NULL;
   free(hapus);
  }
 }
 cout << endl << endl;
 tampil();
}

void tampil(){
 if(awal==NULL){
  cout << "Kosong";
 }
 else{
  bantu=awal;
  while(bantu!=NULL){
   cout << "NAMA : " << bantu->npm << endl;
   cout << "NPM : " << bantu->nama << endl;
   cout << "USIA : " << bantu->umur << endl;

 
   bantu=bantu->next;
  }
 }
 getch();
}

