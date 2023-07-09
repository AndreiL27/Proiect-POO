#include <iostream>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;

class IFile {
	virtual void writeToFile(fstream& f) = 0;
	virtual void readFromFile(fstream& f) = 0;
	virtual void writeTxtToFile(fstream& f) = 0;
	virtual void readTxtFromFile(fstream& f) = 0;
};

class Spital :public IFile
{
private:
	const int anInfiintare = 0; 
	char* nume;
	int nrMedici = 0;
	string* specializareMedici = NULL;
	int nrSaloaneDisp = 0;
	int nrPaturiDisp[50];
	int nrPacienti = 0;
public:

	void writeTxtToFile(fstream& f) {
		f << this->nume << endl;
		f << this->nrPacienti << endl;
		f << this->nrMedici << endl;
		for (int i = 0; i < this->nrMedici; i++)
			f << this->specializareMedici[i] << endl;
		f << this->nrSaloaneDisp << endl;
		for (int i = 0; i < this->nrSaloaneDisp; i++)
			f << this->nrPaturiDisp[i] << endl;
	}

	void readTxtFromFile(fstream& f) {
		char buffer[100];
		f >> buffer;
		this->nume = new char[strlen(buffer) + 1];
		strcpy(this->nume, buffer);
		f >> this->nrPacienti;
		f >> this->nrMedici;
		this->specializareMedici = new string[this->nrMedici];
		for (int i = 0; i < this->nrMedici; i++)
			f >> this->specializareMedici[i];
		f >> this->nrSaloaneDisp;
		for (int i = 0; i < this->nrSaloaneDisp; i++)
			f >> this->nrPaturiDisp[i];
	}

