#include "JanelaPrincipal.h"

//(*InternalHeaders(JanelaPrincipal)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(JanelaPrincipal)
const long JanelaPrincipal::ID_BUTTON1 = wxNewId();
const long JanelaPrincipal::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(JanelaPrincipal,wxFrame)
	//(*EventTable(JanelaPrincipal)
	//*)
END_EVENT_TABLE()

JanelaPrincipal::JanelaPrincipal(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(JanelaPrincipal)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(800,460));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(144,272), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Sobre"), wxPoint(696,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnButton1Click);
	//*)
}

JanelaPrincipal::~JanelaPrincipal()
{
	//(*Destroy(JanelaPrincipal)
	//*)
}


void JanelaPrincipal::OnButton1Click(wxCommandEvent& event)
{
    JanelaSobre dialog(this);
    dialog.ShowModal();
}
