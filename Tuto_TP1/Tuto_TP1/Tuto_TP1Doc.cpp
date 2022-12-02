
// Tuto_TP1Doc.cpp : implémentation de la classe CTutoTP1Doc
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL, et permettent le partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "Tuto_TP1.h"
#endif

#include "Tuto_TP1Doc.h"
#include <propkey.h>


#include "MaBoiteBis.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTutoTP1Doc

IMPLEMENT_DYNCREATE(CTutoTP1Doc, CDocument)

BEGIN_MESSAGE_MAP(CTutoTP1Doc, CDocument)
	ON_COMMAND(ID_MENU_EXEMPLE, &CTutoTP1Doc::OnMenuExemple)
	ON_COMMAND(ID_EXEMPLE2_SAISIE, &CTutoTP1Doc::OnExemple2Saisie)
	ON_COMMAND(ID_EXEMPLE2_RAFRAICHISSEMENT, &CTutoTP1Doc::OnExemple2Rafraichissement)
END_MESSAGE_MAP()


// construction/destruction de CTutoTP1Doc

CTutoTP1Doc::CTutoTP1Doc() noexcept
{
	// TODO: ajoutez ici le code d'une construction unique

}

CTutoTP1Doc::~CTutoTP1Doc()
{
}

BOOL CTutoTP1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ajoutez ici le code de réinitialisation
	// (les documents SDI réutiliseront ce document)
	m_xaff = " Pas de saisie ";
	return TRUE;
}




// sérialisation de CTutoTP1Doc

void CTutoTP1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_xaff;	// TODO: ajoutez ici le code de stockage
	}
	else
	{
		ar >> m_xaff;	// TODO: ajoutez ici le code de chargement
	}
}

#ifdef SHARED_HANDLERS

// Prise en charge des miniatures
void CTutoTP1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modifier ce code pour dessiner les données du document
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support pour les gestionnaires de recherche
void CTutoTP1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Définir le contenu de recherche à partir des données du document.
	// Les parties du contenu doivent être séparées par ";"

	// Par exemple :  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTutoTP1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// diagnostics de CTutoTP1Doc

#ifdef _DEBUG
void CTutoTP1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTutoTP1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// commandes de CTutoTP1Doc


void CTutoTP1Doc::OnMenuExemple()
{
	// TODO: ajoutez ici le code de votre gestionnaire de commande
	AfxMessageBox (_T ("OK , ca marche ") , MB_OK , NULL );
	MaBoiteBis dlg;
	dlg.DoModal();
}




void CTutoTP1Doc::OnExemple2Saisie()
{
	// TODO: ajoutez ici le code de votre gestionnaire de commande
	MaBoiteBis dlg;
	dlg.DoModal();
	m_xaff = "Texte saisi dans la boite de dialogue : ";
	m_xaff += dlg.m_xsaisie;
}


void CTutoTP1Doc::OnExemple2Rafraichissement()
{
	// TODO: ajoutez ici le code de votre gestionnaire de commande
	UpdateAllViews(0);
}
