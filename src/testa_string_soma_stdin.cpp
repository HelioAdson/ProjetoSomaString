/// @file testa_string_soma_stdin.cpp
/// @breif Arquivo contendo o a função main() que realiza a leitura da string e a chamada da função soma_string
///
/// @author Helio Adson

#include "string_soma.hpp"
#include <iostream>
#include <cstdio>

int main() {
  char string_entrada[100];
  char buffer[40];
  int resultado = 0;
  fscanf(stdin, "%[^EOF]", string_entrada);
  resultado = soma_string(string_entrada);
  std::cout << resultado << std::endl;
  return 0;
}