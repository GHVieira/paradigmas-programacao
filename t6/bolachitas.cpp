#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>
using namespace std;


//P = 0.5   -   M = 1   -   G = 2
// < 7      -   < 15    - 


class Cookie
{
    protected:
       double area;
       double preco;
       string nome;
    public:
       double getArea(){
           return area;
       }
       double getPreco(){
           return preco;
       }
       string getNome(){
           return nome;
       }
       void calculaPreco(){
          if(this->area <= 7)
            this->preco  = 0.5;
          else if (this->area <= 15)
            this->preco  = 1;
          else
            this->preco  = 2;
       }
};

class Quadrado : public Cookie
{
  private:
    double lado;
  public:
    double calculaArea(){
      return area = lado*lado;
    }
    Quadrado(double lado){
      this->nome = "quadrado";
      this->lado = lado;
      calculaArea();
      calculaPreco();
    }
};

class Circulo : public Cookie
{
  private:
    double raio;
  public:
    double calculaArea(){
      return area = 3,14*raio*raio;
    }
    Circulo(double raio){
      this->nome = "circulo";
      this->raio = raio;
      calculaArea();
      calculaPreco();
    }
};

class Triangulo : public Cookie
{
  private:
    double base;
    double altura;
  public:
     double calculaArea(){
       return area = (base*altura) / 2;
     }
     Triangulo(double base, double altura){
       this->nome = "triangulo";
       this->base = base;
       this->altura = altura;
       calculaArea();
       calculaPreco();
     }
};


bool cmpArea(Cookie* c1, Cookie* c2) {
   return c1->getArea() > c2->getArea();
}


void calculaFinal(vector<Cookie*>& cookies){
    int total_peq = 0;
    int total_med = 0;
    int total_gra = 0;
    
	//impressão dos biscoitos por ordem de tamanho
	vector<Cookie*>::iterator it;
	for (it = cookies.begin(); it != cookies.end(); it++){
    cout << "Biscoito " << (*it)->getNome() << " de area " << (*it)->getArea() << endl;
	
  	}
	
	cout << endl;
	
	//impressão do total arrecadado
	for (it = cookies.begin(); it != cookies.end(); it++){
      if((*it)->getArea() < 7)
        total_peq++;
      else if((*it)->getArea() < 15)
        total_med++;
      else
        total_gra++;
    }
    cout << "Produzidos " << total_peq << " biscoitos pequenos, gerando R$" << total_peq * 0.5 << endl;
    cout << "Produzidos " << total_med << " biscoitos medios, gerando R$" << total_med * 1 << endl;
    cout << "Produzidos " << total_gra << " biscotios grandes, gerando R$" << total_gra * 2 << endl;
    cout << "Numero total de biscoitos: " << total_peq+total_med+total_gra << " - Valor total arrecadado: R$" << (total_peq* 0.5) + (total_med * 1) + (total_gra * 2) << endl;

}


int main(){
    srand((unsigned)time(NULL));
    vector<Cookie*> cookies;
    int lote;
    
	cout << "Insira o numero de biscoitos desejados" << endl;
    cin >> lote;
    
	for(int i = 0; i < lote; i++){
        int t = rand() % 3;
        if (t == 0){
            Quadrado* q = new Quadrado(rand() % 5 + 1);
            cookies.push_back(q);
        }
        if (t == 1){
            Circulo*  c = new Circulo(rand() % 5 + 1);
            cookies.push_back(c);
        }
        if (t == 2){
            Triangulo* t = new Triangulo(rand() % 10 + 1, rand() % 10 + 1);
            cookies.push_back(t);
        }
    }

    sort(cookies.begin(), cookies.end(), cmpArea);
        
    calculaFinal(cookies);
    return 0;
}
