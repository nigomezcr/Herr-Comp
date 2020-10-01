//

#include<iostream>
#include<gsl/gsl_ieee_utils.h>
#include<gsl/gsl_version.h>

int main(void)
{
  double d = 1.0/3.0;
  float f = 2.0/3.0;

  // print gsl version
  std::printf("%s\n", GSL_VERSION);

  // print float
  std::printf (" f=");
  gsl_ieee_printf_float(&f);
  std::printf("\n");

  // print double
  std::printf(" d=");
  gsl_ieee_printf_double(&d);
  std::printf ("\n");

  return 0;
}
