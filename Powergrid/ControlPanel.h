#pragma once

#include <wx/wx.h>

namespace powergrid {

	class ControlPanel : public wxFrame {
	public:
		ControlPanel(const wxString& title, const wxPoint& pos, const wxSize& size);

		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);

		DECLARE_EVENT_TABLE()
	};

	enum {
		ID_QUIT = 1,
		ID_ABOUT
	};

	BEGIN_EVENT_TABLE(ControlPanel, wxFrame)
		EVT_MENU(ID_QUIT, ControlPanel::OnQuit)
		EVT_MENU(ID_ABOUT, ControlPanel::OnAbout)
	END_EVENT_TABLE()

}
