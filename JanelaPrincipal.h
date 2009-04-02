#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

//(*Headers(JanelaPrincipal)
#include <wx/listctrl.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
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
		wxButton* Executar;
		wxButton* Resetar;
		wxStaticText* StaticText2;
		wxButton* Abrir;
		wxListCtrl* Pipeline;
		wxButton* Button1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxFileDialog* FileDialog1;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine2;
		wxStaticLine* StaticLine1;
		wxListCtrl* Registradores;
		wxListCtrl* Flags;
		//*)

	protected:

		//(*Identifiers(JanelaPrincipal)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICLINE1;
		static const long ID_STATICLINE2;
		static const long ID_BUTTON3;
		static const long ID_LISTCTRL2;
		static const long ID_LISTCTRL1;
		static const long ID_BUTTON4;
		static const long ID_LISTCTRL3;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(JanelaPrincipal)
		void OnButton1Click(wxCommandEvent& event);
		void OnResetarClick(wxCommandEvent& event);
		void OnAbrirClick(wxCommandEvent& event);
		//*)

		void Reset();

		DECLARE_EVENT_TABLE()
};

#endif
