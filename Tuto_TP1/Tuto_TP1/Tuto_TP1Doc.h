
// Tuto_TP1Doc.h : interface de la classe CTutoTP1Doc
//


#pragma once



class CTutoTP1Doc : public CDocument
{
protected: // création à partir de la sérialisation uniquement
	CTutoTP1Doc() noexcept;
	DECLARE_DYNCREATE(CTutoTP1Doc)

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
	virtual ~CTutoTP1Doc();
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
	afx_msg void OnMenuExemple();
	CString m_xaff;
	afx_msg void OnExemple2Saisie();
	afx_msg void OnExemple2Rafraichissement();
};
