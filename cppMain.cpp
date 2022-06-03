#include "cppMain.h"

wxBEGIN_EVENT_TABLE(cppMain, wxFrame)	
wxEND_EVENT_TABLE()

cppMain::cppMain() : wxFrame(nullptr, 10001, "Making GUI with C++ was a dudu idea :D", wxPoint(30,30), wxSize(800, 600)){
	btn = new wxButton * [FieldHeight * FieldWidth];
	wxGridSizer* grid = new wxGridSizer(FieldWidth, FieldHeight, 0, 0);

	nField = new int[FieldWidth * FieldHeight];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0; x < FieldWidth; x++) {
		for (int y = 0; y < FieldHeight; y++) {
			btn[y * FieldWidth + x] = new wxButton(this, 10000 + (y * FieldWidth + x));
			grid->Add(btn[y * FieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * FieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cppMain::OnButtonClicked, this);
			nField[y * FieldWidth + x] = 0;
		}
	}
	this->SetSizer(grid);
	grid->Layout();
}



cppMain::~cppMain(){
	delete[]btn;
}



void cppMain::OnButtonClicked(wxCommandEvent& evt) {
	//Get coordinate of button within the array

	int x = (evt.GetId() - 10000) % FieldWidth;
	int y = (evt.GetId() - 10000) / FieldWidth;

	if (bFirstClicked) {
		int mines = 30;

		while (mines) {
			int rx = rand() % 10;
			int ry = rand() % 10;

			if (nField[ry * FieldWidth + rx] == 0 && rx != x && ry != y) 
			{
				nField[ry * FieldWidth + rx] = -1;
				mines--;
			}
		}
		bFirstClicked = false;
	}
	btn[y * FieldWidth + x]->Enable(false);

	if (nField[y * FieldWidth + x] == -1) {
		wxMessageBox("Allah Damn it... Not again :(");

		//Reseting the game
		bFirstClicked = true;
		for (int x = 0; x < FieldWidth; x++) {
			for (int y = 0; y < FieldHeight; y++)
			{
				nField[y * FieldWidth + x] = 0;
				btn[y * FieldWidth + x]->SetLabel("");
				btn[y * FieldWidth + x]->Enable(true);
			}
		}
	}
	else {
		// count the neibouring mines
		int mines_active = 0;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (x + i >= 0 && x + 1 < FieldWidth && y + j >= 0 && y + j < FieldHeight) {
					if (nField[(y + j) * FieldWidth + (x + i)] == -1) {
						mines_active++;
					}
				}
			}
		}
		if (mines_active > 0) { btn[y * FieldHeight + x]->SetLabel(std::to_string(mines_active));}

	}

	evt.Skip();
}