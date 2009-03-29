#include "JanelaPrincipal.h"

//(*InternalHeaders(JanelaPrincipal)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(JanelaPrincipal)
const long JanelaPrincipal::ID_BUTTON1 = wxNewId();
const long JanelaPrincipal::ID_BUTTON2 = wxNewId();
const long JanelaPrincipal::ID_STATICLINE1 = wxNewId();
const long JanelaPrincipal::ID_STATICLINE2 = wxNewId();
const long JanelaPrincipal::ID_BUTTON3 = wxNewId();
const long JanelaPrincipal::ID_LISTCTRL2 = wxNewId();
const long JanelaPrincipal::ID_LISTCTRL1 = wxNewId();
const long JanelaPrincipal::ID_BUTTON4 = wxNewId();
const long JanelaPrincipal::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(JanelaPrincipal,wxFrame)
	//(*EventTable(JanelaPrincipal)
	//*)
END_EVENT_TABLE()

JanelaPrincipal::JanelaPrincipal(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(JanelaPrincipal)
	Create(parent, id, _("Simulador 8086 com pipeline"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(800,460));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Sobre"), wxPoint(704,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Abrir = new wxButton(Panel1, ID_BUTTON2, _("Abrir"), wxPoint(704,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(704,42), wxSize(88,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(704,82), wxSize(88,2), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	Executar = new wxButton(Panel1, ID_BUTTON3, _("Executar"), wxPoint(704,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Registradores = new wxListCtrl(Panel1, ID_LISTCTRL2, wxPoint(8,8), wxSize(680,64), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES|wxRAISED_BORDER|wxNO_BORDER, wxDefaultValidator, _T("ID_LISTCTRL2"));
	pipeline = new wxListCtrl(Panel1, ID_LISTCTRL1, wxPoint(8,80), wxSize(680,200), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES|wxRAISED_BORDER|wxNO_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
	Resetar = new wxButton(Panel1, ID_BUTTON4, _("Resetar"), wxPoint(704,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnButton1Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnResetarClick);
	//*)
    Reset();
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

void JanelaPrincipal::Reset()
{
    Registradores->ClearAll();
    Registradores->InsertColumn(0,_("AX"));
	Registradores->InsertColumn(1,_("BX"));
	Registradores->InsertColumn(2,_("CX"));
	Registradores->InsertColumn(3,_("DX"));
	Registradores->InsertColumn(4,_("SP"));
	Registradores->InsertColumn(5,_("BP"));
	Registradores->InsertColumn(6,_("SI"));
	Registradores->InsertColumn(7,_("DI"));

	Registradores->InsertItem(0,_("0000h"));    //AX
	Registradores->SetItem(0,1,_("0000h"));     //BX
    Registradores->SetItem(0,2,_("0000h"));     //CX
    Registradores->SetItem(0,3,_("0000h"));     //DX
    Registradores->SetItem(0,4,_("0000h"));     //SP
	Registradores->SetItem(0,5,_("0000h"));     //BP
    Registradores->SetItem(0,6,_("0000h"));     //SI
    Registradores->SetItem(0,7,_("0000h"));     //DI

    pipeline->ClearAll();
    pipeline->InsertColumn(0,_("IF"));          //Instruction Fetch
    pipeline->InsertColumn(0,_("ID"));          //Instruction Decode
    pipeline->InsertColumn(0,_("EX"));          //Execute
    pipeline->InsertColumn(0,_("MEM"));         //Memory Access
    pipeline->InsertColumn(0,_("WB"));          //Register Write Back

}

void JanelaPrincipal::OnResetarClick(wxCommandEvent& event)
{
    Reset();
}
