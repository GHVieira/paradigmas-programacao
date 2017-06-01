#ifndef window_h
#define window_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Text_Display.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_Image.H>

class UserInterface {
public:
  UserInterface();
protected:
  Fl_Double_Window *w; //janelita
  Fl_Int_Input *inputValue1; //numero participantes
  Fl_Button *btnReset; //reset
  Fl_Box *boxResult; //sorteado
  Fl_Button *btnSortear; //sortear
  Fl_Box *boxTitulo; //ganhadores
  Fl_Box *boxImg; //caixita da imagem
  Fl_PNG_Image* myimage; //a imagem hihihi
  Fl_Box *boxWinner;
  
};
#endif
