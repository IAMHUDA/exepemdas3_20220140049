#include <iostream>
#include <vector>
using namespace std;


#include "buku.h";
#include "dikarang.h";

class pengarang;
class penerbit {
public:
	string nama_penerbit;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) : nama_penerbit(pNama) {
		cout << "penerbit \"" << nama_penerbit << "\"  \n";
	}
	~penerbit() {
		cout << "penerbit \"" << nama_penerbit << "\" tidak ada \n";
	}

	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

class pengarang {
public:
	string nama_pengarang;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) : nama_pengarang(pNama) {
		cout << "pengarang \"" << nama_pengarang << "\"  \n";
	}
	~pengarang() {
		cout << "pengarang\"" << nama_pengarang << "\" tidak ada \n";
	}

	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};

void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "Daftar pengarang yang menerbitkan buku pada \"" << this->nama_penerbit << "\" : \n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama_pengarang << "\n";
	}
	cout << endl;
}

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar penerbit yang dikuti oleh \"" << this->nama_pengarang << "\" : \n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama_penerbit << "\n";
	}
	cout << endl;
}

int main() {


	penerbit* Penerbit1 = new penerbit("Gama Press");
	penerbit* Penerbit2 = new penerbit("Intan Pariwara");
	pengarang* Pengarang1 = new pengarang("Giga");
	pengarang* Pengarang2 = new pengarang("Joko");
	pengarang* Pengarang3 = new pengarang("Asroni");
	pengarang* Pengarang4 = new pengarang("Lia");
	buku* Buku1 = new buku("Fisika");
	buku* Buku2 = new buku("Algoritma");
	buku* Buku3 = new buku("Basisdata");
	buku* Buku4 = new buku("Dasar Pemrograman");
	buku* Buku5 = new buku("Matematika");
	buku* Buku6 = new buku("Multimedia 1");
	karangan* Karangan1 = new karangan("Joko");
	karangan* Karangan2 = new karangan("Lia");
	karangan* Karangan3 = new karangan("Asroni");
	karangan* Karangan4 = new karangan("Giga");

	Penerbit1->tambahPengarang(Pengarang2);
	Penerbit1->tambahPengarang(Pengarang4);
	Penerbit1->tambahPengarang(Pengarang1);
	Penerbit2->tambahPengarang(Pengarang3);
	Penerbit2->tambahPengarang(Pengarang1);
	Pengarang1->tambahPenerbit(Penerbit1);
	Pengarang1->tambahPenerbit(Penerbit2);
	Karangan1->tambahBuku(Buku1);
	Karangan1->tambahBuku(Buku2);
	Karangan2->tambahBuku(Buku3);
	Karangan3->tambahBuku(Buku4);
	Karangan4->tambahBuku(Buku5);
	Karangan4->tambahBuku(Buku6);

	cout << "\n______________________\n" << endl;
	cout << "\nOUTPUT PROGRAM\n" << endl;
	cout << "_______________________\n" << endl;
	Penerbit1->cetakPengarang();
	Penerbit2->cetakPengarang();
	Pengarang1->cetakPenerbit();
	Karangan1->cetakBuku();
	Karangan2->cetakBuku();
	Karangan3->cetakBuku();
	Karangan4->cetakBuku();
	cout << "\n______________________\n" << endl;

	return 0;
}