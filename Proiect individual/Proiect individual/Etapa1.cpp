#include <iostream>

using namespace std;

class Spital {
private:
	const int anInfiintare = 0;
	char* nume;
	int nrMedici = 0;
	string* specializareMedici = NULL;
	int nrSaloaneDisp = 0;
	int nrPaturiDisp[50];
	int nrPacienti = 0;
public:

	int getAnInfiintare() {
		return this->anInfiintare;
	}

	char* getNume() {
		return this->nume;
	}

	int getNrMedici() {
		return this->nrMedici;
	}

	string* getSpecializareMedici() {
		return this->specializareMedici;
	}

	int getNrSaloaneDisp() {
		return this->nrSaloaneDisp;
	}

	int getNrPaturiDisp() {
		for (int i = 0; i < this->nrSaloaneDisp; i++)
			return this->nrPaturiDisp[i];
	}

	int getNrPacienti() {
		return this->nrPacienti;
	}

	void setNume(char* nume) {
		delete[] this->nume;
		if (strlen(nume) < 1) {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		else {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
	}

	void setNrMedici(int nrMedici, string* specializare) {
		if (nrMedici > 0 && specializare != NULL) {
			delete[] this->specializareMedici;
			this->nrMedici = nrMedici;
			this->specializareMedici = new string[nrMedici];
			for (int i = 0; i < nrMedici; i++)
				this->specializareMedici[i] = specializare[i];
		}
		else {
			this->nrMedici = 0;
			this->specializareMedici = NULL;
		}
	}

	void setNrSaloaneDisp(int nrSaloane, int nrPaturi[50]) {
		if (nrSaloane > 0) {
			this->nrSaloaneDisp = nrSaloane;
			for (int i = 0; i < nrSaloane; i++)
				this->nrPaturiDisp[i] = nrPaturi[i];
		}
	}

	void setNrPacienti(int nrPacienti) {
		if (nrPacienti > 0)
			this->nrPacienti = nrPacienti;
		else
			this->nrPacienti = 0;
	}

	Spital(int anInfiintare) :anInfiintare(anInfiintare) {
		cout << "\nConstructor fara parametri";
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
	}

	Spital(int anInfiintare, char* nume, int nrMedici, string* specializareMedici, int nrSaloaneDisp, int nrPaturiDisp[50], int nrPacienti) :anInfiintare(anInfiintare) {
		cout << "\nConstructor cu toti parametrii";
		if (strlen(nume) < 1) {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		else {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		if (nrMedici > 0 && specializareMedici != NULL) {
			this->nrMedici = nrMedici;
			this->specializareMedici = new string[this->nrMedici];
			for (int i = 0; i < nrMedici; i++)
				this->specializareMedici[i] = specializareMedici[i];
		}
		else {
			this->nrMedici = 0;
			this->specializareMedici = NULL;
		}
		if (nrSaloaneDisp > 0) {
			this->nrSaloaneDisp = nrSaloaneDisp;
			for (int i = 0; i < nrSaloaneDisp; i++)
				this->nrPaturiDisp[i] = nrPaturiDisp[i];
		}
		if (nrPacienti > 0)
			this->nrPacienti = nrPacienti;
		else
			this->nrPacienti = 0;
	}

	Spital(const Spital& s) :anInfiintare(s.anInfiintare) {
		cout << "\nConstructor de copiere";
		if (strlen(s.nume) < 1) {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		else {
			this->nume = new char[strlen(s.nume) + 1];
			strcpy(this->nume, s.nume);
		}
		if (s.nrMedici > 0 && s.specializareMedici != NULL) {
			this->nrMedici = s.nrMedici;
			this->specializareMedici = new string[this->nrMedici];
			for (int i = 0; i < s.nrMedici; i++)
				this->specializareMedici[i] = s.specializareMedici[i];
		}
		else {
			this->nrMedici = 0;
			this->specializareMedici = NULL;
		}
		if (s.nrSaloaneDisp > 0) {
			this->nrSaloaneDisp = s.nrSaloaneDisp;
			for (int i = 0; i < s.nrSaloaneDisp; i++)
				this->nrPaturiDisp[i] = s.nrPaturiDisp[i];
		}
		if (s.nrPacienti > 0)
			this->nrPacienti = s.nrPacienti;
		else
			this->nrPacienti = 0;
	}

	Spital& operator=(const Spital& s) {
		if (this != &s) {
			cout << "\nApel operator =";
			delete[] this->nume;
			delete[] this->specializareMedici;
			if (strlen(s.nume) < 1) {
				this->nume = new char[strlen("Necunoscut") + 1];
				strcpy(this->nume, "Necunoscut");
			}
			else {
				this->nume = new char[strlen(s.nume) + 1];
				strcpy(this->nume, s.nume);
			}
			if (s.nrMedici > 0 && s.specializareMedici != NULL) {
				this->nrMedici = s.nrMedici;
				this->specializareMedici = new string[this->nrMedici];
				for (int i = 0; i < s.nrMedici; i++)
					this->specializareMedici[i] = s.specializareMedici[i];
			}
			else {
				this->nrMedici = 0;
				this->specializareMedici = NULL;
			}
			if (s.nrSaloaneDisp > 0) {
				this->nrSaloaneDisp = s.nrSaloaneDisp;
				for (int i = 0; i < s.nrSaloaneDisp; i++)
					this->nrPaturiDisp[i] = s.nrPaturiDisp[i];
			}
			if (s.nrPacienti > 0)
				this->nrPacienti = s.nrPacienti;
			else
				this->nrPacienti = 0;
		}
		return *this;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->nrSaloaneDisp)
			return this->nrPaturiDisp[index];
		else
			throw new exception("\nIndex invalid");
	}

	Spital operator+(string specializare) {
		Spital copie = *this;
		copie.nrMedici++;
		string* aux = new string[copie.nrMedici];
		for (int i = 0; i < copie.nrMedici - 1; i++)
			aux[i] = copie.specializareMedici[i];
		aux[copie.nrMedici - 1] = specializare;
		delete[] copie.specializareMedici;
		copie.specializareMedici = aux;
		return copie;
	}

	Spital& operator++() {
		this->nrPacienti++;
		return *this;
	}

	Spital operator++(int) {
		Spital copie = *this;
		this->nrPacienti++;
		return copie;
	}

	explicit operator string() {
		return this->specializareMedici[this->nrMedici - 1];
	}

	bool operator!() {
		if (this->nrPacienti < 0)
			return true;
		else
			return false;
	}

	bool operator<(Spital s) {
		if (this->nrMedici < s.nrMedici)
			return true;
		else
			return false;
	}

	bool operator==(Spital s) {
		if (this->nrMedici == s.nrMedici)
			return true;
		else
			return false;
	}

	~Spital() {
		cout << "\nDestructor";  
		delete[] this->nume;
		delete[] this->specializareMedici;
	}

	friend ostream& operator<<(ostream& out, const Spital& s) {
		out << "\n-------------------------------------------------";
		out << "\nNume spital: " << s.nume;
		out << "\nAnul infiintarii: " << s.anInfiintare;
		out << "\nNumar pacienti: " << s.nrPacienti;
		out << "\nNumar medici: " << s.nrMedici;
		out << "\nSpecializare medici: ";
		for (int i = 0; i < s.nrMedici; i++)
			out << s.specializareMedici[i] << ", ";
		out << "\nNumarul saloanelor disponibile: " << s.nrSaloaneDisp;
		out << "\nNumar paturi disponibile: ";
		for (int i = 0; i < s.nrSaloaneDisp; i++)
			out << s.nrPaturiDisp[i] << " ";
		out << "\n-------------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Spital& s) {
		cout << "\nAdaugati nume spital: ";
		char buffer[200];
		in >> buffer;
		s.setNume(buffer);
		cout << "\nAdaugati numarul pacientilor: ";
		int nrPacienti;
		in >> nrPacienti;
		s.setNrPacienti(nrPacienti);
		cout << "\nAdaugati numarul de medici: ";
		int nrMedici;
		string specializare[200];
		in >> nrMedici;
		for (int i = 0; i < nrMedici; i++) {
			cout << "\nAdaugati specializarea mediciului " << i + 1 << ": ";
			in >> specializare[i];
		}
		s.setNrMedici(nrMedici, specializare);
		cout << "\nAdaugati numarul de saloane disponibile: ";
		int nrSaloane;
		int nrPaturi[200];
		in >> nrSaloane;
		for (int i = 0; i < nrSaloane; i++) {
			cout << "\nAdaugati numarul de paturi disponibile in sala " << i + 1 << ": ";
			in >> nrPaturi[i];
		}
		s.setNrSaloaneDisp(nrSaloane, nrPaturi);
		return in;
	}
};

class Laborator {
private:
	char* nume;
	int nrAsistente = 0;
	int nrServicii = 0;
	string* servicii = NULL;
	float preturi[50];
	bool* disponibilitate = NULL;

public:

	char* getNume() {
		return this->nume;
	}

	void setNume(char* nume) {
		if (strlen(nume) > 1) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			delete[] this->nume;
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
	}

	int getNrAsistente() {
		return this->nrAsistente;
	}

	void setNrAsistente(int nrAsistente) {
		if (nrAsistente > 0)
			this->nrAsistente = nrAsistente;
		else
			this->nrAsistente = 0;
	}

	int getNrServicii() {
		return this->nrServicii;
	}

	string* getServicii() {
		return this->servicii;
	}

	float getPreturi() {
		for (int i = 0; i < this->nrServicii; i++)
			return this->preturi[i];
	}

	bool* getDisponibilitate() {
		return this->disponibilitate;
	}

	void setNrServicii(int nrServicii, string* servicii, float preturi[50], bool* disponibilitate) {
		if (nrServicii > 0) {
			this->nrServicii = nrServicii;
			delete[] this->servicii;
			delete[] this->disponibilitate;
			this->servicii = new string[nrServicii];
			this->disponibilitate = new bool[nrServicii];
			for (int i = 0; i < nrServicii; i++) {
				this->servicii[i] = servicii[i];
				this->preturi[i] = preturi[i];
				this->disponibilitate[i] = disponibilitate[i];
			}
		}
		else {
			this->nrServicii = 0;
			this->servicii = NULL;
			this->disponibilitate = NULL;
		}
	}

	Laborator() {
		cout << "\nConstructor fara parametrii";
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
	}

	Laborator(char* nume, int nrAsistente, int nrServicii, string* servicii, float preturi[50], bool* disponibilitate) {
		cout << "\nConstructor cu parametrii";
		if (strlen(nume) > 1) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (nrAsistente > 0)
			this->nrAsistente = nrAsistente;
		else
			this->nrAsistente = 0;
		if (nrServicii > 0) {
			this->nrServicii = nrServicii;
			this->servicii = new string[nrServicii];
			this->disponibilitate = new bool[nrServicii];
			for (int i = 0; i < nrServicii; i++) {
				this->servicii[i] = servicii[i];
				this->preturi[i] = preturi[i];
				this->disponibilitate[i] = disponibilitate[i];
			}
		}
		else {
			this->nrServicii = 0;
			this->servicii = NULL;
			this->disponibilitate = NULL;
		}
	}

	Laborator(const Laborator& l) {
		cout << "\nConstructor de copiere";
		if (strlen(l.nume) > 1) {
			this->nume = new char[strlen(l.nume) + 1];
			strcpy(this->nume, l.nume);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (l.nrAsistente > 0)
			this->nrAsistente = l.nrAsistente;
		else
			this->nrAsistente = 0;
		if (l.nrServicii > 0) {
			this->nrServicii = l.nrServicii;
			this->servicii = new string[l.nrServicii];
			this->disponibilitate = new bool[l.nrServicii];
			for (int i = 0; i < l.nrServicii; i++) {
				this->servicii[i] = l.servicii[i];
				this->preturi[i] = l.preturi[i];
				this->disponibilitate[i] = l.disponibilitate[i];
			}
		}
		else {
			this->nrServicii = 0;
			this->servicii = NULL;
			this->disponibilitate = NULL;
		}
	}


	Laborator& operator=(const Laborator& l) {
		if (this != NULL) {
			cout << "\nApel operator =";
			delete[] this->nume;
			delete[] this->servicii;
			delete[] this->disponibilitate;
			if (strlen(l.nume) > 1) {
				this->nume = new char[strlen(l.nume) + 1];
				strcpy(this->nume, l.nume);
			}
			else {
				this->nume = new char[strlen("Necunoscut") + 1];
				strcpy(this->nume, "Necunoscut");
			}
			if (l.nrAsistente > 0)
				this->nrAsistente = l.nrAsistente;
			else
				this->nrAsistente = 0;
			if (l.nrServicii > 0) {
				this->nrServicii = l.nrServicii;
				this->servicii = new string[l.nrServicii];
				this->disponibilitate = new bool[l.nrServicii];
				for (int i = 0; i < l.nrServicii; i++) {
					this->servicii[i] = l.servicii[i];
					this->preturi[i] = l.preturi[i];
					this->disponibilitate[i] = l.disponibilitate[i];
				}
			}
			else {
				this->nrServicii = 0;
				this->servicii = NULL;
				this->disponibilitate = NULL;
			}
		}
		return *this;
	}

	string& operator[] (int index) {
		if (index >= 0 && index < this->nrServicii) {
			return this->servicii[index];
		}
		else {
			throw new exception("\nIndex invalid");
		}
	}

	Laborator operator+(string serviciu) {
		Laborator copie = *this;
		if (copie.nrServicii > 0) {
			string* serviciiTemp = new string[copie.nrServicii + 1];
			bool* disponibilitateTemp = new bool[copie.nrServicii + 1];
			float* preturiTemp = new float[copie.nrServicii + 1];
			for (int i = 0; i < copie.nrServicii; i++) {
				serviciiTemp[i] = copie.servicii[i];
				disponibilitateTemp[i] = copie.disponibilitate[i];
				preturiTemp[i] = copie.preturi[i];
			}
			serviciiTemp[copie.nrServicii] = serviciu;
			disponibilitateTemp[copie.nrServicii] = true;
			preturiTemp[copie.nrServicii] = 0;
			copie.nrServicii++;
			delete[] copie.servicii;
			delete[] copie.disponibilitate;
			copie.servicii = serviciiTemp;
			copie.disponibilitate = disponibilitateTemp;
			for (int i = 0; i < copie.nrServicii; i++)
				copie.preturi[i] = preturiTemp[i];
		}
		return copie;
	}

	Laborator& operator++() {
		this->nrAsistente++;
		return *this;
	}

	Laborator operator++(int) {
		Laborator copie = *this;
		this->nrAsistente++;
		return copie;
	}

	explicit operator int() {
		return this->nrAsistente;
	}

	bool operator!() {
		if (this->nrServicii < 0)
			return true;
		else
			return false;
	}

	bool operator>(Laborator l) {
		if (this->nrServicii > l.nrServicii)
			return true;
		else
			return false;
	}

	bool operator==(Laborator l) {
		if (this->nrServicii == l.nrServicii)
			return true;
		else
			return false;
	}

	~Laborator() {
		delete[] this->nume;
		delete[] this->servicii;
		delete[] this->disponibilitate;
	}

	friend ostream& operator<<(ostream& out, Laborator& l) {
		out << "\n------------------------------------------------";
		out << "\nNume laborator: " << l.nume;
		out << "\nNumar asistente: " << l.nrAsistente;
		out << "\nNumar servicii: " << l.nrServicii;
		out << "\nServicii: ";
		for (int i = 0; i < l.nrServicii; i++) {
			out << "\nServiciul " << i + 1 << ": " << l.servicii[i];
			out << "\nPret(lei): " << l.preturi[i];
			out << "\nDisponibilitate: ";
			if (l.disponibilitate[i] == true)
				out << "Disponibil";
			else
				out << "Indisponibil";
		}
		out << "\n------------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Laborator& l) {
		cout << "\nAdaugati numele laboratorului: ";
		char nume[200];
		in >> nume;
		l.setNume(nume);
		cout << "\nAdaugati numarul de asistente: ";
		int nrAsistente;
		in >> nrAsistente;
		l.setNrAsistente(nrAsistente);
		cout << "\nAdaugati numarul de servicii: ";
		int nrServicii;
		in >> nrServicii;
		string* servicii = new string[nrServicii];
		float* preturi = new float[nrServicii];
		bool* disponibilitate = new bool[nrServicii];
		for (int i = 0; i < nrServicii; i++) {
			cout << "\nAdaugati serviciul " << i + 1 << ": ";
			in >> servicii[i];
			cout << "\nAdaugati pretul serviciului " << i + 1 << ": ";
			in >> preturi[i];
			cout << "\nAdaugati disponibilitatea serviciului " << i + 1 << ": ";
			in >> disponibilitate[i];
		}
		l.setNrServicii(nrServicii, servicii, preturi, disponibilitate);
		return in;
	}


};

class Policlinica {
private:
	string oras = "Necunoscut";
	char* nume;
	int nrCabinete = 0;
	int nrSpecialitati = 0;
	string* specialitati = NULL;
	int nrInvestigatii = 0;
	string* investigatii = NULL;
	float pretInvestigatie[50];

public:

	string getOras() {
		return this->oras;
	}

	void setOras(string oras) {
		if (oras.length() > 0)
			this->oras = oras;
		else
			this->oras = "Necunoscut";
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(char* nume) {
		if (strlen(nume) > 0) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			delete[] this->nume;
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
	}

	int getNrCabinete() {
		return this->nrCabinete;
	}

	void setNrCabinete(int nrCabinete) {
		if (nrCabinete > 0)
			this->nrCabinete = nrCabinete;
		else
			this->nrCabinete = 0;
	}

	int getNrSpecialitati() {
		return this->nrSpecialitati;
	}

	string* getSpecialitati() {
		return this->specialitati;
	}

	void setNrSpecialitati(int nrSpecialitati, string* specialitati) {
		if (nrSpecialitati > 0) {
			this->nrSpecialitati = nrSpecialitati;
			delete[] this->specialitati;
			this->specialitati = new string[nrSpecialitati];
			for (int i = 0; i < nrSpecialitati; i++)
				this->specialitati[i] = specialitati[i];
		}
		else {
			this->nrSpecialitati = 0;
			delete[] this->specialitati;
			this->specialitati = NULL;
		}
	}

	int getNrInvestigatii() {
		return this->nrInvestigatii;
	}

	string* getInvestigatii() {
		return this->investigatii;
	}

	float getPretInvestigatie() {
		for (int i = 0; i < nrInvestigatii; i++)
			return this->pretInvestigatie[i];
	}

	void setNrInvestigatii(int nrInvestigatii, string* investigatii, float pretInvestigatie[50]) {
		if (nrInvestigatii > 0) {
			this->nrInvestigatii = nrInvestigatii;
			delete[] this->investigatii;
			this->investigatii = new string[nrInvestigatii];
			for (int i = 0; i < nrInvestigatii; i++) {
				this->investigatii[i] = investigatii[i];
				this->pretInvestigatie[i] = pretInvestigatie[i];
			}
		}
		else {
			this->nrInvestigatii = 0;
			delete[] this->investigatii;
			this->investigatii = NULL;
		}
	}

	Policlinica() {
		cout << "\nConstructor fara parametri";
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
	}

	Policlinica(string oras, char* nume, int nrCabinete, int nrSpecialitati, string* specialitati, int nrInvestigatii, string* investigatii, float pretInvestigatie[50]) {
		cout << "\nConstructor cu parametri";
		if (oras.length() > 0)
			this->oras = oras;
		else
			this->oras = "Necunoscut";
		if (strlen(nume) > 0) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (nrCabinete > 0)
			this->nrCabinete = nrCabinete;
		else
			this->nrCabinete = 0;
		if (nrSpecialitati > 0) {
			this->nrSpecialitati = nrSpecialitati;
			this->specialitati = new string[nrSpecialitati];
			for (int i = 0; i < nrSpecialitati; i++)
				this->specialitati[i] = specialitati[i];
		}
		else {
			this->nrSpecialitati = 0;
			this->specialitati = NULL;
		}
		if (nrInvestigatii > 0) {
			this->nrInvestigatii = nrInvestigatii;
			this->investigatii = new string[nrInvestigatii];
			for (int i = 0; i < nrInvestigatii; i++) {
				this->investigatii[i] = investigatii[i];
				this->pretInvestigatie[i] = pretInvestigatie[i];
			}
		}
		else {
			this->nrInvestigatii = 0;
			this->investigatii = NULL;
		}
	}

	Policlinica(const Policlinica& p) {
		cout << "\nConstructor de copiere";
		if (p.oras.length() > 0)
			this->oras = p.oras;
		else
			this->oras = "Necunoscut";
		if (strlen(p.nume) > 0) {
			this->nume = new char[strlen(p.nume) + 1];
			strcpy(this->nume, p.nume);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (p.nrCabinete > 0)
			this->nrCabinete = p.nrCabinete;
		else
			this->nrCabinete = 0;
		if (p.nrSpecialitati > 0) {
			this->nrSpecialitati = p.nrSpecialitati;
			this->specialitati = new string[p.nrSpecialitati];
			for (int i = 0; i < p.nrSpecialitati; i++)
				this->specialitati[i] = p.specialitati[i];
		}
		else {
			this->nrSpecialitati = 0;
			this->specialitati = NULL;
		}
		if (p.nrInvestigatii > 0) {
			this->nrInvestigatii = p.nrInvestigatii;
			this->investigatii = new string[p.nrInvestigatii];
			for (int i = 0; i < p.nrInvestigatii; i++) {
				this->investigatii[i] = p.investigatii[i];
				this->pretInvestigatie[i] = p.pretInvestigatie[i];
			}
		}
		else {
			this->nrInvestigatii = 0;
			this->investigatii = NULL;
		}
	}

	Policlinica& operator=(const Policlinica& p) {
		if (this != NULL) {
			cout << "\nApel operator =";
			if (p.oras.length() > 0)
				this->oras = p.oras;
			else
				this->oras = "Necunoscut";
			if (strlen(p.nume) > 0) {
				this->nume = new char[strlen(p.nume) + 1];
				strcpy(this->nume, p.nume);
			}
			else {
				this->nume = new char[strlen("Necunoscut") + 1];
				strcpy(this->nume, "Necunoscut");
			}
			if (p.nrCabinete > 0)
				this->nrCabinete = p.nrCabinete;
			else
				this->nrCabinete = 0;
			if (p.nrSpecialitati > 0) {
				this->nrSpecialitati = p.nrSpecialitati;
				this->specialitati = new string[p.nrSpecialitati];
				for (int i = 0; i < p.nrSpecialitati; i++)
					this->specialitati[i] = p.specialitati[i];
			}
			else {
				this->nrSpecialitati = 0;
				this->specialitati = NULL;
			}
			if (p.nrInvestigatii > 0) {
				this->nrInvestigatii = p.nrInvestigatii;
				this->investigatii = new string[p.nrInvestigatii];
				for (int i = 0; i < p.nrInvestigatii; i++) {
					this->investigatii[i] = p.investigatii[i];
					this->pretInvestigatie[i] = p.pretInvestigatie[i];
				}
			}
			else {
				this->nrInvestigatii = 0;
				this->investigatii = NULL;
			}
		}
		return *this;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrInvestigatii)
			return this->pretInvestigatie[index];
		else
			throw new exception("\nIndex invalid");
	}

	Policlinica operator+(string specialitate) {
		Policlinica copie = *this;
		if (copie.nrSpecialitati > 0) {
			copie.nrSpecialitati++;
			string* aux = new string[copie.nrSpecialitati];
			for (int i = 0; i < copie.nrSpecialitati - 1; i++)
				aux[i] = copie.specialitati[i];
			aux[copie.nrSpecialitati - 1] = specialitate;
			delete[] copie.specialitati;
			copie.specialitati = aux;
		}
		else {
			copie.nrSpecialitati = 1;
			copie.specialitati = new string[1];
			copie.specialitati[0] = specialitate;
		}
		return copie;
	}

	Policlinica& operator--() {
		if (this->nrInvestigatii > 0) {
			string* aux = new string[this->nrInvestigatii - 1];
			float* aux2 = new float[this->nrInvestigatii - 1];
			for (int i = 0; i < this->nrInvestigatii - 1; i++) {
				aux[i] = this->investigatii[i];
				aux2[i] = this->pretInvestigatie[i];
			}
			this->nrInvestigatii--;
			delete[] this->investigatii;
			this->investigatii = aux;
			for (int i = 0; i < this->nrInvestigatii; i++)
				this->pretInvestigatie[i] = aux2[i];
		}
		return *this;
	}

	Policlinica operator--(int) {
		Policlinica copie = *this;
		if (this->nrInvestigatii > 0) {
			string* aux = new string[this->nrInvestigatii - 1];
			float* aux2 = new float[this->nrInvestigatii - 1];
			for (int i = 0; i < this->nrInvestigatii - 1; i++) {
				aux[i] = this->investigatii[i];
				aux2[i] = this->pretInvestigatie[i];
			}
			this->nrInvestigatii--;
			delete[] this->investigatii;
			this->investigatii = aux;
			for (int i = 0; i < this->nrInvestigatii; i++)
				this->pretInvestigatie[i] = aux2[i];
		}
		return copie;
	}

	explicit operator int() {
		return this->nrSpecialitati;
	}

	bool operator!() {
		if (this->nrInvestigatii < 0)
			return true;
		else
			return false;
	}

	bool operator<=(Policlinica p) {
		if (this->nrInvestigatii <= p.nrInvestigatii)
			return true;
		else
			return false;
	}

	bool operator==(Policlinica p) {
		if (this->oras == p.oras && strcmp(this->nume, p.nume) == 0)
			return true;
		else
			return false;
	}

	~Policlinica() {
		cout << "\nDestructor";
		delete[] this->nume;
		delete[] this->specialitati;
		delete[] this->investigatii;
	}

	friend ostream& operator<<(ostream& out, const Policlinica& p) {
		out << "\n-------------------------------------------------";
		out << "\nOras: " << p.oras;
		out << "\nNume: " << p.nume;
		out << "\nNr cabinete: " << p.nrCabinete;
		out << "\nNr specialitati: " << p.nrSpecialitati;
		out << "\nSpecialitati: ";
		for (int i = 0; i < p.nrSpecialitati; i++)
			out << p.specialitati[i] << ", ";
		out << "\nNr investigatii: " << p.nrInvestigatii;
		for (int i = 0; i < p.nrInvestigatii; i++)
			out << "\nInvestigatia " << i + 1 << ": " << p.investigatii[i] << " - " << p.pretInvestigatie[i];
		out << "\n-------------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Policlinica& p) {
		cout << "\nIntroduceti orasul: ";
		string oras;
		in >> oras;
		p.setOras(oras);
		cout << "\nIntroduceti numele: ";
		char nume[100];
		in >> nume;
		p.setNume(nume);
		cout << "\nIntroduceti nr cabinete: ";
		int nrCabinete;
		in >> nrCabinete;
		p.setNrCabinete(nrCabinete);
		cout << "\nIntroduceti nr specialitati: ";
		int nrSpecialitati;
		in >> nrSpecialitati;
		string* specialitati = new string[nrSpecialitati];
		for (int i = 0; i < nrSpecialitati; i++) {
			cout << "\nIntroduceti specialitatea " << i + 1 << ": ";
			in >> specialitati[i];
		}
		p.setNrSpecialitati(nrSpecialitati, specialitati);
		cout << "\nIntroduceti nr investigatii: ";
		int nrInvestigatii;
		in >> nrInvestigatii;
		string* investigatii = new string[nrInvestigatii];
		float* pretInvestigatie = new float[nrInvestigatii];
		for (int i = 0; i < nrInvestigatii; i++) {
			cout << "\nIntroduceti investigatia " << i + 1 << ": ";
			in >> investigatii[i];
			cout << "\nIntroduceti pretul investigatiei " << i + 1 << ": ";
			in >> pretInvestigatie[i];
		}
		p.setNrInvestigatii(nrInvestigatii, investigatii, pretInvestigatie);
		return in;
	}
};

class Boala {
private:
	const int anAparitie;
	char* nume;
	int nrSimptome = 0;
	string* simptome = NULL;
	int nrCazuri = 0;
	int nrLuniImbolnavire = 0;
	string* luniImbolnavire = NULL;
	int nrCazuriLuna[50];
	static int decese;

public:

	int getAnAparitie() {
		return this->anAparitie;
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(char* nume) {
		if (strlen(nume) > 1) {
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			delete[] this->nume;
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
	}

	int getNrSimptome() {
		return this->nrSimptome;
	}

	string* getSimptome() {
		return this->simptome;
	}

	void setNrSimptome(int nrSimptome, string* simptome) {
		if (nrSimptome > 0 && simptome != NULL) {
			delete[] this->simptome;
			this->simptome = new string[nrSimptome];
			for (int i = 0; i < nrSimptome; i++)
				this->simptome[i] = simptome[i];
			this->nrSimptome = nrSimptome;
		}
		else {
			delete[] this->simptome;
			this->nrSimptome = 0;
			this->simptome = NULL;
		}
	}

	int getNrCazuri() {
		return this->nrCazuri;
	}

	void setNrCazuri(int nrCazuri) {
		if (nrCazuri > 0)
			this->nrCazuri = nrCazuri;
		else
			this->nrCazuri = 0;
	}

	int getNrLuniImbolnavire() {
		return this->nrLuniImbolnavire;
	}

	string* getLuniImbolnavire() {
		return this->luniImbolnavire;
	}

	int getNrCazuriLuna() {
		for (int i = 0; i < this->nrLuniImbolnavire; i++)
			return this->nrCazuriLuna[i];
	}

	void setNrLuniImbolnavire(int nrLuniImbolnavire, string* luniImbolnavire, int nrCazuriLuna[50]) {
		if (nrLuniImbolnavire > 0 && luniImbolnavire != NULL) {
			int nrCazuriTot = 0;
			for (int i = 0; i < nrLuniImbolnavire; i++)
				nrCazuriTot += nrCazuriLuna[i];
			if (this->nrCazuri == nrCazuriTot) {
				delete[] this->luniImbolnavire;
				this->luniImbolnavire = new string[nrLuniImbolnavire];
				for (int i = 0; i < nrLuniImbolnavire; i++) {
					this->luniImbolnavire[i] = luniImbolnavire[i];
					this->nrCazuriLuna[i] = nrCazuriLuna[i];
				}
				this->nrLuniImbolnavire = nrLuniImbolnavire;
			}
		}
		else {
			this->nrCazuri = 0;
			this->luniImbolnavire = NULL;
		}
	}

	static int getDecese() {
		return decese;
	}

	static void setDecese(int decese) {
		Boala::decese = decese;
	}

	Boala(int anAparitie) :anAparitie(anAparitie) {
		cout << "\nConstructor fara parametrii";
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
	}

	Boala(int anAparitie, char* nume, int nrSimptome, string* simptome, int nrCazuri, int nrLuniImbolnavire, string* luniImbolnavire, int nrCazuriLuna[50]) :anAparitie(anAparitie) {
		cout << "\nConstructor cu parametrii";
		if (strlen(nume) > 1) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (nrSimptome > 0 && simptome != NULL) {
			this->simptome = new string[nrSimptome];
			for (int i = 0; i < nrSimptome; i++)
				this->simptome[i] = simptome[i];
			this->nrSimptome = nrSimptome;
		}
		else {
			this->nrSimptome = 0;
			this->simptome = NULL;
		}
		if (nrCazuri > 0)
			this->nrCazuri = nrCazuri;
		else
			this->nrCazuri = 0;
		if (nrLuniImbolnavire > 0 && luniImbolnavire != NULL && nrCazuriLuna != NULL) {
			int nrCazuriTot = 0;
			for (int i = 0; i < nrLuniImbolnavire; i++)
				nrCazuriTot += nrCazuriLuna[i];
			if (this->nrCazuri == nrCazuriTot) {
				this->luniImbolnavire = new string[nrLuniImbolnavire];
				for (int i = 0; i < nrLuniImbolnavire; i++) {
					this->luniImbolnavire[i] = luniImbolnavire[i];
					this->nrCazuriLuna[i] = nrCazuriLuna[i];
				}
				this->nrLuniImbolnavire = nrLuniImbolnavire;
			}
		}
		else {
			this->nrLuniImbolnavire = 0;
			this->luniImbolnavire = NULL;
		}
	}

	Boala(const Boala& b) :anAparitie(b.anAparitie) {
		cout << "\nConstructor de copiere";
		if (strlen(b.nume) > 1) {
			this->nume = new char[strlen(b.nume) + 1];
			strcpy(this->nume, b.nume);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (b.nrSimptome > 0 && b.simptome != NULL) {
			this->simptome = new string[b.nrSimptome];
			for (int i = 0; i < b.nrSimptome; i++)
				this->simptome[i] = b.simptome[i];
			this->nrSimptome = b.nrSimptome;
		}
		else {
			this->nrSimptome = 0;
			this->simptome = NULL;
		}
		if (b.nrCazuri > 0)
			this->nrCazuri = b.nrCazuri;
		else
			this->nrCazuri = 0;
		if (b.nrLuniImbolnavire > 0 && b.luniImbolnavire != NULL && b.nrCazuriLuna != NULL) {
			int nrCazuriTot = 0;
			for (int i = 0; i < b.nrLuniImbolnavire; i++)
				nrCazuriTot += b.nrCazuriLuna[i];
			if (this->nrCazuri == nrCazuriTot) {
				this->luniImbolnavire = new string[b.nrLuniImbolnavire];
				for (int i = 0; i < b.nrLuniImbolnavire; i++) {
					this->luniImbolnavire[i] = b.luniImbolnavire[i];
					this->nrCazuriLuna[i] = b.nrCazuriLuna[i];
				}
				this->nrLuniImbolnavire = b.nrLuniImbolnavire;
			}
		}
		else {
			this->nrLuniImbolnavire = 0;
			this->luniImbolnavire = NULL;
		}
	}

	Boala& operator=(const Boala& b) {
		if (this != NULL) {
			cout << "\nApel operator =";
			delete[] this->luniImbolnavire;
			delete[] this->simptome;
			delete[] this->nume;
			if (strlen(b.nume) > 1) {
				this->nume = new char[strlen(b.nume) + 1];
				strcpy(this->nume, b.nume);
			}
			else {
				this->nume = new char[strlen("Necunoscut") + 1];
				strcpy(this->nume, "Necunoscut");
			}
			if (b.nrSimptome > 0 && b.simptome != NULL) {
				this->simptome = new string[b.nrSimptome];
				for (int i = 0; i < b.nrSimptome; i++)
					this->simptome[i] = b.simptome[i];
				this->nrSimptome = b.nrSimptome;
			}
			else {
				this->nrSimptome = 0;
				this->simptome = NULL;
			}
			if (b.nrCazuri > 0)
				this->nrCazuri = b.nrCazuri;
			else
				this->nrCazuri = 0;
			if (b.nrLuniImbolnavire > 0 && b.luniImbolnavire != NULL && b.nrCazuriLuna != NULL) {
				int nrCazuriTot = 0;
				for (int i = 0; i < b.nrLuniImbolnavire; i++)
					nrCazuriTot += b.nrCazuriLuna[i];
				if (this->nrCazuri == nrCazuriTot) {
					this->luniImbolnavire = new string[b.nrLuniImbolnavire];
					for (int i = 0; i < b.nrLuniImbolnavire; i++) {
						this->luniImbolnavire[i] = b.luniImbolnavire[i];
						this->nrCazuriLuna[i] = b.nrCazuriLuna[i];
					}
					this->nrLuniImbolnavire = b.nrLuniImbolnavire;
				}
			}
			else {
				this->nrLuniImbolnavire = 0;
				this->luniImbolnavire = NULL;
			}
		}
		return *this;
	}

	string operator[](int index) {
		if (index >= 0 && index < this->nrSimptome)
			return this->simptome[index];
		else
			throw new exception("\nIndex invalid");
	}

	Boala operator+(string simptom) {
		Boala rez = *this;
		rez.nrSimptome++;
		string* simptomeNou = new string[rez.nrSimptome];
		for (int i = 0; i < rez.nrSimptome - 1; i++)
			simptomeNou[i] = rez.simptome[i];
		simptomeNou[rez.nrSimptome - 1] = simptom;
		delete[] rez.simptome;
		rez.simptome = simptomeNou;
		return rez;
	}

	Boala& operator++() {
		if (this->nrLuniImbolnavire > 0) {
			for (int i = 0; i < this->nrLuniImbolnavire; i++)
			{
				this->nrCazuriLuna[i]++;
				this->nrCazuri++;
			}
		}
		return *this;
	}

	Boala operator++(int) {
		Boala rez = *this;
		if (this->nrLuniImbolnavire > 0) {
			for (int i = 0; i < this->nrLuniImbolnavire; i++)
			{
				this->nrCazuriLuna[i]++;
				this->nrCazuri++;
			}
		}
		return rez;
	}

	explicit operator int() {
		return this->nrCazuri;
	}

	bool operator!() {
		if (this->nrCazuri < 0)
			return true;
		else
			return false;
	}

	bool operator>=(Boala b) {
		if (this->nrCazuri >= b.nrCazuri)
			return true;
		else
			return false;
	}

	bool operator==(Boala b) {
		if (this->nrCazuri == b.nrCazuri)
			return true;
		else
			return false;
	}

	~Boala() {
		delete[] this->nume;
		delete[] this->simptome;
		delete[] this->luniImbolnavire;
	}

	friend ostream& operator<<(ostream& out, Boala& b) {
		out << "\n-----------------------------------------";
		out << "\nNume boala: " << b.nume;
		out << "\nAn aparitie: " << b.anAparitie;
		out << "\nSimptome: ";
		for (int i = 0; i < b.nrSimptome; i++)
			out << b.simptome[i] << ", ";
		out << "\nNr cazuri: " << b.nrCazuri;
		out << "\nNr luni imboliavire: " << b.nrLuniImbolnavire;
		for (int i = 0; i < b.nrLuniImbolnavire; i++)
			out << "\nLuna " << b.luniImbolnavire[i] << ": " << b.nrCazuriLuna[i] << " cazuri";
		out << "\n-----------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Boala& b) {
		cout << "\nNume boala: ";
		char buffer[100];
		in >> buffer;
		b.setNume(buffer);
		cout << "\nNr simptome: ";
		int nrSimptome;
		in >> nrSimptome;
		string* simptome = new string[nrSimptome];
		for (int i = 0; i < nrSimptome; i++) {
			cout << "\nSimptom " << i + 1 << ": ";
			in >> simptome[i];
		}
		b.setNrSimptome(nrSimptome, simptome);
		cout << "\nNr cazuri: ";
		int nrCazuri;
		in >> nrCazuri;
		b.setNrCazuri(nrCazuri);
		cout << "\nNr luni imboliavire: ";
		int nrLuniImbolnavire;
		in >> nrLuniImbolnavire;
		string* luniImbolnavire = new string[nrLuniImbolnavire];
		int* nrCazuriLuna = new int[nrLuniImbolnavire];
		for (int i = 0; i < nrLuniImbolnavire; i++) {
			cout << "\nLuna " << i + 1 << ": ";
			in >> luniImbolnavire[i];
			cout << "\nNr cazuri: ";
			in >> nrCazuriLuna[i];
		}
		b.setNrLuniImbolnavire(nrLuniImbolnavire, luniImbolnavire, nrCazuriLuna);
		return in;
	}
};

int Boala::decese = 0;

class AutospecialeMedicale {
private:
	char* Interventie;
	string tipAutospeciala = "Necunoscut";
	int nrPersoaneAutorizate = 0;
	string* specializare = NULL;
	int nrKm_oreZbor = 0;
	int nrRevizii = 0;
	float revizie[50];
	bool disponibilitate = true;

public:

	char* getInterventie() {
		return this->Interventie;
	}

	void setInterventie(char* Interventie) {
		if (strlen(Interventie) > 1) {
			delete[] this->Interventie;
			this->Interventie = new char[strlen(Interventie) + 1];
			strcpy(this->Interventie, Interventie);
		}
		else {
			this->Interventie = new char[strlen("Necunoscuta") + 1];
			strcpy(this->Interventie, "Necunoscuta");
		}
	}

	string getTipAutospeciala() {
		return this->tipAutospeciala;
	}

	void setTipAutospeciala(string tipAutospeciala) {
		if (tipAutospeciala.length() > 1)
			this->tipAutospeciala = tipAutospeciala;
		else
			this->tipAutospeciala = "Necunoscut";
	}

	int getNrPersoaneAutorizate() {
		return this->nrPersoaneAutorizate;
	}

	string* getSpecializare() {
		return this->specializare;
	}

	void setNrPersoaneAutorizate(int nrPersoaneAutorizate, string* specializare) {
		if (nrPersoaneAutorizate > 0 && specializare != NULL) {
			this->nrPersoaneAutorizate = nrPersoaneAutorizate;
			delete[] this->specializare;
			this->specializare = new string[nrPersoaneAutorizate];
			for (int i = 0; i < nrPersoaneAutorizate; i++)
				this->specializare[i] = specializare[i];
		}
		else {
			this->nrPersoaneAutorizate = 0;
			delete[] this->specializare;
			this->specializare = NULL;
		}
	}

	int getNrKm_oreZbor() {
		return this->nrKm_oreZbor;
	}

	void setNrKm_oreZbor(int nrKm_oreZbor) {
		if (nrKm_oreZbor > 0)
			this->nrKm_oreZbor = nrKm_oreZbor;
		else
			this->nrKm_oreZbor = 0;
	}

	int getNrRevizii() {
		return this->nrRevizii;
	}

	float getRevizie() {
		for (int i = 0; i < this->nrRevizii; i++)
			return this->revizie[i];
	}

	void setNrRevizii(int nrRevizii, float revizie[50]) {
		if (nrRevizii > 0) {
			this->nrRevizii = nrRevizii;
			for (int i = 0; i < nrRevizii; i++)
				this->revizie[i] = revizie[i];
		}
		else {
			this->nrRevizii = 0;
		}
	}

	bool getDisponibilitate() {
		return this->disponibilitate;
	}

	void setDisponibilitate(bool disponibilitate) {
		this->disponibilitate = disponibilitate;
	}


	AutospecialeMedicale() {
		cout << "\nConstructor fara parametrii";
		this->Interventie = new char[strlen("Necunoscut") + 1];
		strcpy(this->Interventie, "Necunoscut");
	}

	AutospecialeMedicale(char* Interventie, string tipAutospeciala, int nrPersoaneAutorizate, string* specializare, int nrKm_oreZbor, int nrRevizii, float revizie[50], bool disponibilitate) {
		cout << "\nConstructor cu parametri";
		if (strlen(Interventie) > 1) {
			this->Interventie = new char[strlen(Interventie) + 1];
			strcpy(this->Interventie, Interventie);
		}
		else {
			this->Interventie = new char[strlen("Necunoscuta") + 1];
			strcpy(this->Interventie, "Necunoscuta");
		}
		if (tipAutospeciala.length() > 1)
			this->tipAutospeciala = tipAutospeciala;
		else
			this->tipAutospeciala = "Necunoscut";
		if (nrPersoaneAutorizate > 0 && specializare != NULL) {
			this->nrPersoaneAutorizate = nrPersoaneAutorizate;
			this->specializare = new string[nrPersoaneAutorizate];
			for (int i = 0; i < nrPersoaneAutorizate; i++)
				this->specializare[i] = specializare[i];
		}
		else {
			this->nrPersoaneAutorizate = 0;
			this->specializare = NULL;
		}
		if (nrKm_oreZbor > 0)
			this->nrKm_oreZbor = nrKm_oreZbor;
		else
			this->nrKm_oreZbor = 0;
		if (nrRevizii > 0) {
			this->nrRevizii = nrRevizii;
			for (int i = 0; i < nrRevizii; i++)
				this->revizie[i] = revizie[i];
		}
		else {
			this->nrRevizii = 0;
		}
		this->disponibilitate = disponibilitate;
	}

	AutospecialeMedicale(const AutospecialeMedicale& a) {
		cout << "\nConstructor de copiere";
		if (strlen(a.Interventie) > 1) {
			this->Interventie = new char[strlen(a.Interventie) + 1];
			strcpy(this->Interventie, a.Interventie);
		}
		else {
			this->Interventie = new char[strlen("Necunoscuta") + 1];
			strcpy(this->Interventie, "Necunoscuta");
		}
		if (a.tipAutospeciala.length() > 1)
			this->tipAutospeciala = a.tipAutospeciala;
		else
			this->tipAutospeciala = "Necunoscut";
		if (a.nrPersoaneAutorizate > 0 && a.specializare != NULL) {
			this->nrPersoaneAutorizate = a.nrPersoaneAutorizate;
			this->specializare = new string[a.nrPersoaneAutorizate];
			for (int i = 0; i < a.nrPersoaneAutorizate; i++)
				this->specializare[i] = a.specializare[i];
		}
		else {
			this->nrPersoaneAutorizate = 0;
			this->specializare = NULL;
		}
		if (a.nrKm_oreZbor > 0)
			this->nrKm_oreZbor = a.nrKm_oreZbor;
		else
			this->nrKm_oreZbor = 0;
		if (a.nrRevizii > 0) {
			this->nrRevizii = a.nrRevizii;
			for (int i = 0; i < a.nrRevizii; i++)
				this->revizie[i] = a.revizie[i];
		}
		else {
			this->nrRevizii = 0;
		}
		this->disponibilitate = a.disponibilitate;
	}

	AutospecialeMedicale& operator=(const AutospecialeMedicale& a) {
		if (this != NULL) {
			cout << "\nConstructor de copiere";
			delete[] this->Interventie;
			delete[] this->specializare;
			if (strlen(a.Interventie) > 1) {
				this->Interventie = new char[strlen(a.Interventie) + 1];
				strcpy(this->Interventie, a.Interventie);
			}
			else {
				this->Interventie = new char[strlen("Necunoscuta") + 1];
				strcpy(this->Interventie, "Necunoscuta");
			}
			if (a.tipAutospeciala.length() > 1)
				this->tipAutospeciala = a.tipAutospeciala;
			else
				this->tipAutospeciala = "Necunoscut";
			if (a.nrPersoaneAutorizate > 0 && a.specializare != NULL) {
				this->nrPersoaneAutorizate = a.nrPersoaneAutorizate;
				this->specializare = new string[a.nrPersoaneAutorizate];
				for (int i = 0; i < a.nrPersoaneAutorizate; i++)
					this->specializare[i] = a.specializare[i];
			}
			else {
				this->nrPersoaneAutorizate = 0;
				this->specializare = NULL;
			}
			if (a.nrKm_oreZbor > 0)
				this->nrKm_oreZbor = a.nrKm_oreZbor;
			else
				this->nrKm_oreZbor = 0;
			if (a.nrRevizii > 0) {
				this->nrRevizii = a.nrRevizii;
				for (int i = 0; i < a.nrRevizii; i++)
					this->revizie[i] = a.revizie[i];
			}
			else {
				this->nrRevizii = 0;
			}
			this->disponibilitate = a.disponibilitate;
		}
		return *this;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrRevizii)
			return this->revizie[index];
		else
			throw new exception("\nIndex invalid");
	}

	AutospecialeMedicale operator+(float revizienoua) {
		AutospecialeMedicale copie = *this;
		if (revizienoua > 0) {
			copie.nrRevizii++;
			float* temp = new float[copie.nrRevizii];
			for (int i = 0; i < copie.nrRevizii - 1; i++)
				temp[i] = copie.revizie[i];
			temp[copie.nrRevizii - 1] = revizienoua;
			for (int i = 0; i < copie.nrRevizii; i++)
				copie.revizie[i] = temp[i];
			delete[] temp;
		}
		return copie;
	}

	AutospecialeMedicale& operator++() {
		this->nrKm_oreZbor++;
		return *this;
	}

	AutospecialeMedicale operator++(int) {
		AutospecialeMedicale copie = *this;
		this->nrKm_oreZbor++;
		return copie;
	}

	explicit operator int() {
		return this->nrKm_oreZbor;
	}

	bool operator!() {
		if (this->disponibilitate == false)
			return true;
		else
			return false;
	}

	bool operator<(AutospecialeMedicale a) {
		if (this->nrRevizii < a.nrRevizii)
			return true;
		else
			return false;
	}

	bool operator==(AutospecialeMedicale a) {
		if (this->nrRevizii == a.nrRevizii)
			return true;
		else
			return false;
	}

	~AutospecialeMedicale() {
		cout << "\nDestructor";
		delete[] this->Interventie;
		delete[] this->specializare;
	}

	friend ostream& operator<<(ostream& out, const AutospecialeMedicale& a) {
		out << "\n---------------------------------------------------------";
		out << "\nInterventie: " << a.Interventie;
		out << "\nTip autospeciala: " << a.tipAutospeciala;
		out << "\nNr persoane autorizate: " << a.nrPersoaneAutorizate;
		for (int i = 0; i < a.nrPersoaneAutorizate; i++)
			out << "\nSpecializare: " << i + 1 << ": " << a.specializare[i];
		out << "\nDisponibilitate: ";
		if (a.disponibilitate == true)
			out << "Disponibil";
		else
			out << "Indisponibil";
		out << "\nNr km/ore zbor: " << a.nrKm_oreZbor;
		out << "\nNr revizii: " << a.nrRevizii;
		for (int i = 0; i < a.nrRevizii; i++)
			out << "\nRevizie " << i + 1 << ": " << a.revizie[i];
		out << "\n---------------------------------------------------------";
		return out;
	}

	friend istream& operator>>(istream& in, AutospecialeMedicale& a) {
		cout << "\nInterventie: ";
		char buffer[100];
		in >> buffer;
		a.setInterventie(buffer);
		cout << "\nTip autospeciala: ";
		string tip;
		in >> tip;
		a.setTipAutospeciala(tip);
		cout << "\nNr persoane autorizate: ";
		int nrPers;
		in >> nrPers;
		string* specializari = new string[nrPers];
		for (int i = 0; i < nrPers; i++) {
			cout << "\nSpecializare " << i + 1 << ": ";
			in >> specializari[i];
		}
		a.setNrPersoaneAutorizate(nrPers, specializari);
		cout << "\nDisponibilitate: ";
		bool disp;
		in >> disp;
		a.setDisponibilitate(disp);
		cout << "\nNr km/ore zbor: ";
		float nrKm_oreZbr;
		in >> nrKm_oreZbr;
		a.setNrKm_oreZbor(nrKm_oreZbr);
		cout << "\nNr revizii: ";
		int nrRevizii;
		in >> nrRevizii;
		float* revizii = new float[nrRevizii];
		for (int i = 0; i < nrRevizii; i++) {
			cout << "\nRevizie " << i + 1 << ": ";
			in >> revizii[i];
		}
		a.setNrRevizii(nrRevizii, revizii);
		return in;
	}
};

int main() {

	Spital sp1(0);
	cout << sp1;
	char nume[] = "Spitalul de Urgenta Floreasca";
	Spital sp2(2015, nume, 3, new string[3]{ "Medicina Interna", "Chirurgie generala", "A.T.I." }, 4, new int[4] { 3, 2, 5, 1 }, 50);
	cout << sp2;
	sp2.getAnInfiintare();
	sp2.getNume();
	sp2.getNrMedici();
	sp2.getSpecializareMedici();
	sp2.getNrSaloaneDisp();
	sp2.getNrPaturiDisp();
	sp2.getNrPacienti();
	char numeSpital[] = "Spitalul Militar Central";
	sp2.setNume(numeSpital);
	sp2.setNrMedici(4, new string[4]{ "Cardiologie", "Chirurgie generala", "Oncologie", "Medicina Interna" });
	sp2.setNrSaloaneDisp(3, new int[3] { 2, 3, 4 });
	sp2.setNrPacienti(100);
	cout << sp2;

	try {
		cout << "\nSalonul 2 al spitalului sp2 are " << sp2[1] << " paturi disponibile";
	}
	catch (exception* ex) {
		cout << ex->what();
		delete[] ex;
	}

	Spital sp3(sp2);
	cout << sp3;

	Spital sp4(2018);
	sp4 = sp3;
	cout << sp4;

	//cin >> sp4;
	//cout << sp4;

	sp4 = sp4 + "Cardiologie";
	cout << sp4;

	sp4 = ++sp4;
	cout << sp4;

	sp4 = sp4++;
	cout << sp4;

	string specializare = (string)sp4;
	cout << "\nSpecializarea ultimului medic este: " << specializare;

	if (!sp4)
		cout << "\nSpitalul nu are pacienti";
	else
		cout << "\nSpitalul are pacienti";

	if (sp4 < sp3)
		cout << "\nSpitalul 4 are mai putini medici decat spitalul 3";
	else
		cout << "\nSpitalul 4 are mai multi medici decat spitalul 3";

	if (sp4 == sp3)
		cout << "\nSpitalul 4 are acelasi numar de medici ca si spitalul 3";
	else
		cout << "\nSpitalul 4 are un numar diferit de medici decat spitalul 3";

	Laborator lab1;
	cout << lab1;
	char numeLab[100] = "Laboratorul de Analize";
	Laborator lab2(numeLab, 7, 3, new string[3]{ "Analize de sange", "Analize de urina", "Analize de fecale" }, new float[3] { 50, 30, 40 }, new bool[3] { true, false, true });
	cout << lab2;

	lab2.getNume();
	lab2.getNrAsistente();
	lab2.getNrServicii();
	lab2.getServicii();
	lab2.getPreturi();
	lab2.getDisponibilitate();
	char numeLabor[100] = "Laboratorul de Analize";
	lab2.setNume(numeLabor);
	lab2.setNrAsistente(5);
	lab2.setNrServicii(3, new string[3]{ "Analize de fecale", "Analize de sange", "Analize de urina" }, new float[3] { 80, 100, 60 }, new bool[3] { false, true, true });
	cout << lab2;

	Laborator lab3(lab2);
	cout << lab3;

	Laborator lab4;
	lab4 = lab3;
	cout << lab4;

	//cin >> lab4;
	//cout << lab4;

	try {
		string serviciu = lab2[0];
		cout << "\nServiciul 1 al laboratorului 2 este: " << serviciu;
	}
	catch (exception* ex) {
		cout << ex->what();
		delete[] ex;
	}

	lab4 = lab4 + "Perfuzie intravenoasa";
	cout << lab4;

	lab3 = ++lab2;
	cout << lab3;
	lab3 = lab2++;
	cout << lab3;

	int nrAsistente = (int)lab4;
	cout << "\nNumarul de asistente al laboratorului 4 este: " << nrAsistente;

	if (!lab4)
		cout << "\nLaboratorul 4 nu are servicii disponibile";
	else
		cout << "\nLaboratorul 4 are servicii disponibile";

	if (lab4 > lab3)
		cout << "\nLaboratorul 4 are mai multe servicii disponibile decat laboratorul 3";
	else
		cout << "\nLaboratorul 4 are mai putine servicii disponibile decat laboratorul 3";

	if (lab4 == lab3)
		cout << "\nLaboratorul 4 are acelasi numar de servicii disponibile ca si laboratorul 3";
	else
		cout << "\nLaboratorul 4 are un numar diferit de servicii disponibile decat laboratorul 3";

	Policlinica pol1;
	cout << pol1;
	char numePol[100] = "Policlinica de Chirurgie";
	Policlinica pol2("Bucuresti", numePol, 6, 4, new string[4]{ "Cardiologie", "Chirurgie generala", "Oncologie", "Medicina Interna" }, 5, new string[5]{ "Consult cardiologie", "Control chirurgie generala", "Control dermatologie", "Ecografie abdomen superior", "Consult neurologie" }, new float[5] {225, 145, 180, 200, 225});
	cout << pol2;

	pol2.getOras();
	pol2.getNume();
	pol2.getNrCabinete();
	pol2.getNrSpecialitati();
	pol2.getSpecialitati();
	pol2.getNrInvestigatii();
	pol2.getInvestigatii();
	pol2.getPretInvestigatie();
	pol2.setOras("Brasov");
	char numePolic[100] = "Regina Maria";
	pol2.setNume(numePolic);
	pol2.setNrCabinete(8);
	pol2.setNrSpecialitati(5, new string[5]{ "Cardiologie", "Chirurgie generala", "Oncologie", "Medicina Interna", "Chirurgie plastica" });
	pol2.setNrInvestigatii(6, new string[6]{ "Consult cardiologie", "Control chirurgie generala", "Control dermatologie", "Ecografie abdomen superior", "Consult neurologie", "Consult oftalmologie" }, new float[6] { 225, 145, 180, 200, 225, 250 });
	cout << pol2;

	Policlinica pol3(pol2);
	cout << pol3;
	Policlinica pol4;
	pol4 = pol3;
	cout << pol4;

	//cin >> pol4;
	//cout << pol4;

	try {
		float pretInvestigatie = pol2[2];
		cout << "\nPretul investigatiei 3 al policlinicii 2 este: " << pretInvestigatie;
	}
	catch (exception* ex) {
		cout << ex->what();
		delete[] ex;
	}

	pol4 = pol4 + "Oftalmologie";
	cout << pol4;

	pol4 = --pol3;
	cout << pol4;

	pol4 = pol3--;
	cout << pol4;

	int nrSpecialitati = (int)pol4;
	cout << "\nNumarul de specialitati al policlinicii 4 este: " << nrSpecialitati;

	if (!pol4)
		cout << "\nPoliclinica 4 nu are investigatii disponibile";
	else
		cout << "\nPoliclinica 4 are investigatii disponibile";

	if (pol4 <= pol3)
		cout << "\nPoliclinica 4 are mai putine investigatii disponibile decat policlinica 3";
	else
		cout << "\nPoliclinica 4 are mai multe investigatii disponibile decat policlinica 3";

	if (pol4 == pol3)
		cout << "\nPoliclinica 4 se afla in acelasi oras ca si policlinica 3";
	else
		cout << "\nPoliclinica 4 se afla intr-un oras diferit fata de policlinica 3";

	Boala b1(2010);
	cout << b1;
	char numeBoala[100] = "COVID-19";
	Boala b2(2020, numeBoala, 3, new string[3]{ "Febra","Tuse","Dificultati respiratorii" }, 500, 3, new string[3]{ "Ianuarie","Februarie","Martie" }, new int[3] { 100, 200, 200 });
	cout << b2;

	b2.getAnAparitie();
	b2.getNume();
	b2.getNrSimptome();
	b2.getSimptome();
	b2.getNrCazuri();
	b2.getNrLuniImbolnavire();
	b2.getLuniImbolnavire();
	b2.getNrCazuriLuna();
	char numeBl[100] = "Ciuma";
	b2.setNume(numeBl);
	string* simptome = new string[2]{ "Febra","Tuse" };
	b2.setNrSimptome(2, simptome);
	b2.setNrCazuri(300);
	string* luni = new string[2]{ "Ianuarie","Februarie" };
	int* nrCazuriLuna = new int[2] { 100, 200 };
	b2.setNrLuniImbolnavire(2, luni, nrCazuriLuna);
	cout << b2;

	b2.getDecese();
	b2.setDecese(100);
	cout << "\nDecese cauzate de boala b2: " << b2.getDecese();

	Boala b3(b2);
	cout << b3;
	Boala b4(2021);
	b4 = b3;
	cout << b4;

	//cin >> b4;
	//cout << b4;

	try {
		cout << "\nSimptomul 2 al bolii b4 este: " << b4[1];
	}
	catch (exception* ex) {
		cout << ex->what();
		delete[] ex;
	}

	Boala b5 = b2 + "Dificultati respiratorii";
	cout << b5;

	b5 = ++b4;
	cout << b5;
	b5 = b4++;
	cout << b5;

	int nrCazuri = (int)b5;
	cout << "\nNr cazuri boala b5: " << nrCazuri;

	if (!b5)
		cout << "\nNu exista cazuri de boala";
	else
		cout << "\nExista cazuri de boala";

	if (b5 >= b4)
		cout << "\nNr cazuri b5 este mai mare sau egal cu nr cazuri b4";
	else
		cout << "\nNr cazuri b5 este mai mic decat nr cazuri b4";

	if (b5 == b4)
		cout << "\nNr cazuri b5 este egal cu nr cazuri b4";
	else
		cout << "\nNr cazuri b5 este diferit de nr cazuri b4";

	AutospecialeMedicale a1;
	cout << a1;
	char Interventie[100] = "EAA";
	AutospecialeMedicale a2(Interventie, "Avion sanitar", 4, new string[4]{ "Medic","Asistetnt medical","Pilot","Copilot" }, 101, 10, new float[10] { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }, true);
	cout << a2;

	a2.getInterventie();
	a2.getTipAutospeciala();
	a2.getNrPersoaneAutorizate();
	a2.getSpecializare();
	a2.getDisponibilitate();
	a2.getNrKm_oreZbor();
	a2.getNrRevizii();
	a2.getRevizie();
	char Interv[100] = "TIM";
	a2.setInterventie(Interv);
	a2.setTipAutospeciala("Ambulanta tip C1");
	string spec[4] = { "Medic de urgenta","Asistetnt medical","Paramedic","Sofer" };
	a2.setNrPersoaneAutorizate(4, spec);
	a2.setDisponibilitate(false);
	a2.setNrKm_oreZbor(58999);
	float rev[8] = { 7500,15000,22500,30000,37500,45000,52500 };
	a2.setNrRevizii(7, rev);
	cout << a2;

	AutospecialeMedicale a3(a2);
	cout << a3;
	AutospecialeMedicale a4;
	a4 = a3;
	cout << a4;

	//cin >> a4;
	//cout << a4;

	try {
		cout << "\nRevizie 3: " << a4[2];
	}
	catch (exception* ex) {
		cout << ex->what();
		delete[] ex;
	}

	a4 = a4 + 57000;
	cout << a4;

	a4 = ++a3;
	cout << a4;

	a4 = a3++;
	cout << a4;

	int nrKm_oreZbor = (int)a4;
	cout << "\nNr km/ore zbor autospeciala medicala a4: " << nrKm_oreZbor;

	if (!a4)
		cout << "\nAutospeciala medicala a4 nu este disponibila";
	else
		cout << "\nAutospeciala medicala a4 este disponibila";

	if (a4 < a3)
		cout << "\nAutospeciala medicala a4 are mai putine revizii decat autospeciala medicala a3";
	else
		cout << "\nAutospeciala medicala a4 are mai multe revizii decat autospeciala medicala a3";

	if (a4 == a3)
		cout << "\nAutospeciala medicala a4 are acelasi numar de revizii ca autospeciala medicala a3";
	else
		cout << "\nAutospeciala medicala a4 are un numar diferit de revizii decat autospeciala medicala a3";

	return 0;
}