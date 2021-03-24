#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H_LAENGE 20
#define M_LAENGE 20
#define K_LAENGE 50

enum Einsatz {s,b};

class Fahrzeug
{ private:
    char Hersteller[H_LAENGE];
    char Modell[M_LAENGE];
    unsigned int Motorleistung;
  
  public:
    Fahrzeug(const char H[], const char M[], unsigned int L)
    {
      if (strlen(H) < H_LAENGE)            
        strcpy(Hersteller,H);
      else printf("Falsche Herstellerangabe\n");
      if (strlen(M) < M_LAENGE)            
        strcpy(Modell,M);
      else printf("Falsche Modellangabe\n");
      Motorleistung = L; 
    }  
    
    // weitere Methoden sind hier nicht aufgeführt   
};

class Kfz_Versicherung
{
  private:
    Fahrzeug V_Fahrzeug;  // versichertes Fahrzeug
    unsigned int Nummer;  // Versicherungsnummer
    char Kunde[K_LAENGE]; // Versicherungsnehmer
  
  public:
    Kfz_Versicherung(const char Hersteller[H_LAENGE], const char Modell[M_LAENGE], unsigned int Leistung, unsigned int Nr, const char Kd[K_LAENGE])
            
             
    {
      Nummer = Nr;
      if (strlen(Kd) < K_LAENGE)            
        strcpy(Kunde,Kd);
      else printf("Falsche Kundenangabe\n");
    };
    
    // weitere Methoden sind hier nicht aufgeführt  
};

int main()
{
  Kfz_Versicherung Meine_Versicherung("Audi","A4",100, 12345,"Hans Meier");
  system("PAUSE");
  return 0;
}
