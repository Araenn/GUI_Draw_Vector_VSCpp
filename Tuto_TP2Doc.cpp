
// Tuto_TP2Doc.cpp : implémentation de la classe CTutoTP2Doc
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL, et permettent le partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "Tuto_TP2.h"
#endif

#include "Tuto_TP2Doc.h"

#include <propkey.h>

#include "Vecteurs.h"
#include "Saisie_valeur_tableau.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTutoTP2Doc

IMPLEMENT_DYNCREATE(CTutoTP2Doc, CDocument)

BEGIN_MESSAGE_MAP(CTutoTP2Doc, CDocument)
	ON_COMMAND(ID_AFFICHAGE_ENMODETEXTE, &CTutoTP2Doc::OnAffichageEnmodetexte)
	ON_COMMAND(ID_AFFICHAGE_ENMODEGRAPH, &CTutoTP2Doc::OnAffichageEnmodegraph)
END_MESSAGE_MAP()


// construction/destruction de CTutoTP2Doc

CTutoTP2Doc::CTutoTP2Doc() noexcept :
	pxDoc(NULL),
	pyDoc(NULL),
	m_iaff(0),
	pxaff(NULL)
{
	// TODO: ajoutez ici le code d'une construction unique
	flag = 0;
}

CTutoTP2Doc::~CTutoTP2Doc()
{
	if (pxaff != NULL) delete[] pxaff;
	if (pxDoc != NULL) delete[] pxDoc;
	if (pyDoc != NULL) delete[] pyDoc;
}

BOOL CTutoTP2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	InitDocument();
	// TODO: ajoutez ici le code de réinitialisation
	// (les documents SDI réutiliseront ce document)

	return TRUE;
}




// sérialisation de CTutoTP2Doc

void CTutoTP2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ajoutez ici le code de stockage
	}
	else
	{
		// TODO: ajoutez ici le code de chargement
	}
}

#ifdef SHARED_HANDLERS

// Prise en charge des miniatures
void CTutoTP2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CTutoTP2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Définir le contenu de recherche à partir des données du document.
	// Les parties du contenu doivent être séparées par ";"

	// Par exemple :  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTutoTP2Doc::SetSearchContent(const CString& value)
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

// diagnostics de CTutoTP2Doc

#ifdef _DEBUG
void CTutoTP2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTutoTP2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// commandes de CTutoTP2Doc


void CTutoTP2Doc::OnAffichageEnmodetexte()
{
	// TODO: ajoutez ici le code de votre gestionnaire de commande
	flag = 1;
	Saisie_valeur_tableau dlg;
	int result = dlg.DoModal();

	if (result == IDOK) {
		m_iaff = dlg.m_itaille;
		Vecteurs vect(m_iaff);
		vect.Remplit();
		pxaff = new CString[m_iaff];
		if (pxaff != NULL) {
			delete[] pxaff;
			pxaff = new  CString[m_iaff];
			pxaff = vect.Exchange();
		}
		else {
			m_iaff = 1; 
			if (pxaff != NULL) delete[]  pxaff; 
			pxaff = new  CString[m_iaff]; 
			pxaff[0] = "Annulation  de l’opération";
		}
	}
	UpdateAllViews(0);  
}


void CTutoTP2Doc::OnAffichageEnmodegraph()
{
	// TODO: ajoutez ici le code de votre gestionnaire de commande
	flag = 2;
	Saisie_valeur_tableau dlg;
	int result = dlg.DoModal();

	if (result == IDOK) {
		m_iaff = dlg.m_itaille;
		pxDoc = new double[m_iaff];
		pyDoc = new double[m_iaff];
		Vecteurs vect(m_iaff);
		vect.Remplit();
		pxaff = new CString[m_iaff];
		if (pxaff != NULL) {
			delete[] pxaff;
			pxaff = new  CString[m_iaff];
			pxaff = vect.Exchange();
		}
		else {
			m_iaff = 1;
			if (pxaff != NULL) delete[]  pxaff;
			pxaff = new  CString[m_iaff];
			pxaff[0] = "Annulation  de l’opération";
		}

		for (int i = 0; i < m_iaff; i++) {
			pxDoc[i] = vect.GetTabx(i);
			pyDoc[i] = vect.GetTaby(i);
		}
	} else {
		m_iaff = 1;
		if (pxaff != NULL) delete[]  pxaff;
		pxaff = new  CString[m_iaff];
		pxaff[0] = "Annulation  de l’opération";
	}
	UpdateAllViews(0);
}


int CTutoTP2Doc::GetTaille()
{
	// TODO: Ajoutez ici votre code d'implémentation..
	return m_iaff;
}


CString* CTutoTP2Doc::GetChaine()
{
	// TODO: Ajoutez ici votre code d'implémentation..
	return pxaff;
}

void CTutoTP2Doc::InitDocument() {
	m_sizeDoc = CSize(8000, 9000);
}

CSize CTutoTP2Doc::getDocSize()
{
	// TODO: Ajoutez ici votre code d'implémentation..
	return m_sizeDoc;
}


BOOL CTutoTP2Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  Ajoutez ici votre code de création spécialisé
	InitDocument();
	return TRUE;
}
