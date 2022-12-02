#pragma once


// boîte de dialogue de MaBoiteBis

class MaBoiteBis : public CDialog
{
	DECLARE_DYNAMIC(MaBoiteBis)

public:
	MaBoiteBis(CWnd* pParent = nullptr);   // constructeur standard
	virtual ~MaBoiteBis();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_xsaisie;
};
