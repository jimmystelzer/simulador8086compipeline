#ifndef JANELASOBRE_H
#define JANELASOBRE_H

//(*Headers(JanelaSobre)
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class JanelaSobre: public wxDialog
{
	public:

		JanelaSobre(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~JanelaSobre();

		//(*Declarations(JanelaSobre)
		wxStaticText* StaticText2;
		wxStaticBitmap* StaticBitmap1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* ButtonOk;
		//*)

	protected:

		//(*Identifiers(JanelaSobre)
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON1;
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(JanelaSobre)
		void OnButtonOkClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
