#include <wx/wxprec.h>
#include "MainApp.h"
//(*AppHeaders
#include "JanelaPrincipal.h"
#include <wx/image.h>
//*)
#include "Helpers.h"
#include <iostream>


IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	JanelaPrincipal* Frame = new JanelaPrincipal(0);
    	Helpers* h = new Helpers();
    	h->setLog(std::string("Janela Criada"));
    	Frame->Show();
    	h->setLog(std::string("Mostrar Janela"));
    	SetTopWindow(Frame);
    	h->setLog(std::string("Dar foco a Janela"));
    	Frame->Registradores->SetItem(0,4,_("0080h"));
    	h->setLog(std::string("Definido o valor do item 0,4"));
    	h->saveLog(std::string("log.txt"));
    }
    //*)
    /*
        JanelaPrincipal* Frame = new JanelaPrincipal(0);
    	Helpers* h = new Helpers();
    	h->setLog(std::string("Janela Criada"));
    	Frame->Show();
    	h->setLog(std::string("Mostrar Janela"));
    	SetTopWindow(Frame);
    	h->setLog(std::string("Dar foco a Janela"));
    	Frame->Registradores->SetItem(0,4,_("0080h"));
    	h->setLog(std::string("Definido o valor do item 0,4"));
    	h->saveLog(std::string("log.txt"));
    */
    return wxsOK;
}

