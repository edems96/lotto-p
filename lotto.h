#include <cstdio>
#include <vector>

typedef unsigned int uint;

struct Datum {
	uint ev, honap, nap;
};

struct Lotto {
	uint ev, het;
	Datum huzas;
	
	uint talalat_db_5;
	uint talalat_ft_5;
	
	uint talalat_db_4;
	uint talalat_ft_4;
	
	uint talalat_db_3;
	uint talalat_ft_3;
	
	uint talalat_db_2;
	uint talalat_ft_2;
	
	uint szamok[5];
	
	void print() {
		printf("#LOTTO#\n");
		printf("\tEv: %d\n", ev);
		printf("\tHet: %d\n", het);
		printf("\tHuzas: %d. %d. %d\n", datum.ev, datum.honap, datum.nap);
		printf("\tTalalat:\n")
		printf("\t\t5 (db): %d\n", talalat_db_5);
		printf("\t\t5 (Ft): %d\n", talalat_ft_5);
		printf("\t\t4 (db): %d\n", talalat_db_4);
		printf("\t\t4 (Ft): %d\n", talalat_ft_4);
		printf("\t\t3 (db): %d\n", talalat_db_3);
		printf("\t\t3 (Ft): %d\n", talalat_ft_3);
		printf("\t\t2 (db): %d\n", talalat_db_2);
		printf("\t\t2 (Ft): %d\n", talalat_ft_2);
		printf("\tSzamok: %d, %d, %d, %d, %d", szamok[0], szamok[1], szamok[2], szamok[3], szamok[4]);
		printf("#######\n\n");
	}
};

vector<Lotto> lottok;

void main(int argc, char** args);
bool readFile(const char* filename);