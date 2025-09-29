#include <stdio.h>
#include <math.h>

double p(double n) {
  if (n < 8)
    return -1;
  long double product = 5*64/63;
  for (double m = 9; m <= n; ++m) {
    product *= 5*m*m/((m*m) - 1);
  }
  return product;
}

double also_p(double n){
  return 8*(pow(5,n-7))*n/(7*(n+1));
}

int main(void) {
  for (int i = 8; i <= 16; i++) {
    printf("%lf = %lf\n",p(i),also_p(i));
  }
}
