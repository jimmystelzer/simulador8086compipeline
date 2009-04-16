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
    	Helpers* healper = new Helpers(); // Para conversão de Bases

    	JanelaPrincipal* Janela = new JanelaPrincipal(0); // Nova Janela
    	Janela->Show();  // Mostra Janela
    	SetTopWindow(Janela);  // Defini foco na Janela

        wxString mystring((healper->intToBase(80,16)).c_str(), wxConvUTF8);  // Converte a string para string do tipo label DEBUG REMOVER
        Janela->Registradores->SetItem(0,4,mystring.Append('h')); // mostra a string label DEBUG REMOVER
    }
    //*)

    return wxsOK;
}

