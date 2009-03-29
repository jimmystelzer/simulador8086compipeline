#ifndef MAINAPP_H
#define MAINAPP_H

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/app.h>
#endif

class MyApp : public wxApp
{
	public:
		virtual bool OnInit();
};

#endif // MAINAPP_H
