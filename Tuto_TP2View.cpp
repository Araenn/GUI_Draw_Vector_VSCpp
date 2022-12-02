
// Tuto_TP2View.cpp : implémentation de la classe CTutoTP2View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL, et permettent le partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "Tuto_TP2.h"
#endif

#include "Tuto_TP2Doc.h"
#include "Tuto_TP2View.h"

#include "Vecteurs.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTutoTP2View

IMPLEMENT_DYNCREATE(CTutoTP2View, CScrollView)

BEGIN_MESSAGE_MAP(CTutoTP2View, CScrollView)
	// Commandes d'impression standard
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTutoTP2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// construction/destruction de CTutoTP2View

CTutoTP2View::CTutoTP2View() noexcept
{
	// TODO: ajoutez ici du code de construction

}

CTutoTP2View::~CTutoTP2View()
{

}

BOOL CTutoTP2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: changez ici la classe ou les styles Window en modifiant
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// dessin de CTutoTP2View

void CTutoTP2View::OnDraw(CDC* pDC)
{
	CTutoTP2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;		     // Déclare une instance rect de la classe CRect (définie dans afxwin.h) 
	GetClientRect(rect); // Définit une aire client, càd la zone de l'écran où l'on écrit, ici un rectangle


	switch (pDoc->flag) //qui a forcé le passage par la méthode OnDraw ?
	{
	case 1:             // si c'est OnAffichageEnModetext()
	{
		if (pDoc->GetChaine() != NULL)
		{
			for (int i = 0; i < pDoc->GetTaille(); i++)      //boucle sur les éléments du tableaux
			{ // on fait afficher le contenu de pxaff
				pDC->TextOut((int)(rect.Width() / 10.0),
					(int)(rect.Height() / 10.0 + 22 * (i + 1)), pDoc->GetChaine()[i],
					pDoc->GetChaine()[i].GetLength());
			}
		}
		break;
	}
	case 2:  // si c'est OnAffichageEnModegraphique()
	{
		if (pDoc->GetTaille() != 1)
		{ // on fait tracer py en function de px
			CPen penBlack; //déclaration d’un crayon penBlack instance de CPen     
			penBlack.CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); //on définit le type de  
														   //crayon utilisé
														   //noir (RGB(0,0 0)), trait continu PS_SOLID, épaisseur 1
			CPen* pOldPen = pDC->SelectObject(&penBlack);
			// on sélectionne le nouveau crayon dans le contexte de périph. (CDP)
			// tout en conservant un pointeur vers le crayon initialement 
			// sélectionné dans le CDP 
			pDC->Rectangle((rect.left + rect.right) / 4 - 210, (rect.left + rect.right) / 4 - 210, (rect.left + rect.right) / 4 + 210, (rect.left + rect.right) / 4 + 210);
			//trace un rectangle 

			CPen pen0(PS_DASHDOTDOT, 2, RGB(0, 255, 150));
			//on définit un nouveau crayon 
			//parme (RGB(255,0 255)), trait pointillé PS_DASHDOTDOT, épaisseur 2
			// on le sélectionne dans le CDP
			pDC->SelectObject(&pen0);
			// boucle sur les éléments des tableaux px et py du document	
			for (int i = 1; i < pDoc->GetTaille(); i++)
			{
				pDC->MoveTo((rect.left + rect.right) / 4 + 200 * pDoc->pxDoc[i - 1], (rect.left + rect.right) / 4 + 200 * pDoc->pyDoc[i - 1]);
				//se place à un certain endroit de l'aire cliente
				//fonction de px[i-1] et py[i-1]
				pDC->LineTo((rect.left + rect.right) / 4 + 200 * pDoc->pxDoc[i],
					(rect.left + rect.right) / 4 + 200 * pDoc->pyDoc[i]);
				//et relie se point à une autre zone de l’aire cliente 
				//fonction de px[i] et py[i]
			}
			pDC->SelectObject(&penBlack); //resélectionne le crayon noir 
										  //dans le CDP  
			pDC->Rectangle(3 * (rect.left + rect.right) / 4 - 110, (rect.left + rect.right) / 4 - 110, 3 * (rect.left + rect.right) / 4 + 110, (rect.left + rect.right) / 4 + 110);
			//trace un nouveau rectangle à un autre endroit de l'aire cliente
			CPen pen1(PS_DASHDOTDOT, 2, RGB(0, 150, 255));
			//définit un nouveau crayon et le sélectionne dans le CDP
			pDC->SelectObject(&pen1);
			//comme précédemment mais à un autre endroit de l'aire cliente
			for (int i = 1; i < pDoc->GetTaille(); i++)
			{
				pDC->MoveTo(3 * (rect.left + rect.right) / 4 + 100 * pDoc->pxDoc[i - 1],
					(rect.left + rect.right) / 4 + 100 * pDoc->pyDoc[i - 1]);
				pDC->LineTo(3 * (rect.left + rect.right) / 4 +
					100 * pDoc->pxDoc[i], (rect.left + rect.right) / 4 + 100 * pDoc->pyDoc[i]);
			}
			pDC->SelectObject(&pOldPen); //restaure le CDP dans son état initial  					    
										 // afin d'éviter les fuites de mémoire	
		}
		//sinon, on vient de OnAffichageEnModegraphique() mais on a annulé l'opération dessin
		else {
			pDC->TextOut((int)(rect.Width() / 10.0),
				(int)(rect.Height() / 10.0 + 22),
				pDoc->GetChaine()[0], pDoc->GetChaine()[0].GetLength());
		}
		break;
	}
	break;
	}
}


// impression de CTutoTP2View


void CTutoTP2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTutoTP2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// préparation par défaut
	return DoPreparePrinting(pInfo);
}

void CTutoTP2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez une initialisation supplémentaire avant l'impression
}

void CTutoTP2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez un nettoyage après l'impression
}

void CTutoTP2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTutoTP2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// diagnostics de CTutoTP2View

#ifdef _DEBUG
void CTutoTP2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CTutoTP2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CTutoTP2Doc* CTutoTP2View::GetDocument() const // la version non Debug est inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTutoTP2Doc)));
	return (CTutoTP2Doc*)m_pDocument;
}
#endif //_DEBUG


// gestionnaires de messages de CTutoTP2View


void CTutoTP2View::OnInitialUpdate()
{
	SetScrollSizes(MM_TEXT, GetDocument()->getDocSize());
	CScrollView::OnInitialUpdate();

	// TODO: ajoutez ici votre code spécialisé et/ou l'appel de la classe de base
}
