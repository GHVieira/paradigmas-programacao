#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>


class Fescores {
	std::string nome;
	int pontos;
};

class Escores {
   std::string nome;
   std::string atividade;
   int pontos;
public:
   Escores(std::string nome, std::string atividade, int pontos) {
      this->nome = nome;
      this->atividade = atividade;
      this->pontos = pontos;
   }
   std::string getNome() {
      return nome;
   }
   std::string getAtividade() {
   	  return atividade;
   }
   int getPontos() {
      return pontos;
   }
   // operador '<' sobrecarregado (overload)
   // permite comparar Persons pela idade
   bool operator<(Escores& e) {
      return this->pontos < e.pontos;
   }

};

// comparador de Persons pelo nome
bool cmpEscoreNome(Escores& e1, Escores& e2) {
   return e1.getNome() < e2.getNome();
}

int main() {

   std::ifstream data("data.csv");
   
   std::string line;
   std::string cell[3];
   std::vector<Escores> t;
   
   while (std::getline(data, line)) {
      std::stringstream linestream(line);
      std::getline(linestream, cell[0], ',');
      std::getline(linestream, cell[1], ',');
	  std::getline(linestream, cell[2], ',');      
      t.push_back(Escores(cell[0], cell[1] , std::stoi(cell[2])));
   }
   
   std::vector<Escores>::iterator it;
   
   // Ordem original
   std::cout<< "Ordem original dos escores dos jogadores" << std::endl;         
   std::cout << std::endl;
   for (it = t.begin(); it != t.end(); it++){
      std::cout<< it->getNome() << " - ";
      std::cout<< it->getAtividade() << " - ";
	  std::cout<< it->getPontos() << std::endl;
	}
	std::cout << std::endl;
	   
   // Ordenando pelos pontos   
   std::cout<< "Ordenacao dos escores por ordem crescente dos pontos dos jogadores" << std::endl;         
   std::cout << std::endl;
   std::sort(t.begin(), t.end());
   for (it = t.begin(); it != t.end(); it++){
      std::cout<< it->getNome() << " - ";
      std::cout<< it->getAtividade() << " - ";
	  std::cout<< it->getPontos() << std::endl;
	}
	std::cout << std::endl;




   /*
   // Ordenando pelos nomes
   std::cout<< "Ordenacao dos escores por ordem alfabetica dos nomes dos jogadores" << std::endl;
   std::cout << std::endl;
   std::sort(t.begin(), t.end(), cmpEscoreNome);
   
   for (it = t.begin(); it != t.end(); it++){
      std::cout<< it->getNome() << " - ";
      std::cout<< it->getAtividade() << " - ";
	  std::cout<< it->getPontos() << std::endl;
	}
	std::cout << std::endl;
   */
   
}