#include "JanelaSobre.h"

//(*InternalHeaders(JanelaSobre)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)


//(*IdInit(JanelaSobre)
const long JanelaSobre::ID_STATICTEXT3 = wxNewId();
const long JanelaSobre::ID_STATICBITMAP1 = wxNewId();
const long JanelaSobre::ID_STATICTEXT1 = wxNewId();
const long JanelaSobre::ID_STATICTEXT2 = wxNewId();
const long JanelaSobre::ID_BUTTON1 = wxNewId();
const long JanelaSobre::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(JanelaSobre,wxDialog)
	//(*EventTable(JanelaSobre)
	//*)
END_EVENT_TABLE()

JanelaSobre::JanelaSobre(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    std::string titulo1("com suporte a pipeline\n       v.: ");
    std::string tituloversion(AutoVersion::FULLVERSION_STRING);
    std::string tituloversionstatus(AutoVersion::STATUS_SHORT);

    titulo1.append(tituloversion).append(tituloversionstatus);


	wxString titulo(titulo1.c_str(), wxConvUTF8);

	//(*Initialize(JanelaSobre)
	Create(parent, wxID_ANY, _("Sobre o Simulador"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(490,400));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(490,400), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Copyright 2009 Jimmy Pinto Stelzer <jimmy.stelzer@gmail.com>, Bruno Goulart <bruno.goulart@acad.pucrs.br> e Bruno Paes <bruno.paes@acad.pucrs.br>\n\nThis program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.\n\nThis program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA."), wxPoint(8,80), wxSize(472,288), wxST_NO_AUTORESIZE, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("./res/8086.jpg"))), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Simulador 8086"), wxPoint(232,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("com suporte a pipeline"), wxPoint(256,48), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	ButtonOk = new wxButton(Panel1, ID_BUTTON1, _("Ok"), wxPoint(395,365), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Center();
	
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaSobre::OnButtonOkClick);
	//*)
}

JanelaSobre::~JanelaSobre()
{
	//(*Destroy(JanelaSobre)
	//*)
}


void JanelaSobre::OnButtonOkClick(wxCommandEvent& event)
{
    Close();
}
