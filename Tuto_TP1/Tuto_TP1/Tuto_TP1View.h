
// Tuto_TP1View.h : interface de la classe CTutoTP1View
//

#pragma once


class CTutoTP1View : public CView
{
protected: // création à partir de la sérialisation uniquement
	CTutoTP1View() noexcept;
	DECLARE_DYNCREATE(CTutoTP1View)

// Attributs
public:
	CTutoTP1Doc* GetDocument() const;

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
	virtual ~CTutoTP1View();
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
};

#ifndef _DEBUG  // version Debug dans Tuto_TP1View.cpp
inline CTutoTP1Doc* CTutoTP1View::GetDocument() const
   { return reinterpret_cast<CTutoTP1Doc*>(m_pDocument); }
#endif

