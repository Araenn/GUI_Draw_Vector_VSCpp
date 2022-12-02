// MaBoiteBis.cpp : fichier d'implémentation
//

#include "pch.h"
#include "Tuto_TP1.h"
#include "MaBoiteBis.h"
#include "afxdialogex.h"


// boîte de dialogue de MaBoiteBis

IMPLEMENT_DYNAMIC(MaBoiteBis, CDialog)

MaBoiteBis::MaBoiteBis(CWnd* pParent /*=nullptr*/)
	: CDialog(ID_DIALOG, pParent)
	, m_xsaisie(_T("Pas de saisie"))
{

}

MaBoiteBis::~MaBoiteBis()
{
}

void MaBoiteBis::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTROL_DIALOG, m_xsaisie);
}


BEGIN_MESSAGE_MAP(MaBoiteBis, CDialog)
END_MESSAGE_MAP()


// gestionnaires de messages de MaBoiteBis
