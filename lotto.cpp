#include "lotto.h"

void main(int argc, char** args) {
	
	if( !readFile("otos.csv") )
		return 0;
	
	printf("Lottok: %d\n", lottok.size());
	
	return 1;
}

bool readFile(const char* filename) {
	FILE *f;
	f = fopen(filename, "r");
	
	if( f == NULL ) {
		printf("Failed to open file: %s\n", filename);
		return false;
	}
	
	int r;
	while( true ) {
		Lotto l;
		
		r = fscanf(f, 
			"%d;%d;%d.%d.%d.;%d;%d Ft;%d;%d Ft;%d;%d Ft;%d;%d Ft;%d;%d;%d;%d;%d\n",
			&l.ev,
			&l.het,
			&l.datum.ev,
			&l.datum.honap,
			&l.datum.nap,
			&l.talalat_db_5,
			&l.talalat_ft_5,
			&l.talalat_db_4,
			&l.talalat_ft_4,
			&l.talalat_db_3,
			&l.talalat_ft_3,
			&l.talalat_db_2,
			&l.talalat_ft_2,
			&l.szamok[0],
			&l.szamok[1],
			&l.szamok[2],
			&l.szamok[3],
			&l.szamok[4]);
			
		if( r == EOF )
			break;
		
		lottok.push_back(l);
	}
	
	fclose(f);
	
	return true;
}