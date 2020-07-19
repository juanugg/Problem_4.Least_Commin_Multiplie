#include <iostream>

// long long lcm_naive(int a, int b) {
//
//   if (a == 0 || b == 0)
//   {
//     return (long long) 0;
//   }
//
//   for (long long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;
//
//   return (long long) a * b;
// }

// Función auxiliar para calcular el lcm de manera más rápida


int gcd_euclidean(int a, int b)
{
  if (b == 0)
  {
    return a;
  }

  if (a < b)
  {
    int a_aux = 0;
    a_aux = a;
    a = b;
    b = a_aux;
  }

  int a_prima = 0;
  a_prima = a % b;

  return gcd_euclidean(b, a_prima);
}

long long lcm_efficient(int a, int b)
{
  // 1. calcular gcd con gcd_euclidean
  // 2. Dividir a ó b entre gcd. Nos da c
  // 3 Multiplicar el valor de c por el otro elemento a ó b


  if (a == 0 || b == 0)
  {
    return (long long) 0;
  }

  int gcd = 0;
  gcd = gcd_euclidean(a, b);

  int c = 0;
  c = a / gcd;

  return (long long) c * b;

}


int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_efficient(a, b) << std::endl;
  return 0;
}
