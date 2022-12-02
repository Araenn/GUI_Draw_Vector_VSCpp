#pragma once
class Vecteurs
{
private:
	double *px;
	double *py;

	double m_dfreq;
	int m_inech;

public:
	Vecteurs();
	Vecteurs(int);
	~Vecteurs();
	void Remplit();
	int Getnech();
	double GetTabx(int k);
	double GetTaby(int k);
	CString* Exchange();
};

