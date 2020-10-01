#include<iostream>

void f1(void);
void f2(void);
void f3(void);
void f4(void);

int main(void)
{
  f1();
  f2();
  f3();
  f4();

  return 0;
}


void f1(void)
{
  char *z = new char [100]{};
  delete [] z;
}

void f2(void)
{
  char *y = new char[10]{};
  y[9] = 'a';
  delete [] y ;
  
}

void f3(void)
{
  int x=0;
  if(x==0)
    {
      std::cout << "X is zero: " << x << "\n";
    }
}

void f4(void)
{
  int x=0;
  std::cout << "x=" << x << "\n";

  int i,j;
  int a[10]{}, b[10]{};

  if (1==2)
    {
      std::cout << b[0] << "\n";
    }
  j=0;
  for ( i = 0 ; i < 10 ; i++ )
    {
      j += a[i];
    }
  if ( j == 77 )
    {
    std::cout << "hello here\n";
    }
}
