#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

//(*Headers(JanelaPrincipal)
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

#include "JanelaSobre.h"

class JanelaPrincipal: public wxFrame
{
	public:

		JanelaPrincipal(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~JanelaPrincipal();

		//(*Declarations(JanelaPrincipal)
		wxButton* Button1;
		wxPanel* Panel1;
		//*)

	protected:

		//(*Identifiers(JanelaPrincipal)
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(JanelaPrincipal)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
