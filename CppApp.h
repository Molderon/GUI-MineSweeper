//Launcher of the application

#pragma once

#include"wx/wx.h"
#include"cppMain.h"
#include<random>



class CppApp : public wxApp
{
public:
	CppApp();
	~CppApp();
private:
	cppMain* m_frame1 = nullptr;

public:

	virtual bool OnInit();
};

