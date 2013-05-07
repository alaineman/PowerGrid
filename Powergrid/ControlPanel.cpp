#include "ControlPanel.h"

namespace powergrid {
	ControlPanel::ControlPanel(const wxString& title, const wxPoint& pos, const wxSize& size) 
		: wxFrame( NULL, -1, title, pos, size ){
		wxMenu *menuFile = new wxMenu;

		menuFile->Append( ID_ABOUT, _("&About...") );
		menuFile->AppendSeparator();
		menuFile->Append( ID_QUIT, _("E&xit") );

		wxMenuBar *menuBar = new wxMenuBar;
		menuBar->Append( menuFile, _("&File") );

		SetMenuBar( menuBar );
			
		CreateStatusBar();
		SetStatusText( _("Welcome to wxWidgets!") );
	}

	ControlPanel::~ControlPanel(void) {}

}