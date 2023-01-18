#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <windows.h>

//gotoxy dari library windows
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
using namespace std;
struct
{
 char kode_hewan,kode_perawatan,jnsh[10],jp[20];
   long int jumlah_hewan,bp,st;
}cntr[5];

char nama_petugas[20],nama_pemilik[20],idl;
long int jml_data,total_bayar,uang_bayar,uang_kembali,a;


judul()
{
 cout<<"   Penitipan Hewan Pemeliharaan"<<endl;
   cout<<"       'Selamat berbelanja'"<<endl;
   cout<<"=================================="<<endl;
//   cout<<"No	Kode Hewan	Nama Hewan	Kode Perawatan	Jenis Perawatan	 Biaya Perawatan	Jumlah Hewan	Total"<<endl;
//   cout<<"1.	K	Kucing	1	Lux	 250000	3	Total"<<endl;
}


tobay()
{
 total_bayar=total_bayar+cntr[a].st;
}

main()
{
 awal:
   system("cls");
   total_bayar=0;
   judul();
   cout<<"Nama Petugas :";cin>>nama_petugas;
   cout<<"Nama Pemilik :";cin>>nama_pemilik;
   cout<<"Jumlah Data Peliharaan :";cin>>jml_data;

   for(a=1;a<=jml_data;a++)
   {
    cout<<"Hewan ke-"<<a<<endl;
      cout<<"Kode Jenis Hewan [K/H/A] :";cin>>cntr[a].kode_hewan;
      cout<<"Kode Perawatan [1/2]  :";cin>>cntr[a].kode_perawatan;
      cout<<"Jumlah Hewan     :";cin>>cntr[a].jumlah_hewan;

      if(cntr[a].kode_hewan=='K')
      {
       strcpy(cntr[a].jnsh,"Kucing");
         if(cntr[a].kode_perawatan=='1')
         {
            strcpy(cntr[a].jp,"Lux");
          cntr[a].bp=250000;
         }
         else
         {
          strcpy(cntr[a].jp,"Intensif");
            cntr[a].bp=300000;
         }
      }
      if (cntr[a].kode_hewan=='H')
      {
       strcpy(cntr[a].jnsh,"Hamster");
         if(cntr[a].kode_perawatan=='1')
         {
            strcpy(cntr[a].jp,"Lux");
          cntr[a].bp=50000;
         }
         else
         {
          strcpy(cntr[a].jp,"Intensif");
            cntr[a].bp=100000;
         }
      }
      if (cntr[a].kode_hewan=='A')
      {
       strcpy(cntr[a].jnsh,"Anjing");
         if(cntr[a].kode_perawatan=='1')
         {
            strcpy(cntr[a].jp,"Lux");
          cntr[a].bp=250000;
         }
         else
         {
          strcpy(cntr[a].jp,"Intensif");
            cntr[a].bp=100000;
         }
      }
  else
      {
      	cout << "Masukan dengan benar, lanjut" << endl;
      }
   }

   system("cls");
   judul();
   cout<<"Nama Petugas : "<<nama_petugas<<endl;
   cout<<"Nama Pemilik : "<<nama_pemilik<<endl;
   cout<<"====================================================================================="<<endl;
   cout<<"No. Kode	Nama	Kode		Jenis		Biaya		Jumlah 	total"<<endl;
   cout<<"    Hewan	Hewan	Perawatan	Perawatan	Perawatan	hewan		"<<endl;
   cout<<"====================================================================================="<<endl;
        //12345678901234567890123456789012345678901234567890
        
   for(a=1;a<=jml_data;a++)
   {
    gotoxy(1,9+a);cout<<a;
      gotoxy(6,9+a);cout<<cntr[a].kode_hewan;
      gotoxy(16,9+a);cout<<cntr[a].jnsh;
      gotoxy(26,9+a);cout<<cntr[a].kode_perawatan;
      gotoxy(42,9+a);cout<<cntr[a].jp;
      gotoxy(56,9+a);cout<<cntr[a].bp;
      gotoxy(74,9+a);cout<<cntr[a].jumlah_hewan;
      cntr[a].st=cntr[a].bp*cntr[a].jumlah_hewan;
      gotoxy(80,9+a);cout<<cntr[a].st<<endl;
      tobay();
   }
   cout<<"====================================================================================="<<endl;
   cout<<"               Total Bayar :Rp."<<total_bayar<<endl;
   cout<<"               Uang Bayar  :Rp.";cin>>uang_bayar;
   uang_kembali=uang_bayar-total_bayar;
   cout<<"               Uang Kembali:Rp."<<uang_kembali<<endl;
   cout<<"=================================================="<<endl;
   cout<<"Input data lagi [y/t] :";cin>>idl;
   if(idl=='y')
    goto awal;
   getch();
   }
