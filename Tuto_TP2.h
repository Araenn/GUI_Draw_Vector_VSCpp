
// Tuto_TP2.h : fichier d'en-tête principal de l'application Tuto_TP2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'pch.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// CTutoTP2App :
// Consultez Tuto_TP2.cpp pour l'implémentation de cette classe
//

class CTutoTP2App : public CWinAppEx
{
public:
	CTutoTP2App() noexcept;


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

extern CTutoTP2App theApp;
