#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class string1
{
      private:
              char *text;  // Zeichenkette mit '\0' als Endekennzeichen
      
      public:
             string1(char *t)
             {
               if (t==NULL)
                 text = NULL;
               else { text = new char[strlen(t)+1];
                      strcpy(text,t);
                    };
             };
             ~string1()
             {
               delete text;
             };
             
             string1(const string1& s1)
             {
               if (s1.text==NULL)
                 text = NULL;
               else { text = new char[strlen(s1.text)+1];
                      strcpy(text,s1.text);
                    };
             };
             
             void textaus()
             {
               if (text != NULL)
                 cout << text;
             };
      

      
      
};

class string2
{     private:
              char *text;  // Zeichenkette ohne \0 als Endekennzeichen
              int laenge;  // Kennzeichnet die Länge
      
      public:
             string2(char *t)
             {
               if (t==NULL)
               { text = NULL;
                 laenge = 0;
               } 
               else { text = new char[strlen(t)];
                      strncpy(text,t, strlen(t));
                      laenge = strlen(t);
                    };
             };
             ~string2()
             {
               delete text;
             };
             void textaus()
             { 
               if (text != NULL)
               {
                 for (int i=0; i<laenge; i++)
                   cout << text[i];
               }
             };
             
             string2(const string2& s)
             {
               text = new char[s.laenge];
               for (int i=0; i< s.laenge;i++)
                 text[i] = s.text[i];
               laenge = s.laenge;
             };
             

};

          
int main()
{
  char testtext[100];
  cout << "Bitte Text fuer ein Objekt der Klasse string1 eigeben (max 100 Zeichen)" << endl;
  cin >> testtext;
  
  string1 teststring1(testtext);
  teststring1.textaus();
  cout << endl;
  
  char testtext2[100];
  cout << "Bitte Text fuer ein Objekt der Klasse string2 eigeben (max 100 Zeichen)" << endl;
  cin >> testtext2;
  
  string2 teststring2(testtext2);
  teststring2.textaus();
  cout << endl;
  

  
  system("PAUSE");

  return 0;
} 
             
      
