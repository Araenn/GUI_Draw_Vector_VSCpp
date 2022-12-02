#include "pch.h"
#include "Vecteurs.h"

Vecteurs::Vecteurs() {
	m_inech = 16;
	m_dfreq = 10.0;
	px = new double[m_inech];
	py = new double[m_inech];


	for (int i = 0; i < m_inech; i++) {
		px[i] = 0.0;
		py[i] = 0.0;
	}
}

Vecteurs::Vecteurs(int taille) {
	m_inech = taille;
	m_dfreq = 10.0;
	px = new double[m_inech];
	py = new double[m_inech];


	for (int i = 0; i < m_inech; i++) {
		px[i] = 0.0;
		py[i] = 0.0;
	}
}

Vecteurs::~Vecteurs() {
	delete[] px;
	delete[] py;
}

void Vecteurs::Remplit() {
	for (int i = 0; i < m_inech; i++) {
		px[i] = sin(m_dfreq * i);
		py[i] = cos(m_dfreq * i);
	}
}

int Vecteurs::Getnech() {
	return m_inech;
}

double Vecteurs::GetTabx(int k) {
	return px[k];
}

double Vecteurs::GetTaby(int k) {
	return py[k];
}

CString* Vecteurs::Exchange() { 
	CString* pxaff; 
	CString  temp; pxaff = new  CString[m_inech]; 
	for (int i = 0; i < m_inech; i++) { 
		pxaff[i] = "x["; 
		temp.Format(_T("%2i"), i); 
		pxaff[i] = pxaff[i] + temp + (CString)"]="; 
		temp.Format(_T("% .4f"), px[i]); 
		pxaff[i] = pxaff[i] + temp + (CString)"         y["; 
		temp.Format(_T("%2i"), i); pxaff[i] = pxaff[i] + temp + (CString)"]="; 
		temp.Format(_T("% .4f"), py[i]); 
		pxaff[i] = pxaff[i] + temp; 
	}
	return  pxaff; 
}
