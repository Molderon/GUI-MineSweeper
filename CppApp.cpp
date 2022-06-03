#include "CppApp.h"
wxIMPLEMENT_APP(CppApp);

CppApp::CppApp() {
}

CppApp::~CppApp() {

}

bool CppApp::OnInit() {
	m_frame1 = new cppMain();
	m_frame1->Show();
	return true;
}

