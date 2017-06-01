#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include <stdexcept>
#include <FL/fl_ask.H>
#include "window.h"
#include <iostream>
#include <vector>
#include <algorithm>    
#include <vector>       
#include <ctime>        
#include <cstdlib> 
     
class SorteioView : public UserInterface {

protected:
	std::vector<int> ganhador;
	int final=0;
public:
  
  SorteioView() {
    btnReset->callback((Fl_Callback*) cbBtnReset, (void*)(this)); 
    btnSortear->callback((Fl_Callback*) cbBtnSortear, (void*)(this));
  }
  
  void show() {
    // Mostra janela
    w->show();
  }
   
   void preenche_ganhadores(int i){
     for(auto j=1; j<=i; j++){
	   this->ganhador.push_back(j);
	 }
	 std::random_shuffle (this->ganhador.begin(), this->ganhador.end());
	 this->final++;
   }
   
  // Funcao callback chamada quando pressionado botao 'Sortear'
  static void cbBtnSortear(Fl_Widget* btn, void*userdata){
		SorteioView* gui = static_cast<SorteioView*>(userdata);
	  	try{
	  		int a = std::stoi(gui->inputValue1->value());
			if(gui->ganhador.empty()){
				if(gui->final==0){
		    		gui->preenche_ganhadores(a);
		  		}
		  		else{
		  			fl_alert("Todos os participantes foram premiados.");
		  			gui->boxResult->label("");
		  			gui->inputValue1->value("");
		  			gui->boxTitulo->label("");
		  			gui->final=0;
		  		}
			}
	  		if(gui->final!=0){
				if (a<=0){
		  			fl_alert("Coloque um número maior que zero.");
	    		}
				else{
					int b = gui->ganhador.back();
					gui->ganhador.pop_back();
		    		gui->boxResult->copy_label(std::to_string(b).c_str());
		    		std::string ganhador_atual=std::to_string(gui->ganhador.size()+1).c_str();
					ganhador_atual+="º Ganhador";
		    		gui->boxTitulo->copy_label(ganhador_atual.c_str());

				}
			}
		}	catch (std::invalid_argument&) {
      			fl_alert("Antes de sortear, digite a quantidade de participantes.");
 	 		}	 
  }
 
  // Funcao callback chamada quando pressionado botao 'Reset'
  static void cbBtnReset(Fl_Widget* btn, void* userdata) {
	SorteioView* gui = static_cast<SorteioView*>(userdata);
    gui->inputValue1->value(""); 
    gui->boxResult->label("");
    gui->boxTitulo->label("");
    gui->ganhador.clear(); //caso ainda tenham elementos não sorteados, ele vai limpar o vector
    gui->final=0;
  }
  
};

int main() {
  srand((unsigned)time(NULL));
  SorteioView gui;
  gui.show();
  return Fl::run();
}