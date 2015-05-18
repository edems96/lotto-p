#include "lotto.h"

int main(int argc, char** args) {
	srand (time(NULL));
	
	if( !readFile("otos.csv") )
		return 0;
	
	printf("Lottok: %d\n", lottok.size());
	
	elozo();
	//stat1();
	//stat2();
	
	for(uint i = 0; i < 10; i++) 
		proba1();
	
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

void proba1() {
	/* printf("utolso	| %d %d %d %d %d\n", 
	lottok[0].szamok[0], 
	lottok[0].szamok[1], 
	lottok[0].szamok[2], 
	lottok[0].szamok[3], 
	lottok[0].szamok[4]); */
	
	for(uint i = 0;; i++) {
		uint r[5];
		
		uint t = 0;
		for(uint x = 0; x < 5; x++) {
			r[x] = (uint)(rand() % 95 + 1);
			t += cin_array(r[x], lottok[0].szamok, 5);
		}
		
		//uint t = cin_array(r, 5, lottok[0].szamok, 5);
		
		if( t > 4 ) {
			printf("%d. t: %d | %d %d %d %d %d\n", i+1, t, r[0], r[1], r[2], r[3], r[4]);
			break;
		}
	}
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

uint cin_array(uint number, uint *array, uint size) {
	uint c = 0;
	
	for(uint i = 0; i < size; i++) {
		if( array[i] == number )
			c++;
	}
	
	return c;
}

uint cin_array(uint *a1, uint s1, uint *a2, uint s2) {
	uint c = 0;
	
	for(uint i = 0; i < s1; i++) {
		if( in_array(a1[i], a2, s2) )
			return c++;
	}
	
	return c;
}