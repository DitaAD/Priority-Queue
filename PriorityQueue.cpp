#include <iostream>
#include <windows.h>
#include <stdio.h>
#define maks 5

using namespace std;

class Queue {
     
      friend ostream& operator<<(ostream&, const Queue&);

      public :       
             Queue();
             void print();//deklrasi fungsi cetak
             void enqueue(int);//deklrasi fungsi enqueue
             int penuh(int); //deklrasi variabel  penuh
             int kosong(int);//deklrasi variabel  kosong
             int dequeue();//deklrasi variabel  dequeue
             int PrioritasMax();//deklrasi variabel prioritas besar
             int PrioritasMin();//deklrasi variabel prioritaas kecil
             int maxsi();//deklrasi variabel  max
             int indeksMak();//deklrasi variabel  indek max
             int min();//deklrasi variabel  min
             int indeksMin();//deklrasi variabel  index min

      private :
              int A[maks];///deklarasi array A (maks)
              int banyak;//deklarasi varibael banyak

};
//menampilkan isi antrian
ostream& operator<<(ostream& out, const Queue& s){
         cout << "\nIsi Queue : ";
         for (int i=s.banyak-1; i>=0; i--)
             out << s.A[i] << " ";
    
}
//operasi antrian
Queue::Queue() {
               banyak = 0;//variabel bnayak sama dengan 0
               for (int i=0; i<maks; i++)
                   A[i] = '0';
}
//operasi kondisi saat penuh
int Queue::penuh(int s){
    return s == maks ? 1 : 0;
}
//operasi kondisi saat kosong
int Queue::kosong(int s) {
    return s == 0 ? 1 : 0;
    }
//operasi fungsi cetak antrian
void Queue::print(){
     cout << "\nIsi Queue : ";

     for (int i=0; i<banyak; i++)
         cout << A[i] << " ";
}
 //operasi fungsi masuk antrian
void Queue::enqueue(int x){
     cout  << x << " MASUK";
     if (penuh(banyak)) cout << "queue penuh";
     else {
         A[banyak] = x;
         banyak++;
     }
}
//operasi keluar antrian
int Queue::dequeue() {
     if(banyak == 0) cout<<"Data masih kosong."<<endl;
     else {
         int temp=A[0];
         cout << "\nDequeue elemen --> " << temp;
         banyak--;
        for(int i=0;i<5;i++){
            A[i] = A[i+1];
        }
         return temp;
     }
}
//operasi antrian bilangan besar
int Queue::maxsi(){
    int mak;
    for(int i=0;i<banyak;i++){
        if(i==0){
            mak = A[i];
        } else {
            if(mak < A[i]){
                mak = A[i];   
            }
        }
    }
    return mak;
}
//operasi indek ke antrian
int Queue::indeksMak(){
    int dek;
    for(int i=0;i<banyak;i++){
        if(A[i] == maxsi()){
            dek = i;
            break;
        }
    }
    return dek;
}
//operasi antrian bilangan prioritas besar
int Queue::PrioritasMax(){
    int dequeue;
    int ind;
    if(banyak == 0)cout<<"DATA KOSONG"<<endl;
    else {
         dequeue = maxsi();
         ind = indeksMak();
         for(int i=0;i<banyak;i++){
             if(i>=ind){
                 A[i] = A[i+1];
             }
         }
         banyak--;
     }
     return dequeue;
}
//operasi antrian kecil
int Queue::min(){
    int min;
    for(int i=0;i<banyak;i++){
        if(i==0){
            min = A[i];
        } else {
            if(min > A[i]){
                min = A[i];
               
            }
        }
    }
    return min;
}
//operasi memnentukan indek bilangan kecil
int Queue::indeksMin(){
    int dek;
    for(int i=0;i<banyak;i++){
        if(A[i] == min()){
            dek = i;
            break;
        }
    }
    return dek;
}

int Queue::PrioritasMin(){//prioritas kecil
    int dequeue;
    int ind;
    if(banyak == 0)cout<<"Data masih kosong."<<endl;
    else {
         dequeue = min();
         ind = indeksMin();
         for(int i=0;i<banyak;i++){
             if(i>=ind){
                 A[i] = A[i+1];
             }
         }
         banyak--;
   
     }
     return dequeue;
}
int main() {
       
        int r;//deklrasi variabel r
        int m;//deklarasi variabel m
       Queue q;
      
       home :
       //MENU UTAMA
       cout<<endl<<"Pilih menu utama: "<<endl<<endl;
       cout<<"1. ASCENDING PRIORITAS  ";
       cout<<"2. DESCENDING PRIORITAS   ";
       cout<<endl<<endl;
       cout<<"pilih menu : "; cin>>r;//input pilihan ke menu dengan variabel x
       switch(r){
            case 1 : //pemilihan 1
                goto ascending;//masuk ascending
                break;
            case 2 ://pemilihan 2
                goto descending;//masuk descending
                break;
            case 3 ://pemilihan 3
                goto ext;//keluar
                break;       
            default :
                goto home;//masuk awal utama
                break;   
           
       }
      
       descending :
       cout<<endl<<"DESCENDING PRIORITAS QUEUE: "<<endl;
       cout<<"1. ENQUE"<<endl;
       cout<<"2. DENQUE"<<endl;
       cout<<"3. TAMPILKAN"<<endl;
       cout<<"4. EXIT"<<endl;
       cout<<"masukkan menu ke : "; cin>>r;//input elemen ke variabel x
       switch(r){
            case 1 :
                cout<<"Masukkan data : "; cin>>m;//input elemen ke m
                q.enqueue(m);//varibael q sama dengan m
                goto descending;//masuk descending
                break;
            case 2 :
                cout<<"Yang di dequeue adalah "<<q.PrioritasMax()<<endl;//menampilkan hasil deque variabel q
                goto descending;//masuk deqending
                break;
            case 3 :
                q.print();//mencetak variabel q
                goto descending;//masuk desecending
                break;   
            case 4 ://pemilihan 4
                goto home;//masuk menu awal
                break;       
            default :
                goto descending;//masuk descending
                break;   
           
       }
      
      
       //min
       ascending :
       cout<<endl<<"ASCENDING PRIORITAS : "<<endl;
       cout<<"1. ENQUE"<<endl;//Outtput Enque
       cout<<"2. DEQUE"<<endl;//output DEque
       cout<<"3. TAMPILKAN"<<endl;//output tampilkan
       cout<<"4. EXIT"<<endl;//output keluar
       cout<<"masukkan menu ke : "; cin>>r;//pemilihan dengan input var.x
       switch(r){
            case 1 : //pemilihan 1
                cout<<"MASUK ANTRIAN : "; cin>>m;//input antrian ke variabel m
                q.enqueue(m);//antrian q sama dengan m
                goto ascending;//masuk ke ascending
                break;
            case 2 :
                cout<<"YANG KELUAR = "<<q.PrioritasMin()<<endl;//menampilkan elemen keluar prio.kecil
                goto ascending;//masuk ke ascending
                break;
            case 3 ://pemilihan 3
                q.print();//mencetak variabel q
                goto ascending;//masuk ke ascending
                break;   
            case 4 ://pemilihan 4
                goto home;//masuk ke menu awal home
                break;       
            default :
                goto ascending;//masuk ke ascending
                break;   
           
       }
        ext :
       system("PAUSE");
       return 0;

}
