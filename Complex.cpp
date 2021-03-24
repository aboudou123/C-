#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class complex
{ float real;
  float imag;
 
  public:
   
   
  void ausgabe()
  { printf("%s%f\n","Realteil: ",real);
    printf("%s%f\n","Imagteil: ",imag);
  };
    
  void addiere(complex b)
  { real = real + b.real;
    imag = imag + b.imag;
  };
  void subtrahiere(complex b)
  { real = real - b.real;
    imag = real - b.imag;
  };
  void addiere_real(float r)
  { real = real + r;
  };
  void initialisiere(float r, float i)  
  { real = r;
    imag = i;
  };
  void lesecomplex()
  { printf("Bitte Realteil eingeben:\n");
    scanf("%f",&(real));
    printf("Bitte Imaginaerteil eingeben:\n");
    scanf("%f",&(imag));
  };  
};


