
// Tuto_TP1View.cpp : implémentation de la classe CTutoTP1View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL, et permettent le partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "Tuto_TP1.h"
#endif

#include "Tuto_TP1Doc.h"
#include "Tuto_TP1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTutoTP1View

IMPLEMENT_DYNCREATE(CTutoTP1View, CView)

BEGIN_MESSAGE_MAP(CTutoTP1View, CView)
	// Commandes d'impression standard
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTutoTP1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// construction/destruction de CTutoTP1View

CTutoTP1View::CTutoTP1View() noexcept
{
	// TODO: ajoutez ici du code de construction

}

CTutoTP1View::~CTutoTP1View()
{
}

BOOL CTutoTP1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: changez ici la classe ou les styles Window en modifiant
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// dessin de CTutoTP1View

void CTutoTP1View::OnDraw(CDC* pDC)
{
	CTutoTP1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	// Déclaration d’une instance rect de la classe CRect ( définie dans afxwin.h)
	GetClientRect(rect);
	// Définition d’une aire client ( zone de l’écran dans laquelle on écrit )
	// elle est rectangulaire ici
	pDC -> TextOut(int(rect.Width() / 10.0), int(rect.Height() / 10.0), pDoc -> m_xaff, pDoc -> m_xaff.GetLength());
	// La fonction TextOut permet d’afficher une chaîne de caractères à l’écran
		// en mode graphique , consulter l’aide pour voir quel type de paramètres
		// elle attend .


	// TODO: ajoutez ici le code de dessin pour les données natives
}


// impression de CTutoTP1View


void CTutoTP1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTutoTP1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// préparation par défaut
	return DoPreparePrinting(pInfo);
}

void CTutoTP1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez une initialisation supplémentaire avant l'impression
}

void CTutoTP1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez un nettoyage après l'impression
}

void CTutoTP1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTutoTP1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// diagnostics de CTutoTP1View

#ifdef _DEBUG
void CTutoTP1View::AssertValid() const
{
	CView::AssertValid();
}

void CTutoTP1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTutoTP1Doc* CTutoTP1View::GetDocument() const // la version non Debug est inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTutoTP1Doc)));
	return (CTutoTP1Doc*)m_pDocument;
}
#endif //_DEBUG


// gestionnaires de messages de CTutoTP1View
