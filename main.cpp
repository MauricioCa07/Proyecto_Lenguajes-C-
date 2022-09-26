#include "Adicional.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  Adicional d1 = Adicional();
  d1.bienvenida();
  cout << "-Para continuar presione 1: " << endl;
  int i;
  cin >> i;
  if (i == 1) {
    d1.cargar_Palabra();
    d1.comparando_Palabra();
  }
  cout << "\n**********************************\n"
       << "Has dejado el juego\n"
       << "**********************************\n";
  return 0;
}
