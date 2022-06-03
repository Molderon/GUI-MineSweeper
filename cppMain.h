//GUI launcher

#pragma once
#include"wx/wx.h"
#include<random>



class cppMain: public wxFrame
{
public:
	cppMain();
	~cppMain();

	const int FieldWidth = 10;
	const int FieldHeight = 10;
	wxButton** btn;

	int* nField = nullptr;
	bool bFirstClicked = true;


	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

};

