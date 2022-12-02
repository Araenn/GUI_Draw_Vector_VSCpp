
// Tuto_TP2Doc.h : interface de la classe CTutoTP2Doc
//


#pragma once


class CTutoTP2Doc : public CDocument
{
protected: // création à partir de la sérialisation uniquement
	CTutoTP2Doc() noexcept;
	DECLARE_DYNCREATE(CTutoTP2Doc)

// Attributs
public:

// Opérations
public:

// Substitutions
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implémentation
public:
	virtual ~CTutoTP2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Fonction d'assistance qui définit le contenu de recherche pour un gestionnaire de recherche
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnAffichageEnmodetexte();
	afx_msg void OnAffichageEnmodegraph();
private:
	CString *pxaff;
	int m_iaff;
public:
	int GetTaille();
	CString *GetChaine();
private:
	CSize m_sizeDoc;
public:
	CSize getDocSize();
	void InitDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
public:
	double* pxDoc;
	double* pyDoc;
public:
	int flag;
};
