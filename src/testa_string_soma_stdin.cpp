#include "string_soma.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
  char string_entrada[100];
  char buffer[40];
  int resultado = 0;
  fscanf(stdin, "%[^EOF]", string_entrada);
  resultado = soma_string(string_entrada);
  std::cout << resultado << std::endl;
  return 0;
}