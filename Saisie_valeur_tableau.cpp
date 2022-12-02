// Saisie_valeur_tableau.cpp : fichier d'implémentation
//

#include "pch.h"
#include "Tuto_TP2.h"
#include "Saisie_valeur_tableau.h"
#include "afxdialogex.h"


// boîte de dialogue de Saisie_valeur_tableau

IMPLEMENT_DYNAMIC(Saisie_valeur_tableau, CDialog)

Saisie_valeur_tableau::Saisie_valeur_tableau(CWnd* pParent /*=nullptr*/)
	: CDialog(ID_ENMODETEXTE_DIALOG, pParent)
	, m_itaille(20)
{

}

Saisie_valeur_tableau::~Saisie_valeur_tableau()
{
}

void Saisie_valeur_tableau::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SAISIE_TEXT_DIALOG, m_itaille);
}


BEGIN_MESSAGE_MAP(Saisie_valeur_tableau, CDialog)
END_MESSAGE_MAP()


// gestionnaires de messages de Saisie_valeur_tableau
