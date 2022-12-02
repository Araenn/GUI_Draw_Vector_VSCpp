
// Tuto_TP1.h : fichier d'en-tête principal de l'application Tuto_TP1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'pch.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// CTutoTP1App :
// Consultez Tuto_TP1.cpp pour l'implémentation de cette classe
//

class CTutoTP1App : public CWinAppEx
{
public:
	CTutoTP1App() noexcept;


// Substitutions
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implémentation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTutoTP1App theApp;
