
// Tuto_TP2View.h : interface de la classe CTutoTP2View
//

#pragma once


class CTutoTP2View : public CScrollView
{
protected: // création à partir de la sérialisation uniquement
	CTutoTP2View() noexcept;
	DECLARE_DYNCREATE(CTutoTP2View)

// Attributs
public:
	CTutoTP2Doc* GetDocument() const;

// Opérations
public:

// Substitutions
public:
	virtual void OnDraw(CDC* pDC);  // substitué pour dessiner cette vue
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implémentation
public:
	virtual ~CTutoTP2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // version Debug dans Tuto_TP2View.cpp
inline CTutoTP2Doc* CTutoTP2View::GetDocument() const
   { return reinterpret_cast<CTutoTP2Doc*>(m_pDocument); }
#endif

