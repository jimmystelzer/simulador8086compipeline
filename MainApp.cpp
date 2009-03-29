#include <wx/wxprec.h>
#include "MainApp.h"
//(*AppHeaders
#include "JanelaPrincipal.h"
#include <wx/image.h>
//*)

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
    }
    //*)
    return wxsOK;
}