	void writeToFile(fstream& f) {
		f.write((char*)&this->anInfiintare, sizeof(int));
		int lg = strlen(this->nume) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume, lg);
		f.write((char*)&this->nrMedici, sizeof(int));
		for (int i = 0; i < this->nrMedici; i++)
		{
			lg = this->specializareMedici[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->specializareMedici[i].data(), lg);
		}
		f.write((char*)&this->nrSaloaneDisp, sizeof(int));
		for (int i = 0; i < this->nrSaloaneDisp; i++)
		{
			f.write((char*)&this->nrPaturiDisp[i], sizeof(int));
		}
		f.write((char*)&this->nrPacienti, sizeof(int));
	}

	void readFromFile(fstream& f) {
		f.read((char*)&this->anInfiintare, sizeof(int));
		int lg;
		f.read((char*)&lg, sizeof(int));
		this->nume = new char[lg];
		f.read(this->nume, lg);
		delete[] this->specializareMedici;
		f.read((char*)&this->nrMedici, sizeof(int));
		this->specializareMedici = new string[this->nrMedici];
		for (int i = 0; i < this->nrMedici; i++)
		{
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->specializareMedici[i] = buffer;
			delete[] buffer;
		}
		f.read((char*)&this->nrSaloaneDisp, sizeof(int));
		for (int i = 0; i < this->nrSaloaneDisp; i++)
		{
			f.read((char*)&this->nrPaturiDisp[i], sizeof(int));
		}
		f.read((char*)&this->nrPacienti, sizeof(int)); {
		}
	}

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
		string* sp;
		sp = new string[this->nrMedici];
		for (int i = 0; i < this->nrMedici; i++)
			sp[i] = this->specializareMedici[i];
		return sp;
	}

	int getNrSaloaneDisp() {
		return this->nrSaloaneDisp;
	}

	int* getNrPaturiDisp() {
		int* nrp;
		nrp = new int[this->nrSaloaneDisp];
		for (int i = 0; i < this->nrSaloaneDisp; i++)
			nrp[i] = this->nrPaturiDisp[i];
		return nrp;
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


class Laborator : public IFile
{
private:
	char* nume;
	int nrAsistente = 0;
	int nrServicii = 0;
	string* servicii = NULL;
	float preturi[50];
	bool* disponibilitate = NULL;

public:

	void writeTxtToFile(fstream& f) {
		f << this->nume << endl;
		f << this->nrAsistente << endl;
		f << this->nrServicii << endl;
		for (int i = 0; i < this->nrServicii; i++) {
			f << this->servicii[i] << endl;
			f << this->preturi[i] << endl;
			f << this->disponibilitate[i] << endl;
		}
	}

	void readTxtFromFile(fstream& f) {
		char buffer[200];
		f >> buffer;
		this->nume = new char[strlen(buffer) + 1];
		strcpy_s(this->nume, strlen(buffer) + 1, buffer);
		f >> this->nrAsistente;
		f >> this->nrServicii;
		this->servicii = new string[this->nrServicii];
		this->disponibilitate = new bool[this->nrServicii];
		for (int i = 0; i < this->nrServicii; i++) {
			f >> buffer;
			this->servicii[i] = buffer;
			f >> this->preturi[i];
			f >> this->disponibilitate[i];
		}
	}

	void writeToFile(fstream& f) {
		int lg = strlen(this->nume) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume, lg);
		f.write((char*)&this->nrAsistente, sizeof(int));
		f.write((char*)&this->nrServicii, sizeof(int));
		for (int i = 0; i < this->nrServicii; i++)
		{
			lg = this->servicii[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->servicii[i].data(), lg);
			f.write((char*)&this->preturi[i], sizeof(float));
			f.write((char*)&this->disponibilitate[i], sizeof(bool));
		}
	}

	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		this->nume = new char[lg];
		f.read(this->nume, lg);
		f.read((char*)&this->nrAsistente, sizeof(int));
		delete[] this->servicii;
		delete[] this->disponibilitate;
		f.read((char*)&this->nrServicii, sizeof(int));
		this->servicii = new string[this->nrServicii];
		this->disponibilitate = new bool[this->nrServicii];
		for (int i = 0; i < this->nrServicii; i++)
		{
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->servicii[i] = buffer;
			delete[] buffer;
			f.read((char*)&this->preturi[i], sizeof(float));
			f.read((char*)&this->disponibilitate[i], sizeof(bool));
		}
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

	float* getPreturi() {
		float* p;
		p = new float[this->nrServicii];
		for (int i = 0; i < this->nrServicii; i++)
			p[i] = this->preturi[i];
		return p;
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

	virtual float pretTotalServiciiDisponibile() {
		float suma = 0;
		for (int i = 0; i < this->nrServicii; i++)
			if (this->disponibilitate[i] == true)
				suma += this->preturi[i];
		return suma;
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


class Policlinica :public IFile
{
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

	void writeTxtToFile(fstream& f) {
		f << this->oras << endl;
		f << this->nume << endl;
		f << this->nrCabinete << endl;
		f << this->nrSpecialitati << endl;
		for (int i = 0; i < this->nrSpecialitati; i++)
			f << this->specialitati[i] << endl;
		f << this->nrInvestigatii << endl;
		for (int i = 0; i < this->nrInvestigatii; i++)
			f << this->investigatii[i] << endl;
		for (int i = 0; i < this->nrInvestigatii; i++)
			f << this->pretInvestigatie[i] << endl;
	}

	void readTxtFromFile(fstream& f) {
		f >> this->oras;
		char nume[200];
		f >> nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		f >> this->nrCabinete;
		f >> this->nrSpecialitati;
		this->specialitati = new string[this->nrSpecialitati];
		for (int i = 0; i < this->nrSpecialitati; i++)
			f >> this->specialitati[i];
		f >> this->nrInvestigatii;
		this->investigatii = new string[this->nrInvestigatii];
		for (int i = 0; i < this->nrInvestigatii; i++)
			f >> this->investigatii[i];
		for (int i = 0; i < this->nrInvestigatii; i++)
			f >> this->pretInvestigatie[i];
	}

	void writeToFile(fstream& f) {
		int lg = this->oras.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->oras.data(), lg);
		lg = strlen(this->nume) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume, lg);
		f.write((char*)&this->nrCabinete, sizeof(int));
		f.write((char*)&this->nrSpecialitati, sizeof(int));
		for (int i = 0; i < this->nrSpecialitati; i++) {
			lg = this->specialitati[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->specialitati[i].data(), lg);
		}
		f.write((char*)&this->nrInvestigatii, sizeof(int));
		for (int i = 0; i < this->nrInvestigatii; i++) {
			lg = this->investigatii[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->investigatii[i].data(), lg);
			f.write((char*)&this->pretInvestigatie[i], sizeof(float));
		}
	}

	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->oras = buffer;
		delete[] buffer;
		f.read((char*)&lg, sizeof(int));
		this->nume = new char[lg];
		f.read(this->nume, lg);
		f.read((char*)&this->nrCabinete, sizeof(int));
		delete[] this->specialitati;
		f.read((char*)&this->nrSpecialitati, sizeof(int));
		this->specialitati = new string[this->nrSpecialitati];
		for (int i = 0; i < this->nrSpecialitati; i++) {
			f.read((char*)&lg, sizeof(int));
			buffer = new char[lg];
			f.read(buffer, lg);
			this->specialitati[i] = buffer;
			delete[] buffer;
		}
		delete[] this->investigatii;
		f.read((char*)&this->nrInvestigatii, sizeof(int));
		this->investigatii = new string[this->nrInvestigatii];
		for (int i = 0; i < this->nrInvestigatii; i++) {
			f.read((char*)&lg, sizeof(int));
			buffer = new char[lg];
			f.read(buffer, lg);
			this->investigatii[i] = buffer;
			delete[] buffer;
			f.read((char*)&this->pretInvestigatie[i], sizeof(float));
		}
	}

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

	float* getPretInvestigatie() {
		float* prt;
		prt = new float[this->nrInvestigatii];
		for (int i = 0; i < this->nrInvestigatii; i++)
			prt[i] = this->pretInvestigatie[i];
		return prt;
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


class Boala :public IFile
{
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

	void writeTxtToFile(fstream& f) {
		f << nume << endl;
		f << nrSimptome << endl;
		for (int i = 0; i < nrSimptome; i++)
			f << simptome[i] << endl;
		f << nrCazuri << endl;
		f << nrLuniImbolnavire << endl;
		for (int i = 0; i < nrLuniImbolnavire; i++)
			f << luniImbolnavire[i] << endl;
		for (int i = 0; i < nrLuniImbolnavire; i++)
			f << nrCazuriLuna[i] << endl;
	}

	void readTxtFromFile(fstream& f) {
		char buffer[100];
		f >> buffer;
		this->nume = new char[strlen(buffer) + 1];
		strcpy_s(this->nume, strlen(buffer) + 1, buffer);
		f >> this->nrSimptome;
		this->simptome = new string[this->nrSimptome];
		for (int i = 0; i < this->nrSimptome; i++) {
			f >> buffer;
			this->simptome[i] = buffer;
		}
		f >> this->nrCazuri;
		f >> this->nrLuniImbolnavire;
		this->luniImbolnavire = new string[this->nrLuniImbolnavire];
		for (int i = 0; i < this->nrLuniImbolnavire; i++) {
			f >> buffer;
			this->luniImbolnavire[i] = buffer;
		}
		for (int i = 0; i < this->nrLuniImbolnavire; i++)
			f >> this->nrCazuriLuna[i];
	}

	void writeToFile(fstream& f) {
		f.write((char*)&this->anAparitie, sizeof(int));
		int lg = strlen(this->nume) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume, lg);
		f.write((char*)&this->nrSimptome, sizeof(int));
		for (int i = 0; i < this->nrSimptome; i++) {
			lg = this->simptome[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->simptome[i].data(), lg);
		}
		f.write((char*)&this->nrCazuri, sizeof(int));
		f.write((char*)&this->nrLuniImbolnavire, sizeof(int));
		for (int i = 0; i < this->nrLuniImbolnavire; i++) {
			lg = this->luniImbolnavire[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->luniImbolnavire[i].data(), lg);
			f.write((char*)&this->nrCazuriLuna[i], sizeof(int));
		}
	}

	void readFromFile(fstream& f) {
		f.read((char*)&this->anAparitie, sizeof(int));
		int lg;
		f.read((char*)&lg, sizeof(int));
		this->nume = new char[lg];
		f.read(this->nume, lg);
		delete[] this->simptome;
		f.read((char*)&this->nrSimptome, sizeof(int));
		this->simptome = new string[this->nrSimptome];
		for (int i = 0; i < this->nrSimptome; i++) {
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->simptome[i] = buffer;
			delete[] buffer;
		}
		f.read((char*)&this->nrCazuri, sizeof(int));
		delete[] this->luniImbolnavire;
		f.read((char*)&this->nrLuniImbolnavire, sizeof(int));
		this->luniImbolnavire = new string[this->nrLuniImbolnavire];
		for (int i = 0; i < this->nrLuniImbolnavire; i++) {
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->luniImbolnavire[i] = buffer;
			delete[] buffer;
			f.read((char*)&this->nrCazuriLuna[i], sizeof(int));
		}
	}

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

	int* getNrCazuriLuna() {
		int* nrcaz;
		nrcaz = new int[this->nrLuniImbolnavire];
		for (int i = 0; i < this->nrLuniImbolnavire; i++)
			nrcaz[i] = this->nrCazuriLuna[i];
		return nrcaz;
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

	virtual float RataMortalitate() {
		return (this->decese * 100) / this->nrCazuri;
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

int Boala::decese = 100;


class Epidemiologie : public Boala {
private:
	string numeTara = "Necunoscuta";
	int nrTulpini = 0;
	string* tulpini = NULL;
	int* nrCazuriTulpina = NULL;

public:

	Epidemiologie(int anAparitie) :Boala(anAparitie) {}

	Epidemiologie(Boala bl, string numeTara, int nrTulpini, string* tulpini, int* nrCazuriTulpina) :Boala(bl) {
		this->numeTara = numeTara;
		this->nrTulpini = nrTulpini;
		this->tulpini = new string[nrTulpini];
		this->nrCazuriTulpina = new int[nrTulpini];
		if (nrTulpini > 0 && tulpini != NULL){
			for (int i = 0; i < nrTulpini; i++) {
				this->tulpini[i] = tulpini[i];
				this->nrCazuriTulpina[i] = nrCazuriTulpina[i];
			}
		}
		else {
			this->tulpini = NULL;
			this->nrCazuriTulpina = NULL;
			this->nrTulpini = 0; 
		}
	}

	Epidemiologie(const Epidemiologie& e) :Boala(e) {
		this->numeTara = e.numeTara;
		this->nrTulpini = e.nrTulpini;
		this->tulpini = new string[e.nrTulpini];
		if (e.nrTulpini > 0 && e.tulpini != NULL){
			for (int i = 0; i < nrTulpini; i++) {
				this->tulpini[i] = e.tulpini[i];
				this->nrCazuriTulpina[i] = e.nrCazuriTulpina[i];
			}
		}
		else {
			this->tulpini = NULL;
			this->nrCazuriTulpina = NULL;
			this->nrTulpini = 0;
		}
	}

	Epidemiologie& operator=(const Epidemiologie& e) {
		Boala::operator=(e);
		this->numeTara = e.numeTara;
		this->nrTulpini = e.nrTulpini;
		if (this->tulpini != NULL)
			delete[] this->tulpini;
		this->tulpini = new string[e.nrTulpini];
		if (e.nrTulpini > 0 && e.tulpini != NULL) {
			for (int i = 0; i < nrTulpini; i++) {
				this->tulpini[i] = e.tulpini[i];
				this->nrCazuriTulpina[i] = e.nrCazuriTulpina[i];
			}
		}
		else {
			this->tulpini = NULL;
			this->nrCazuriTulpina = NULL;
			this->nrTulpini = 0;
		}
		return *this;
	}

	~Epidemiologie() {
		delete[] this->tulpini;
	}

	friend ostream& operator<<(ostream& out, Epidemiologie& e) {
		out << (Boala&)e;
		out << "\nNume tara origine: " << e.numeTara;
		out << "\nNr tulpini: " << e.nrTulpini;
		for (int i = 0; i < e.nrTulpini; i++) {
			out << "\nTulpina " << i + 1 << ": " << e.tulpini[i];
			out << "\nNr cazuri: " << e.nrCazuriTulpina[i];
		}
		out << "\n-----------------------------------------";
		return out;
	}
};


class AutospecialeMedicale :public IFile
{
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

	void writeTxtToFile(fstream& f) {
		f << Interventie << endl;
		f << tipAutospeciala << endl;
		f << nrPersoaneAutorizate << endl;
		for (int i = 0; i < nrPersoaneAutorizate; i++)
			f << specializare[i] << endl;
		f << disponibilitate << endl;
		f << nrKm_oreZbor << endl;
		f << nrRevizii << endl;
		for (int i = 0; i < nrRevizii; i++)
			f << revizie[i] << endl;
	}

	void readTxtFromFile(fstream& f) {
		char buffer[100];
		f >> buffer;
		this->Interventie = new char[strlen(buffer) + 1];
		strcpy_s(this->Interventie, strlen(buffer) + 1, buffer);
		f >> this->tipAutospeciala;
		f >> this->nrPersoaneAutorizate;
		this->specializare = new string[this->nrPersoaneAutorizate];
		for (int i = 0; i < this->nrPersoaneAutorizate; i++)
			f >> this->specializare[i];
		f >> this->disponibilitate;
		f >> this->nrKm_oreZbor;
		f >> this->nrRevizii;
		for (int i = 0; i < this->nrRevizii; i++)
			f >> this->revizie[i];
	}

	void writeToFile(fstream& f) {
		int lg = strlen(this->Interventie) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->Interventie, lg);
		lg = this->tipAutospeciala.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->tipAutospeciala.data(), lg);
		f.write((char*)&this->nrPersoaneAutorizate, sizeof(int));
		for (int i = 0; i < this->nrPersoaneAutorizate; i++) {
			lg = this->specializare[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->specializare[i].data(), lg);
		}
		f.write((char*)&this->nrKm_oreZbor, sizeof(int));
		f.write((char*)&this->nrRevizii, sizeof(int));
		for (int i = 0; i < this->nrRevizii; i++) {
			f.write((char*)&this->revizie[i], sizeof(float));
		}
		f.write((char*)&this->disponibilitate, sizeof(bool));
	}

	void readFromFile(fstream& f) {
		int lg;
		f.read((char*)&lg, sizeof(int));
		this->Interventie = new char[lg];
		f.read(this->Interventie, lg);
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->tipAutospeciala = buffer;
		delete[] buffer;
		delete[] this->specializare;
		f.read((char*)&this->nrPersoaneAutorizate, sizeof(int));
		this->specializare = new string[this->nrPersoaneAutorizate];
		for (int i = 0; i < this->nrPersoaneAutorizate; i++) {
			f.read((char*)&lg, sizeof(int));
			char* buffer = new char[lg];
			f.read(buffer, lg);
			this->specializare[i] = buffer;
			delete[] buffer;
		}
		f.read((char*)&this->nrKm_oreZbor, sizeof(int));
		f.read((char*)&this->nrRevizii, sizeof(int));
		for (int i = 0; i < this->nrRevizii; i++) {
			f.read((char*)&this->revizie[i], sizeof(float));
		}
		f.read((char*)&this->disponibilitate, sizeof(bool));
	}

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

	float* getRevizie() {
		float* rev;
		rev = new float[this->nrRevizii];
		for (int i = 0; i < this->nrRevizii; i++)
			rev[i] = this->revizie[i];
		return rev;
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

template <class TIP>
class Gestiune {
private:
	TIP* autospeciale = NULL;
	int nrAutospeciale = 0;
public:

	Gestiune() {}

	Gestiune(TIP* autospeciale, int nrAutospeciale) {
		this->nrAutospeciale = nrAutospeciale;
			this->autospeciale = new TIP[nrAutospeciale];
			for (int i = 0; i < nrAutospeciale; i++)
				this->autospeciale[i] = autospeciale[i];
	}

	Gestiune(const Gestiune& g) {
		this->nrAutospeciale = g.nrAutospeciale;
			this->autospeciale = new TIP[g.nrAutospeciale];
			for (int i = 0; i < g.nrAutospeciale; i++)
				this->autospeciale[i] = g.autospeciale[i];
	}

	Gestiune& operator=(const Gestiune& g) {
		if (this != &g) {
				delete[] this->autospeciale;
				this->autospeciale = new TIP[g.nrAutospeciale];
				for (int i = 0; i < g.nrAutospeciale; i++)
					this->autospeciale[i] = g.autospeciale[i];
		}
		return *this;
	}

	~Gestiune() {
		delete[] this->autospeciale;
	}

	friend ostream& operator<<(ostream& out, const Gestiune& g) {
		out << "\nNr autospeciale: " << g.nrAutospeciale;
		for (int i = 0; i < g.nrAutospeciale; i++)
			out << "\nAutospeciala " << i + 1 << ": " << g.autospeciale[i];
		return out;
	}
};


int main() {

	Spital sp1(0);
	cout << sp1;
	char nume[] = "Spitalul de Urgenta Floreasca";
	Spital sp2(2015, nume, 3, new string[3]{ "Medicina Interna", "Chirurgie generala", "A.T.I." }, 4, new int[4] { 3, 2, 5, 1 }, 50);
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

	fstream fOutTxt("spital(ft).txt", ios::out);
	sp2.writeTxtToFile(fOutTxt);
	fOutTxt.close();

	fstream fInTxt("spital(ft).txt", ios::in);
	Spital sp5(2008);
	sp5.readTxtFromFile(fInTxt);
	fInTxt.close();
	cout << sp5;

	fstream fOut("spital(fb).txt", ios::out | ios::binary);
	sp2.writeToFile(fOut);
	fOut.close();

	fstream fIn("spital(fb).txt", ios::in | ios::binary);
	Spital sp6(2007);
	sp6.readFromFile(fIn);
	fIn.close();
	cout << sp6;


	Laborator lab1;
	cout << lab1;
	char numeLab[100] = "Laboratorul de Analize";
	Laborator lab2(numeLab, 7, 3, new string[3]{ "Analize de sange", "Analize de urina", "Analize de fecale" }, new float[3] { 50, 30, 40 }, new bool[3] { true, false, true });
	cout << lab2;

	Laborator lab3(lab2);
	cout << lab3;

	Laborator lab4;
	lab4 = lab3;
	cout << lab4;

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

	fstream fOutTxt2("laborator(ft).txt", ios::out);
	lab2.writeTxtToFile(fOutTxt2);
	fOutTxt2.close();

	fstream fInTxt2("laborator(ft).txt", ios::in);
	Laborator lab5;
	lab5.readTxtFromFile(fInTxt2);
	fInTxt2.close();
	cout << lab5;

	fstream fOut2("laborator(fb).txt", ios::out | ios::binary);
	lab2.writeToFile(fOut2);
	fOut2.close();

	fstream fIn2("laborator(fb).txt", ios::in | ios::binary);
	Laborator lab6;
	lab6.readFromFile(fIn2);
	fIn2.close();
	cout << lab6;

	cout << "\nPretul total al serviciilor disponibile este: " << lab2.pretTotalServiciiDisponibile();

	Policlinica pol1;
	cout << pol1;
	char numePol[100] = "Policlinica de Chirurgie";
	Policlinica pol2("Bucuresti", numePol, 6, 4, new string[4]{ "Cardiologie", "Chirurgie generala", "Oncologie", "Medicina Interna" }, 5, new string[5]{ "Consult cardiologie", "Control chirurgie generala", "Control dermatologie", "Ecografie abdomen superior", "Consult neurologie" }, new float[5] {225, 145, 180, 200, 225});
	cout << pol2;

	Policlinica pol3(pol2);
	cout << pol3;
	Policlinica pol4;
	pol4 = pol3;
	cout << pol4;

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

	fstream fOutTxt3("policlinica(ft).txt", ios::out);
	pol2.writeTxtToFile(fOutTxt3);
	fOutTxt3.close();

	fstream fInTxt3("policlinica(ft).txt", ios::in);
	Policlinica pol5;
	pol5.readTxtFromFile(fInTxt3);
	fInTxt3.close();
	cout << pol5;

	fstream fOut3("policlinica(fb).txt", ios::out | ios::binary);
	pol2.writeToFile(fOut3);
	fOut3.close();

	fstream fIn3("policlinica(fb).txt", ios::in | ios::binary);
	Policlinica pol6;
	pol6.readFromFile(fIn3);
	fIn3.close();
	cout << pol6;


	Boala b1(2010);
	cout << b1;
	char numeBoala[100] = "COVID-19";
	Boala b2(2020, numeBoala, 3, new string[3]{ "Febra","Tuse","Dificultati respiratorii" }, 500, 3, new string[3]{ "Ianuarie","Februarie","Martie" }, new int[3] { 100, 200, 200 });
	cout << b2;

	b2.getDecese();
	b2.setDecese(100);
	cout << "\nDecese cauzate de boala b2: " << b2.getDecese();

	Boala b3(b2);
	cout << b3;
	Boala b4(2021);
	b4 = b3;
	cout << b4;

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

	fstream fOutTxt4("boala(ft).txt", ios::out);
	b2.writeTxtToFile(fOutTxt4);
	fOutTxt4.close();

	fstream fInTxt4("boala(ft).txt", ios::in);
	Boala b6(2022);
	b6.readTxtFromFile(fInTxt4);
	fInTxt4.close();
	cout << b6;

	fstream fOut4("boala(fb).txt", ios::out | ios::binary);
	b2.writeToFile(fOut4);
	fOut4.close();

	fstream fIn4("boala(fb).txt", ios::in | ios::binary);
	Boala b7(2019);
	b7.readFromFile(fIn4);
	fIn4.close();
	cout << b7;

	cout << "\nRata de mortalitate a bolii b2 este aproximativ: " << b2.RataMortalitate() << "%";

	Epidemiologie e1(2010);
	cout << e1;

	cout << b2;
	Epidemiologie e2(b2, "China", 3, new string[3]{ "Orientalis", "Antiqua", "Mediaevalis" }, new int[3] { 100, 200, 100 });
	cout << e2;
	
	AutospecialeMedicale a1;
	cout << a1;
	char Interventie[100] = "EAA";
	AutospecialeMedicale a2(Interventie, "Avion sanitar", 4, new string[4]{ "Medic","Asistetnt medical","Pilot","Copilot" }, 101, 10, new float[10] { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }, true);
	cout << a2;

	AutospecialeMedicale a3(a2);
	cout << a3;
	AutospecialeMedicale a4;
	a4 = a3;
	cout << a4;

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

	fstream fOutTxt5("autospeciala(ft).txt", ios::out);
	a2.writeTxtToFile(fOutTxt5);
	fOutTxt5.close();

	fstream fInTxt5("autospeciala(ft).txt", ios::in);
	AutospecialeMedicale a5;
	a5.readTxtFromFile(fInTxt5);
	fInTxt5.close();
	cout << a5;

	fstream fOut5("autospeciala(fb).txt", ios::out | ios::binary);
	a2.writeToFile(fOut5);
	fOut5.close();

	fstream fIn5("autospeciala(fb).txt", ios::in | ios::binary);
	AutospecialeMedicale a6;
	a6.readFromFile(fIn5);
	fIn5.close();
	cout << a6;

	string NumeFisier;
	cout << "\nIntroduceti numele fisierului CSV: ";
	cin >> NumeFisier;
	ifstream fisier(NumeFisier);
	string linietxt = "";
	while (getline(fisier, linietxt)) {
		stringstream LiniiTxt(linietxt);
		string cuvinte;
		while (getline(LiniiTxt, cuvinte, ',')) {
			cout << cuvinte << " ";
		}
		cout << endl;
	}
	
	string autospeciale[] = { "Avion sanitar", "Ambulanta tip C1", "TIM"};
	int nrautospeciale = 3;
	Gestiune <string> g(autospeciale, nrautospeciale);
	cout << g;

	AutospecialeMedicale a7(Interventie, "Avion sanitar", 4, new string[4]{ "Medic","Asistetnt medical","Pilot","Copilot" }, 101, 10, new float[10] { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }, true);
	AutospecialeMedicale vAm[] = { a2,a7 };

	Gestiune <AutospecialeMedicale> g2(vAm, 2);
	cout << g2;

	cout << "\n****************Meniu****************\n";
	cout << "\n->1. Spital";
	cout << "\n->2. Laborator";
	cout << "\n->3. Policlinica";
	cout << "\n->4. Boala";
	cout << "\n->5. Autospeciale medicale";
	cout << "\n->6. Meniu";
	cout << "\n->7. Exit\n";
	cout << "\nAlegeti varianta de la 1 la 6: ";
	int opt;
	int fin = 0;
	cin >> opt;
	while (opt > 0 && opt < 7 && fin == 0) {
		if (opt == 1) {
			cout << "\n****************Spital****************";
			cout << "\n->1. Adauga spital nou";
			cout << "\n->2. Afisare spital";
			cout << "\n->3. Afisari si modificari atribute spital";
			cout << "\n->4. Meniu principal";
			cout << "\n->5. Iesire ";
			cout << "\nAlegeti varianta de la 1 la 5: ";
			cin >> opt;

			if (opt == 1) {
				cout << "\n****************Adauga spital nou****************";
				cout << "\nOptiuni: ";
				cout << "\n->1. Adaugare spital de la tastatura";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					Spital s1(2000);
					cin >> s1;
					cout << "Spital adaugat!";
					fstream fOutTxt("Spital(ft).txt", ios::out);
					s1.writeTxtToFile(fOutTxt);
					fOutTxt.close();

					opt = 1;
				}
				else if (opt == 2)
						opt = 1;
				else if (opt == 3)
						opt = 6;
				else{
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 2) {
				cout << "\n****************Afisare****************";
				cout << "\n->1. Afisare spital";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					fstream fInTxt("Spital(ft).txt", ios::in);
					Spital s1(2008);
					s1.readTxtFromFile(fInTxt);
					fInTxt.close();
					cout << s1;

					opt = 1;
				}
				else if (opt == 2)
					opt = 1;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 3) {
				cout << "\n->1. Afisari";
				cout << "\n->2. Modificari";
				cout << "\nSelectati varianta de la 1 la 2 : ";
				cin >> opt;
				if (opt == 1) {
					cout << "\n->1. Afisati numele spitalului";
					cout << "\n->2. Afisati an infiintare";
					cout << "\n->3. Afisati numarul de medici";
					cout << "\n->4. Afisati specializarea medicilor";
					cout << "\n->5. Afisati numarul de saloane disponibile";
					cout << "\n->6. Afisati numarul de paturi disponibile pentru fiecare salon";
					cout << "\n->7. Afisati numarul de pacienti";
					cout << "\nAlegeti varianta de la 1 la 7 : ";
					cin >> opt;
					if (opt == 1) {
						cout << "Numele spitalului este: " << sp2.getNume();
						opt = 1;
					}
					else if (opt == 2) {
						cout << "Anul infiintarii spitalului este:" << sp2.getAnInfiintare();
						opt = 1;
					}
					else if (opt == 3) {
						cout << "Numarul de medici este: " << sp2.getNrMedici();
						opt = 1;
					}
					else if (opt == 4) {
						string* spec = sp2.getSpecializareMedici();
						for (int i = 0; i < sp2.getNrMedici(); i++)
							cout << "\nSpecializare medic " << i + 1 << ": " << spec[i];
						opt = 1;
					}
					else if (opt == 5) {
						cout << "\nNumar saloane disponibile: " << sp2.getNrSaloaneDisp();
						opt = 1;
					}
					else if (opt == 6) {
						int* nrpd = sp2.getNrPaturiDisp();
						for (int i = 0; i < sp2.getNrSaloaneDisp(); i++) {
							cout << "\nNumar paturi disponibile salon " << i + 1 << ": " << sp2.getNrPaturiDisp()[i];
						}
						opt = 1;
					}
					else if (opt == 7) {
						cout << "\nNumar pacienti: " << sp2.getNrPacienti();
					}
					else {
						cout << "\nOptiune invalida!";
						opt = 6;
					}
				}
				else if (opt == 2) {
					cout << "\n->1. Modificati numele spitalului";
					cout << "\n->2. Modificati numarul de medici si specializarea lor";
					cout << "\n->3. Modificati numarul de saloane si paturi disponibile";
					cout << "\n->4. Modificati numarul de pacienti";
					cout << "\nAlegeti varianta de la 1 la 4 : ";
					cin >> opt;
					if (opt == 1) {
						char numespital[100];
						cout << "\nIntroduceti nume spital:";
						cin >> numespital;
						sp2.setNume(numespital);
						opt = 1;
					}
					else if (opt == 2) {
						int nrmed;
						string specmed[50];
						cout << "\nIntroduceti numarul de medici: "; cin >> nrmed;
						for (int i = 0; i < nrmed; i++) {
							cout << "\nIntroduceti specializare medic " << i + 1 << ": ";
							cin >> specmed[i];
						}
						sp2.setNrMedici(nrmed, specmed);
						opt = 1;
					}
					else if (opt == 3) {
						int nrsal;
						int nrpdisp[50];
						cout << "\nIntroduceti numarul de saloane disponibile: "; cin >> nrsal;
						for (int i = 0; i < nrsal; i++) {
							cout << "\nIntroduceti numarul de paturi disponibile din salonul " << i + 1 << ": ";
							cin >> nrpdisp[i];
						}
						sp2.setNrSaloaneDisp(nrsal, nrpdisp);
						opt = 1;
					}
					else if (opt == 4) {
						int nrpac;
						cout << "\nIntroduceti numarul de pacienti: ";
						cin >> nrpac;
						sp2.setNrPacienti(nrpac);
						opt = 1;
					}
					else {
						cout << "\nOptiune invalda";
						opt = 6;
					}
				}
				else {
					cout << "\nOptiune invalda";
					opt = 6;
				}
			}
			else if (opt == 4) {
				cout << "\n****************Meniu****************\n";
				cout << "\n->1. Spital";
				cout << "\n->2. Laborator";
				cout << "\n->3. Policlinica";
				cout << "\n->4. Boala";
				cout << "\n->5. Autospeciale medicale";
				cout << "\n->6. Meniu";
				cout << "\n->7. Exit\n";
				cout << "\nAlegeti varianta de la 1 la 6: ";
				cin >> opt;
			}
			else if (opt == 5) {
				cout << "\nExit";
				fin = 1;
            }
			
		}
		else if (opt == 2) {
			cout << "\n****************Laborator****************";
			cout << "\n->1. Adauga laborator nou";
			cout << "\n->2. Afisare laborator";
			cout << "\n->3. Afisari si modificari atribute laborator";
			cout << "\n->4. Meniu principal";
			cout << "\n->5. Iesire ";
			cout << "\nAlegeti varianta de la 1 la 5: ";
			cin >> opt;

			if (opt == 1) {
				cout << "\n****************Adauga laborator nou****************";
				cout << "\nOptiuni: ";
				cout << "\n->1. Adaugare laborator de la tastatura";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					Laborator l1;
					cin >> l1;
					cout << "Laborator adaugat!";
					fstream fOutTxt("Laborator(ft).txt", ios::out);
					l1.writeTxtToFile(fOutTxt);
					fOutTxt.close();

					opt = 2;
				}
				else if (opt == 2)
					opt = 2;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 2) {
				cout << "\n****************Afisare****************";
				cout << "\n->1. Afisare laborator";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					fstream fInTxt("Laborator(ft).txt", ios::in);
					Laborator l1;
					l1.readTxtFromFile(fInTxt);
					fInTxt.close();
					cout << l1;

					opt = 2;
				}
				else if (opt == 2)
					opt = 2;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 3) {
				cout << "\n->1. Afisari";
				cout << "\n->2. Modificari";
				cout << "\nSelectati varianta de la 1 la 2 : ";
				cin >> opt;
				if (opt == 1) {
					cout << "\n->1. Afisati numele laboratorului";
					cout << "\n->2. Afisati numarul de asistente";
					cout << "\n->3. Afisati numarul de servicii";
					cout << "\n->4. Afisati serviciile";
					cout << "\n->5. Afisati preturile serviciilor";
					cout << "\n->6. Afisati disponibilitatea serviciilor";
					cout << "\nAlegeti varianta de la 1 la 6 : ";
					cin >> opt;
					if (opt == 1) {
						cout << "Numele laboratorului este: " << lab2.getNume();
						opt = 2;
					}
					else if (opt == 2) {
						cout << "Numarul de asistente este:" << lab2.getNrAsistente();
						opt = 2;
					}
					else if (opt == 3) {
						cout << "Numarul de servicii este: " << lab2.getNrServicii();
						opt = 2;
					}
					else if (opt == 4) {
						string* serv = lab2.getServicii();
						for (int i = 0; i < lab2.getNrServicii(); i++)
							cout << "\nServiciul " << i + 1 << ": " << serv[i];
						opt = 2;
					}
					else if (opt == 5) {
						float* prt = lab2.getPreturi();
						for (int i = 0; i < lab2.getNrServicii(); i++)
							cout << "\nPretul serviciului " << i + 1 << ": " << prt[i];
						opt = 2;
					}
					else if (opt == 6) {
						bool* disp = lab2.getDisponibilitate();
						for (int i = 0; i < lab2.getNrServicii(); i++)
							cout << "\nDisponibilitatea serviciului " << i + 1 << ": " << disp[i];
						opt = 2;
					}
					else {
						cout << "\nOptiune invalida!";
						opt = 6;
					}
				}
				else if (opt == 2) {
					cout << "\n->1. Modificati numele laboratorului";
					cout << "\n->2. Modificati numarul de asistente";
					cout << "\n->3. Modificati serviciile";
					cout << "\nAlegeti varianta de la 1 la 3 : ";
					cin >> opt;
					if (opt == 1) {
						char numelab[100];
						cout << "\nIntroduceti nume laborator:";
						cin >> numelab;
						lab2.setNume(numelab);
						opt = 2;
					}
					else if (opt == 2) {
						int nras;
						cout << "\nIntroduceti numarul de asistente: "; cin >> nras;
						lab2.setNrAsistente(nras);
						opt = 2;
					}
					else if (opt == 3) {
						int nrserv;
						string numserv[100];
						float pserv[50];
						bool dispserv[30];
						cout << "\nIntroduceti numarul de servicii: "; cin >> nrserv;
						for (int i = 0; i < nrserv; i++) {
							cout << "\nServiciu " << i + 1 << ": "; cin >> numserv[i];
							cout << "\nPret serviciu " << i + 1 << ": "; cin >> pserv[i];
							cout << "\Disponibilitate serviciu " << i + 1 << ": "; cin >> dispserv[i];
						}
						lab2.setNrServicii(nrserv, numserv, pserv, dispserv);
						opt = 2;
					}
					else {
						cout << "\nOptiune invalda";
						opt = 6;
					}
				}
				else {
					cout << "\nOptiune invalda";
					opt = 6;
				}
			}
			else if (opt == 4) {
				cout << "\n****************Meniu****************\n";
				cout << "\n->1. Spital";
				cout << "\n->2. Laborator";
				cout << "\n->3. Policlinica";
				cout << "\n->4. Boala";
				cout << "\n->5. Autospeciale medicale";
				cout << "\n->6. Meniu";
				cout << "\n->7. Exit\n";
				cout << "\nAlegeti varianta de la 1 la 6: ";
				cin >> opt;
			}
			else if (opt == 5) {
				cout << "\nExit";
				fin = 1;
			}

		}
		else if (opt == 3) {
			cout << "\n****************Policlinica****************";
			cout << "\n->1. Adauga policlinica noua";
			cout << "\n->2. Afisare policlinica";
			cout << "\n->3. Afisari si modificari atribute policlinica";
			cout << "\n->4. Meniu principal";
			cout << "\n->5. Iesire ";
			cout << "\nAlegeti varianta de la 1 la 5: ";
			cin >> opt;

			if (opt == 1) {
				cout << "\n****************Adauga policlinica noua****************";
				cout << "\nOptiuni: ";
				cout << "\n->1. Adaugare policlinica de la tastatura";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					Policlinica p1;
					cin >> p1;
					cout << "Policlinica adaugata!";
					fstream fOutTxt("Policlinica(ft).txt", ios::out);
					p1.writeTxtToFile(fOutTxt);
					fOutTxt.close();

					opt = 3;
				}
				else if (opt == 2)
					opt = 3;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 2) {
				cout << "\n****************Afisare****************";
				cout << "\n->1. Afisare policlinica";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					fstream fInTxt("Policlinica(ft).txt", ios::in);
					Laborator p1;
					p1.readTxtFromFile(fInTxt);
					fInTxt.close();
					cout << p1;

					opt = 3;
				}
				else if (opt == 2)
					opt = 3;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 3) {
				cout << "\n->1. Afisari";
				cout << "\n->2. Modificari";
				cout << "\nSelectati varianta de la 1 la 2 : ";
				cin >> opt;
				if (opt == 1) {
					cout << "\n->1. Afisati numele policlinicii";
					cout << "\n->2. Afisati numele orasului";
					cout << "\n->3. Afisati numarul de cabinete";
					cout << "\n->4. Afisati numarul de specialitati";
					cout << "\n->5. Afisati specialitati";
					cout << "\n->6. Afisati numarul de investigatii";
					cout << "\n->7. Afisati investigatii";
					cout << "\n->8. Afisati pretul investigatiilor";
					cout << "\nAlegeti varianta de la 1 la 8 : ";
					cin >> opt;
					if (opt == 1) {
						cout << "Numele policlinicii este: " << pol2.getNume();
						opt = 3;
					}
					else if (opt == 2) {
						cout << "Nume oras:" << pol2.getOras();
						opt = 3;
					}
					else if (opt == 3) {
						cout << "Numarul de cabinete este: " << pol2.getNrCabinete();
						opt = 3;
					}
					else if (opt == 4) {
						cout << "Numarul de specialitati este: " << pol2.getNrSpecialitati();
						opt = 3;
					}
					else if (opt == 5) {
						string* spec = pol2.getSpecialitati();
						for (int i = 0; i < pol2.getNrSpecialitati(); i++)
							cout << "\nSpecialitatea " << i + 1 << ": " << spec[i];
						opt = 3;
					}
					else if (opt == 6) {
						cout << "Numarul de investigatii este: " << pol2.getNrInvestigatii();
						opt = 3;
					}
					else if (opt == 7) {
						string* invest = pol2.getInvestigatii();
						for (int i = 0; i < pol2.getNrInvestigatii(); i++)
							cout << "\nInvestigatia " << i + 1 << ": " << invest[i];
						opt = 3;
					}
					else if (opt == 8) {
						float* pinvest = pol2.getPretInvestigatie();
						for (int i = 0; i < pol2.getNrInvestigatii(); i++)
							cout << "\nPret investigatie " << i + 1 << ": " << pinvest[i];
						opt = 3;
					}
					else {
						cout << "\nOptiune invalida!";
						opt = 6;
					}
				}
				else if (opt == 2) {
					cout << "\n->1. Modificati numele policlinicii";
					cout << "\n->2. Modificati numele orasului";
					cout << "\n->3. Modificati numarul cabinetelor";
					cout << "\n->4. Modificati specialitatile";
					cout << "\n->5. Modificati investigatiile";
					cout << "\nAlegeti varianta de la 1 la 5 : ";
					cin >> opt;
					if (opt == 1) {
						char numepol[100];
						cout << "\nIntroduceti nume policlinicii:";
						cin >> numepol;
						pol2.setNume(numepol);
						opt = 3;
					}
					else if (opt == 2) {
						string numoras;
						cout << "\nIntroduceti numele orasului: "; cin >> numoras;
						pol2.setOras(numoras);
						opt = 3;
					}
					else if (opt == 3) {
						int nrcab;
						cout << "\nIntroduceti numarul cabinetelor: "; cin >> nrcab;
						pol2.setNrCabinete(nrcab);
						opt = 3;
					}
					else if (opt == 4) {
						int nrspec;
						string numespec[100];
						cout << "\nIntroduceti numarul de specialitati: "; cin >> nrspec;
						for (int i = 0; i < nrspec; i++) {
							cout << "\Specialitatea " << i + 1 << ": "; cin >> numespec[i];
						}
						pol2.setNrSpecialitati(nrspec, numespec);
						opt = 3;
					}
					else if (opt == 5) {
						int nrinvest;
						string invest[100];
						float pinvest[100];
						cout << "\nIntroduceti numarul de investigatii: "; cin >> nrinvest;
						for (int i = 0; i < nrinvest; i++) {
							cout << "\Investigatia " << i + 1 << ": "; cin >> invest[i];
							cout << "\Pretul investigatiei " << i + 1 << ": "; cin >> pinvest[i];
						}
						pol2.setNrInvestigatii(nrinvest, invest, pinvest);
						opt = 3;
					}
					else {
						cout << "\nOptiune invalda";
						opt = 6;
					}
				}
				else {
					cout << "\nOptiune invalda";
					opt = 6;
				}
			}
			else if (opt == 4) {
				cout << "\n****************Meniu****************\n";
				cout << "\n->1. Spital";
				cout << "\n->2. Laborator";
				cout << "\n->3. Policlinica";
				cout << "\n->4. Boala";
				cout << "\n->5. Autospeciale medicale";
				cout << "\n->6. Meniu";
				cout << "\n->7. Exit\n";
				cout << "\nAlegeti varianta de la 1 la 6: ";
				cin >> opt;
			}
			else if (opt == 5) {
				cout << "\nExit";
				fin = 1;
			}

		}
		else if (opt == 4) {
			cout << "\n****************Boala****************";
			cout << "\n->1. Adauga boala noua";
			cout << "\n->2. Afisare boala";
			cout << "\n->3. Afisari si modificari atribute boala";
			cout << "\n->4. Meniu principal";
			cout << "\n->5. Iesire ";
			cout << "\nAlegeti varianta de la 1 la 5: ";
			cin >> opt;

			if (opt == 1) {
				cout << "\n****************Adauga boala noua****************";
				cout << "\nOptiuni: ";
				cout << "\n->1. Adaugare boala de la tastatura";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					Boala bl1(2021);
					cin >> bl1;
					cout << "Boala adaugata!";
					fstream fOutTxt("Boala(ft).txt", ios::out);
					bl1.writeTxtToFile(fOutTxt);
					fOutTxt.close();

					opt = 4;
				}
				else if (opt == 2)
					opt = 4;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 2) {
				cout << "\n****************Afisare****************";
				cout << "\n->1. Afisare boala";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					fstream fInTxt("Boala(ft).txt", ios::in);
					Boala bl1(2021);
					bl1.readTxtFromFile(fInTxt);
					fInTxt.close();
					cout << bl1;

					opt = 4;
				}
				else if (opt == 2)
					opt = 4;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 3) {
				cout << "\n->1. Afisari";
				cout << "\n->2. Modificari";
				cout << "\nSelectati varianta de la 1 la 2 : ";
				cin >> opt;
				if (opt == 1) {
					cout << "\n->1. Afisati anul aparitiri";
					cout << "\n->2. Afisati numele";
					cout << "\n->3. Afisati numarul de simptome";
					cout << "\n->4. Afisati simptomele";
					cout << "\n->5. Afisati numarul de cazuri";
					cout << "\n->6. Afisati numarul de luni de imbolnavire";
					cout << "\n->7. Afisati lunile";
					cout << "\n->8. Afisati numarul de cazuri pe luna";
					cout << "\nAlegeti varianta de la 1 la 8: ";
					cin >> opt;
					if (opt == 1) {
						cout << "Anul aparitiei este: " << b2.getAnAparitie();
						opt = 4;
					}
					else if (opt == 2) {
						cout << "Nume boala:" << b2.getNume();
						opt = 4;
					}
					else if (opt == 3) {
						cout << "Numarul de simptome este: " << b2.getNrSimptome();
						opt = 4;
					}
					else if (opt == 4) {
						string* simp = b2.getSimptome();
						for (int i = 0; i < b2.getNrSimptome(); i++)
							cout << "\nSimptomul " << i + 1 << ": " << simp[i];
						opt = 4;
					}
					else if (opt == 5) {
						cout << "Numarul de cazuri este: " << b2.getNrCazuri();
						opt = 4;
					}
					else if (opt == 6) {
						cout << "Numarul de luni de imbolnavire este: " << b2.getNrLuniImbolnavire();
						opt = 4;
					}
					else if (opt == 7) {
						string* luni = b2.getLuniImbolnavire();
						for (int i = 0; i < b2.getNrLuniImbolnavire(); i++)
							cout << "\nLuna " << i + 1 << ": " << luni[i];
						opt = 4;
					}
					else if (opt == 8) {
						int* nrcz = b2.getNrCazuriLuna();
						for (int i = 0; i < b2.getNrLuniImbolnavire(); i++)
							cout << "\nNr cazuri luna " << i + 1 << ": " << nrcz[i];
						opt = 4;
					}
					else {
						cout << "\nOptiune invalida!";
						opt = 6;
					}
				}
				else if (opt == 2) {
					cout << "\n->1. Modificati numele bolii";
					cout << "\n->2. Modificati simptomele";
					cout << "\n->3. Modificati numarul de cazuri totale";
					cout << "\n->4. Modificati lunile de imbolnavire";
					cout << "\nAlegeti varianta de la 1 la 4 : ";
					cin >> opt;
					if (opt == 1) {
						char numeb[100];
						cout << "\nIntroduceti nume bolii:";
						cin >> numeb;
						b2.setNume(numeb);
						opt = 4;
					}
					else if (opt == 2) {
						int nrsimp;
						string simp[100];
						cout << "\nIntroduceti numarul de simptome: "; cin >> nrsimp;
						for (int i = 0; i < nrsimp; i++) {
							cout << "\Simptomul " << i + 1 << ": "; cin >> simp[i];
						}
						b2.setNrSimptome(nrsimp, simp);
						opt = 4;
					}
					else if (opt == 3) {
						int nrcztot;
						cout << "\nIntroduceti numarul cabinetelor: "; cin >> nrcztot;
						b2.setNrCazuri(nrcztot);
						opt = 4;
					}
					else if (opt == 4) {
						int nrluni;
						string luni[100];
						int nrczluna[100];
						cout << "\nIntroduceti numarul de luni: "; cin >> nrluni;
						for (int i = 0; i < nrluni; i++) {
							cout << "\nLuna " << i + 1 << ": "; cin >> luni[i];
							cout << " - "; cin >> nrczluna[i]; cout << " cazuri";
						}
						b2.setNrLuniImbolnavire(nrluni, luni, nrczluna);
						opt = 4;
					}
					else {
						cout << "\nOptiune invalda";
						opt = 6;
					}
				}
				else {
					cout << "\nOptiune invalda";
					opt = 6;
				}
			}
			else if (opt == 4) {
				cout << "\n****************Meniu****************\n";
				cout << "\n->1. Spital";
				cout << "\n->2. Laborator";
				cout << "\n->3. Policlinica";
				cout << "\n->4. Boala";
				cout << "\n->5. Autospeciale medicale";
				cout << "\n->6. Meniu";
				cout << "\n->7. Exit\n";
				cout << "\nAlegeti varianta de la 1 la 6: ";
				cin >> opt;
			}
			else if (opt == 5) {
				cout << "\nExit";
				fin = 1;
			}

		}
		else if (opt == 5) {
			cout << "\n****************Autospeciale medicale****************";
			cout << "\n->1. Adauga autospeciala noua";
			cout << "\n->2. Afisare autospeciala";
			cout << "\n->3. Afisari si modificari atribute autospeciala";
			cout << "\n->4. Meniu principal";
			cout << "\n->5. Iesire ";
			cout << "\nAlegeti varianta de la 1 la 5: ";
			cin >> opt;

			if (opt == 1) {
				cout << "\n****************Adauga autospeciala noua****************";
				cout << "\nOptiuni: ";
				cout << "\n->1. Adaugare autospeciala de la tastatura";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					AutospecialeMedicale am;
					cin >> am;
					cout << "Autospeciala adaugata!";
					fstream fOutTxt("Autospeciala(ft).txt", ios::out);
					am.writeTxtToFile(fOutTxt);
					fOutTxt.close();

					opt = 5;
				}
				else if (opt == 2)
					opt = 5;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 2) {
				cout << "\n****************Afisare****************";
				cout << "\n->1. Afisare autospeciala";
				cout << "\n->2. Inapoi";
				cout << "\n->3. Meniu principal";
				cout << "\nAlegeti varianta de la 1 la 3: ";
				cin >> opt;
				if (opt == 1) {
					fstream fInTxt("Autospeciala(ft).txt", ios::in);
					AutospecialeMedicale am;
					am.readTxtFromFile(fInTxt);
					fInTxt.close();
					cout << am;

					opt = 5;
				}
				else if (opt == 2)
					opt = 5;
				else if (opt == 3)
					opt = 6;
				else {
					cout << "\nOptiune invalida!";
					opt = 6;
				}
			}
			else if (opt == 3) {
				cout << "\n->1. Afisari";
				cout << "\n->2. Modificari";
				cout << "\nSelectati varianta de la 1 la 2 : ";
				cin >> opt;
				if (opt == 1) {
					cout << "\n->1. Afisati numele interventiei";
					cout << "\n->2. Afisati tipul autospecialei";
					cout << "\n->3. Afisati numarul de persoane autorizate";
					cout << "\n->4. Afisati specializarea";
					cout << "\n->5. Afisati numarul de km/ore de zbor";
					cout << "\n->6. Afisati numarul reviziilor";
					cout << "\n->7. Afisati reviziile";
					cout << "\n->8. Afisati disponibilitatea autospecialei";
					cout << "\nAlegeti varianta de la 1 la 8: ";
					cin >> opt;
					if (opt == 1) {
						cout << "Nume interventie: " << a2.getInterventie();
						opt = 5;
					}
					else if (opt == 2) {
						cout << "Tipul autospecialei:" << a2.getTipAutospeciala();
						opt = 5;
					}
					else if (opt == 3) {
						cout << "Numarul de persoane autorizate este: " << a2.getNrPersoaneAutorizate();
						opt = 5;
					}
					else if (opt == 4) {
						string* spec = a2.getSpecializare();
						for (int i = 0; i < a2.getNrPersoaneAutorizate(); i++)
							cout << "\nSpecializarea " << i + 1 << ": " << spec[i];
						opt = 5;
					}
					else if (opt == 5) {
						cout << "Numarul de km/ore de zbor este: " << a2.getNrKm_oreZbor();
						opt = 5;
					}
					else if (opt == 6) {
						cout << "Numarul de revizii este: " << a2.getNrRevizii();
						opt = 5;
					}
					else if (opt == 7) {
						float* rvz = a2.getRevizie();
						for (int i = 0; i < a2.getNrRevizii(); i++)
							cout << "\nRevizia " << i + 1 << ": " << rvz[i];
						opt = 5;
					}
					else if (opt == 8) {
						cout << "Disponibilitatea autospecialei: " << a2.getDisponibilitate();
						opt = 5;
					}
					else {
						cout << "\nOptiune invalida!";
						opt = 6;
					}
				}
				else if (opt == 2) {
					cout << "\n->1. Modificati interventia";
					cout << "\n->2. Modificati tipul autospecialei";
					cout << "\n->3. Modificati persoanele autorizate";
					cout << "\n->4. Modificati numarul de km/ore de zbor";
					cout << "\n->5. Modificati reviziile";
					cout << "\n->6. Modificati disponibilitatea";
					cout << "\nAlegeti varianta de la 1 la 6 : ";
					cin >> opt;
					if (opt == 1) {
						char interv[100];
						cout << "\nIntroduceti nume interventie:";
						cin >> interv;
						a2.setInterventie(interv);
						opt = 5;
					}
					else if (opt == 2) {
						string numam;
						cout << "\nIntroduceti tipul autospecialei:";
						cin >> numam;
						a2.setTipAutospeciala(numam);
						opt = 5;
					}
					else if (opt == 3) {
						int nrpersaut;
						string spec[100];
						cout << "\nIntroduceti numarul de persoanele autorizate: "; cin >> nrpersaut;
						for (int i = 0; i < nrpersaut; i++) {
							cout << "\nSpecializare " << i + 1 << ": "; cin >> spec[i];
						}
						a2.setNrPersoaneAutorizate(nrpersaut, spec);
						opt = 5;
					}
					else if (opt == 4) {
						int nrkm_orezb;
						cout << "\nIntroduceti numarul de km/ore de zbor: "; cin >> nrkm_orezb;
						a2.setNrKm_oreZbor(nrkm_orezb);
						opt = 5;
					}
					else if (opt == 5) {
						int nrrev;
						float rev[100];
						cout << "\nIntroduceti numarul de revizii: "; cin >> nrrev;
						for (int i = 0; i < nrrev; i++) {
							cout << "\nRevizia " << i + 1 << ": "; cin >> rev[i];
						}
						a2.setNrRevizii(nrrev, rev);
						opt = 5;
					}
					else if (opt == 6) {
						bool disp;
						cout << "\nIntroduceti disponibilitatea(1/0): "; cin >> disp;
						a2.setDisponibilitate(disp);
						opt = 5;
					}
					else {
						cout << "\nOptiune invalda";
						opt = 6;
					}
				}
				else {
					cout << "\nOptiune invalda";
					opt = 6;
				}
			}
			else if (opt == 4) {
				cout << "\n****************Meniu****************\n";
				cout << "\n->1. Spital";
				cout << "\n->2. Laborator";
				cout << "\n->3. Policlinica";
				cout << "\n->4. Boala";
				cout << "\n->5. Autospeciale medicale";
				cout << "\n->6. Meniu";
				cout << "\n->7. Exit\n";
				cout << "\nAlegeti varianta de la 1 la 6: ";
				cin >> opt;
			}
			else if (opt == 5) {
				cout << "\nExit";
				fin = 1;
			}

		}
		else if (opt == 6) {
			cout << "\n****************Meniu****************\n";
			cout << "\n->1. Spital";
			cout << "\n->2. Laborator";
			cout << "\n->3. Policlinica";
			cout << "\n->4. Boala";
			cout << "\n->5. Autospeciale medicale";
			cout << "\n->6. Meniu";
			cout << "\n->7. Exit\n";
			cout << "\nAlegeti varianta de la 1 la 6: ";
			cin >> opt;
		}
		else if (opt == 7) {
			cout << "\nExit";
			fin = 1;
		}
	}

	return 0;
}