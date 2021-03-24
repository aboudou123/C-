#include <iostream>
#include <stdio.h>
using namespace std;
class complex
{ float real;
float imag;
public:
complex()
{ real = 0.0;
imag = 0.0;
};
complex(float r, float i)
{ real = r;
imag = i;
};
~complex()
{
};
// Addition zweier Complex
complex operator+(complex c)
{ complex r;
r.real = real + c.real;
r.imag = imag + c.imag;
return r;
};
// Multiplikation zweier Complex
complex operator*(complex c)
{ complex r;
r.real = real*c.real - imag*c.imag;
r.imag = imag*c.real + real*c.imag;
return r;
};
// Subtraktion zweier Complex
complex operator-(complex c)
{ complex r;
r.real = real - c.real;
r.imag = imag - c.imag;
return r;
};
friend ostream& operator<<(ostream&, complex);
};
// Ausgabe auf Bildschirm
ostream& operator<<(ostream& o, complex c)
{ o << c.real << "+" << c.imag << "i";
return o;
};
main()
{
complex c1(1.0, 2.0);
complex c2(3.0, 4.0);
complex c3(1.0, 2.0);
cout << (c1+c2) * c3 << endl;
system("PAUSE");
}
