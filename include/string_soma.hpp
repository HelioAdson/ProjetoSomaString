/// @file string_soma.hpp
/// @breif Arquivo de cabeçalho das funções de string_soma.cpp
///
/// @author Helio Adson

#include <string>
#include <vector>

using namespace std;

/// @fun soma_string(char* string_entrada)
///
/// @param string_entrada Ponteiro para char com a string para o cálculo.
/// @return O resultado da soma para o caso valido e -1 para caso contrário.
int soma_string(char *string_entrada);

/// @fun redefine_delimitadores (string* entrada, vector<string>* delimitadores)
///
/// Captura os delimitadores definidos na primeira linha da string
///
/// @param entrada Ponteiro para string com os novos delimitadores.
/// @param delimitadores Vector de string contendo os delimitadores que foram encontrados na string entrada.
/// @return 0 caso valido e -1 para caso contrário.
int redefine_delimitadores(string* entrada, vector<string>* delimitadores);