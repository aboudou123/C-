#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

using namespace std;

class Liste;

class Listenelement
{ public:
  int Element;
  Listenelement* next;
};

class Liste
{ protected:
    Listenelement *l; /* Pointer auf erstes Listenelement, NULL, falls Liste leer */
  public:
  Liste()
  { l = NULL;
  };
   
  ~Liste()
  { Listenelement *hp1, *hp2;
    hp1 = l;
    while (hp1!=NULL)
    { hp2 = hp1->next;
      delete hp1;
      hp1 = hp2;
    };
  };

  Liste(const Liste& o)
  { l = o.l;
    if (o.l != NULL)
    { l = new Listenelement;
      l->Element = o.l->Element;
      Listenelement *hp1, *hp2, *hp3;
      hp1 = o.l->next;
      hp3 = l;
      while (hp1 != NULL)
      { hp2 = new Listenelement;
        hp2->Element = hp1->Element;
        hp3->next = hp2;
        hp3 = hp3->next;
        hp1 = hp1->next;
      };
      hp3->next = NULL;
    };
  };
  
  Liste& operator=(/*const*/ Liste/*&*/ o)
  { l = o.l;
    if (o.l != NULL)
    { l = new Listenelement;
      l->Element = o.l->Element;
      Listenelement *hp1, *hp2, *hp3;
      hp1 = o.l->next;
      hp3 = l;
      while (hp1 != NULL)
      { hp2 = new Listenelement;
        hp2->Element = hp1->Element;
        hp3->next = hp2;
        hp3 = hp3->next;
        hp1 = hp1->next;
      };
      hp3->next = NULL;
    };
    return *this;
  };        
  
  void Tail()
  { if (l!=NULL)
    { Listenelement *hp = l->next;
      delete l;
      l=hp;
    }
    else cout << "Fehler: Tail mit leerer Liste aufgerufen \n";
  };
  
  void Append(int i)
  { Listenelement *hp = new Listenelement;
    hp->Element = i;
    hp->next = l;
    l=hp;
  };
  
  int isempty()
  { return (l==NULL);
  };
  
  void emptylist()
  { l=NULL;
  };
  
  int Head()
  { if (isempty())
    { cout << "Fehler: Head mit leerer Liste aufgerufen \n";
      return (0);
    }
    else return l->Element;
  };
  
  void Listenausgabe()
  { if (isempty())
     cout << "Liste ist leer\n";
    else 
    { Listenelement *hilfspointer = l;
      int i = 1;
      while (hilfspointer != NULL)
      { cout << i <<"-tes Element:" << hilfspointer->Element << endl;
        i++;
        hilfspointer = hilfspointer->next;
      };
    };
    };
}; 

int main()
{ int i;
  Liste list;
  list.emptylist();
  char c = 'x';
  while ((c != 'e') && (c != 'E'))
  { cout << "Bitte Listenoperation eingeben: a=Append, h=Head, t=Tail, p=Ausgabe, e = Ende\n";
    cin >> c;
    switch (c)
    { case 'e':
      case 'E': break;
      case 'a': 
      case 'A': cout << "Append gewaehlt\n";
                cout << "Bitte int-Zahl eingeben\n";
                cin >> i;
                list.Append(i);
                break;
      case 'h': 
      case 'H': cout << "Head gewaehlt\n";
                i = list.Head();
                cout << "Headelement: " << i;                
                break;
      case 't': 
      case 'T': cout << "Tail gewaehlt\n";
                list.Tail();
                break; 
      case 'p': 
      case 'P': cout << "Ausgabe gewaehlt\n";
                list.Listenausgabe();
                break;         
      default: break;
    }
  }; 
    system("PAUSE");
};

