#pragma once
#ifndef BUKU_H
#define BUKU_H

class buku {
public:
	string nama;
	buku(string pNama) :nama(pNama) {
		cout << "Buku \"" << nama << "\" ada\n";
	}
	~buku() {
		cout << "Buku \"" << nama << "\" tidak ada\n";
	}
};

#endif
