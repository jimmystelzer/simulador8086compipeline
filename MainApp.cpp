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
    	Frame->Show();
    	SetTopWindow(Frame);
    	Frame->Registradores->SetItem(0,4,_("0080h"));
    }
    //*)
    /*
    Frame->Registradores->SetItem(0,4,_("0080h"));
    */
    return wxsOK;
}

