#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int dimensioneMax=100;


//prototipi
int caricaVettore(float numeri[]);
float media(int n, float num[]);
void caricaScarti(int n, float v[], float v2[], float m);
void scartoQuadraticoMedio(int n, float v2[]);
void OrdinamentoERicerca(float v[], float v2[], int n);
void Ordinamento(float v[], int n);
void Ricerca(float v[], int n);
void stampa(float v[], int n);
int MiniMenu();
int Menu();


int main() {
    
    float valori[dimensioneMax];
    float scarti[dimensioneMax];
    float m=0.00;
    int n;
    int scelta;
    
    n=caricaVettore(valori);
    
    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
                stampa(valori, n);
            break;
            case 2:
                m=media(n, valori);
                caricaScarti(n, valori, scarti, m);
            break;
            case 3:
                scartoQuadraticoMedio(n, scarti);
            break;
            case 4:
                OrdinamentoERicerca(valori, scarti, n);
            break;
            case 0:
                cout<<"Esci"<<endl;
            break;
            default:
                cout<<"Attenzione, scelta sbagliata!"<<endl;
            break;
        }
    }while(scelta!=0);

    return 0;
}


int Menu() {
  int scegli;
  cout<<"-----------------MENU-----------------"<<endl;
  cout<<"1-Stampa vettore VALORI"<<endl;
  cout<<"2-Carica vettore SCARTI"<<endl;
  cout<<"3-Calcola scarto quadratico medio"<<endl;
  cout<<"4-Ricerca dicotomica"<<endl;
  cout<<"0-Fine"<<endl;
  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}

int caricaVettore(float numeri[]) {
    
    int i=0;
    char risp;
    
    do {
        cout<<"Inserisci una misurazione: ";
        cin>>numeri[i];
        cout<<"Vuoi inserire un'altra misurazione ? (S/N): ";
        cin>>risp;
        i++;
    }while(risp=='s'||risp=='S');
    
    return i;
    
}

float media(int n, float num[]) {
    float m=0.00;
    float s=0.00;
    
    for(int i=0; i<n; i++) {
        s=s+num[i];
    }
    
    m=s/n;
    
    return m;
}

void caricaScarti(int n, float v[], float v2[], float m) {
    
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        v2[i]=abs(v[i]-m);
    }
    
    cout<<endl;
    
    stampa(v2, n);
    
    cout<<endl;
    
    cout<<"Caricamento vettore SCARTI completato."<<endl;
    
    cout<<endl;
}

void scartoQuadraticoMedio(int n, float v2[]) {
    
    float s=0.00;
    float scartoQuadraticoMedio=0.00;
    
    for(int i=0; i<n; i++) {
        s=s+(v2[i]*v2[i]);
    }
    
    scartoQuadraticoMedio=sqrt(s/n);
    
    
    cout<<"Lo scarto quadratico medio e' : "<<scartoQuadraticoMedio;
    
    
}

void stampa(float v[], int n) {
    
    for(int i=0; i<n; i++) {
        cout<<v[i]<<endl;
    }
    
}

int MiniMenu() {
  int scegli;
  cout<<"-----------------MENU-----------------"<<endl;
  cout<<"1-Ricerca dicotomica nel vettore VALORI"<<endl;
  cout<<"2-Ricerca dicotomica nel vettore SCARTI"<<endl;
  cout<<"0-Fine"<<endl;
  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli; 
}


void OrdinamentoERicerca(float v[], float v2[], int n) {
    int scelta;
    
    do {
       scelta=MiniMenu();
       switch(scelta) {
           case 1:
               Ordinamento(v, n);
               Ricerca(v, n);
           break;
           case 2:
               Ordinamento(v2, n);
               Ricerca(v2, n);
           break;
       }
    }while(scelta!=0);
    
}

void Ordinamento(float v[], int n) {
    
    float temp;
    
    for(int i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      if(v[i]>v[j]) {
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
      }
    }
  }
    
}

void Ricerca(float v[], int n) {
  int i=0;
  int inizio=0;
  bool trovato=false;
  int fine=n-1;
  float chiave;

  cout<<"Inserisci il dato da cercare: ";
  cin>>chiave;

  while(trovato==false&&inizio<=fine) {
    i=(inizio+fine)/2;
    if(v[i]==chiave) {
      trovato=true;
    } else {
      if(v[i]>chiave) {
        fine=i-1;
      } else {
        inizio=i+1;
      }
    }
  }

  if(trovato==false) {
    cout<<"Dato non trovato"<<endl;
  } else {
    cout<<"Dato trovato"<<endl;
  }  
}
