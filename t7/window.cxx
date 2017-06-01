#include "window.h"

UserInterface::UserInterface() {
  { w = new Fl_Double_Window(400, 450, "Random Demo");
    w->color(20);
	w->box(FL_ENGRAVED_BOX);
    w->user_data((void*)(this));
    
	{ myimage = new Fl_PNG_Image("logo.png");
  	  boxImg = new Fl_Box(148, 65, 100, 100);
  	  boxImg->image(myimage);
  	  boxImg->redraw();
	} //aqui para a logo
	
	{ inputValue1 = new Fl_Int_Input(145, 250, 100, 20, "Participantes");
      inputValue1->type(2);
      inputValue1->labelsize(15);
      inputValue1->align(Fl_Align(FL_ALIGN_LEFT));
    } // Fl_Int_Input* inputValue1
    
	{ btnReset = new Fl_Button(254, 250, 72, 20, "Reset");
    } // Fl_Button* btnReset
    
	{ btnSortear = new Fl_Button(60, 380, 265, 67, "Sortear");
    } // Fl_Button* btnSortear

	{ boxResult = new Fl_Box(60, 300, 265, 67);
      boxResult->box(FL_BORDER_BOX);
      boxResult->labelsize(30);
    } // Fl_Box* boxResult
    
    { boxTitulo = new Fl_Box(145, 280, 100, 20);
      boxTitulo->box(FL_NO_BOX);
      boxTitulo->labelsize(15);
    } // Fl_Box* boxTitulo(o atual ganhador)
          
    
	w->end();
  
  } // Fl_Double_Window* w
}
