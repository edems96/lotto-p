#include "lotto.h"

int main(int argc, char** args) {
	
	if( !readFile("otos.csv") )
		return 0;
	
	printf("Lottok: %d\n", lottok.size());
	
	elozo();
	//stat1();
	stat2();
	
	return 1;
}

void elozo() {
	uint c = 0;
	
	for(uint i = 0; i < lottok.size()-1; i++) {
		if( in_array(lottok[i].szamok, 5, lottok[i+1].szamok, 5) )
			c++;
	}
	
	printf("Elozo: %d/%d = %.3f\n", c, lottok.size(), ((float)c / (float)lottok.size()) * 100.0f);
}

void stat1() {
	uint c[90] = {0};
	
	for(uint i = 0; i < lottok.size(); i++) {
		for(uint j = 0; j < 5; j++) {
			c[lottok[i].szamok[j]-1]++;
		}
	}
	
	uint ossz = lottok.size() * 5;
	for(uint i = 0; i < 90; i++) {
		printf("%d: %d / %d (%.2f)\n", i+1, c[i], ossz, ((float)c[i] / (float)ossz) * 100.f);
	}
	
}

void stat2() {
	uint c[90] = {0};
	
	for(uint i = 0; i < lottok.size(); i++) {
		for(uint j = 0; j < 5; j++) {
			c[lottok[i].szamok[j]-1]++;
		}
	}
	
	uint max = 0;
	for(uint i = 0; i < 90; i++) {
		if( c[i] > max )
			max = c[i];
	}
	
	uint ossz = lottok.size() * 5;
	
	for(uint j = max; j >= 0; j--) {
		for(uint i = 0; i < 90; i++) {
			if( c[i] != j )
				continue;
			
			printf("%d: %d / %d (%.2f)\n", i+1, c[i], ossz, ((float)c[i] / (float)ossz) * 100.f);
		}
	}
	
	
}

bool readFile(const char* filename) {
	FILE *f;
	f = fopen(filename, "r");
	
	if( f == NULL ) {
		printf("Failed to open file: %s\n", filename);
		return false;
	}
	
	printf("Read file: %s\n", filename);
	
	int r;
	while( true ) {
		Lotto l;
		
		r = fscanf(f, 
			"%d;%d;",
			&l.ev,
			&l.het);
			
		if( r != 2 )
			break;

		r = fscanf(f, 
			"%d.%d.%d.;",
			&l.huzas.ev,
			&l.huzas.honap,
			&l.huzas.nap);
			
		if( r != 3 )
			fgetc(f); // ;
		
		r = fscanf(f,
			"%d;%dFt;%d;%dFt;%d;%dFt;%d;%dFt;%d;%d;%d;%d;%d\r\n",
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
			
		if( r != 13 )
			break;
		
		lottok.push_back(l);
	}
	
	fclose(f);
	
	return true;
}

bool in_array(uint number, uint *array, uint size) {
	for(uint i = 0; i < size; i++) {
		if( array[i] == number )
			return true;
	}
	
	return false;
}

bool in_array(uint *a1, uint s1, uint *a2, uint s2) {
	for(uint i = 0; i < s1; i++) {
		if( in_array(a1[i], a2, s2) )
			return true;
	}
	
	return false;
}