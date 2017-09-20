#include "string_soma.hpp"
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int soma_string(char *string_entrada) {
  string entrada = string_entrada;
  string elemento_esperado;
  vector<string> delimitadores = {","};
  vector<tuple<string, string>> elementos;
  size_t inicio, fim = 0;
  int somatorio = 0;
  int cont = 0;
  int cont_num_por_linha = 0;
  bool delimitador_encontrado;

  if (entrada.find("//[") == 0) {
    entrada = entrada.substr(entrada.find("["));
    while (entrada.find("]") != std::string::npos) {
      inicio = entrada.find("[");
      fim = entrada.find("]");
      delimitadores.push_back(entrada.substr(inicio + 1, fim - inicio - 1));
      entrada = entrada.substr(fim + 1);
    }
    if (entrada[0] == '\n') {
      entrada = entrada.substr(1);
    } else {
      return -1;
    }
  }

  while (entrada.size() > 0) {
    if (entrada.find_first_of("1234567890") == 0) {
      inicio = entrada.find_first_of("1234567890");
      fim = entrada.find_first_not_of("1234567890");
      elementos.push_back(make_tuple("Numero", string(entrada, inicio, fim - inicio)));
    } else {
      delimitador_encontrado = false;
      cont = 0;
      while (delimitador_encontrado == false && cont < delimitadores.size()){
        if (entrada.find(delimitadores[cont]) == 0) {
          inicio = entrada.find(delimitadores[cont]);
          fim = inicio + delimitadores[cont].size();
          elementos.push_back(make_tuple("Delimitador", string(entrada, inicio, fim - inicio)));
          delimitador_encontrado = true;
        }
        cont++;
      }
      if (delimitador_encontrado == false) {
        if (entrada.find("\n") == 0) {
          if (entrada.size() > 2) {
            inicio = entrada.find_first_of("\n");
            fim = entrada.find_first_not_of("\n");
            elementos.push_back(make_tuple("Quebra de linha", string(entrada, inicio, fim - inicio)));
          } else {
            inicio = entrada.find_first_of("\n");
            elementos.push_back(make_tuple("Quebra de linha", string(entrada, inicio, 1)));
          }
        } else {
          return -1;
        }
      }
    }

    if (entrada.size() == 1) {
      entrada.clear();
    } else {
      entrada = entrada.substr(fim);
    }
  }

  elemento_esperado = "Numero";
  for (cont = 0; cont < elementos.size(); cont++) {
    if (std::get<0>(elementos[cont]) == elemento_esperado) {
      if (elemento_esperado == "Numero") {
        somatorio += stoi(get<1>(elementos[cont]));
        cont_num_por_linha += 1;
        elemento_esperado = "Delimitador";
        if (cont_num_por_linha > 3) {
          return -1;
        }
      } else {
        elemento_esperado = "Numero";
      }
    } else if (get<0>(elementos[cont]) == "Quebra de linha") {
      cont_num_por_linha = 0;
    } else {
      return -1;
    }
    if ((cont == elementos.size() - 1) && get<0>(elementos[cont]) != "Quebra de linha") {
      return -1;
    }
  }

  if (elemento_esperado == "Numero") {
    return -1;
  }
  return somatorio;
}
