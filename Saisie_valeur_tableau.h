#pragma once


// boîte de dialogue de Saisie_valeur_tableau

class Saisie_valeur_tableau : public CDialog
{
	DECLARE_DYNAMIC(Saisie_valeur_tableau)

public:
	Saisie_valeur_tableau(CWnd* pParent = nullptr);   // constructeur standard
	virtual ~Saisie_valeur_tableau();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_ENMODETEXTE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int m_itaille;
};
