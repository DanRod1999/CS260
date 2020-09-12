/*
 * CS 260
 * HW 2
 *
 */


#include <stdio.h>

#define MAX_LEN 100

int FIRST(int * L){
	if (L[0] == NULL){
		printf("empty list\n");
		return NULL;
	}else
		return 0;
}

int END(int * L){
	int i = 0;
	while (L[i] != NULL){
		i++;
	}
	return i-1;
}


int RETRIEVE(int p, int * L){
	if( p != END(L)+1){
		return L[p];
	}
	else{
		printf("no element in this position\n");
		return NULL;
	}
}

int LOCATE(int x, int * L){
	int p = 0;
	while( p != END(L)+1){
		if(L[p] ==x )
			return p;
		p++;
	}

	printf("no element in list\n");
	return NULL;

}

int NEXT(int p, int * L){
	if( p == END(L) ){
		printf("undefined\n");
		return NULL;
	}else{
		return p + 1;
	}
}

int PREVIOUS(int p, int * L){
	if( p == FIRST(L) ){
		printf("undefined\n");
		return NULL;
	}else{
		return p - 1;
	}
}

int * INSERT(int x, int p, int * L){
	int i = END(L) + 2;
	while ( i != p ){
		L[i] = L[i - 1];
		i--;
	}
	L[p] = x;

	return L;
}

int *  DELETE(int p, int * L){
	while( p != END(L)){
		L[p] = L[p+1];
		p++;
	}
	L[END(L)] = NULL;
	return L;

}

int MAKENULL(int * L){
	for( int i = 0; i <MAX_LEN; i++){
		L[i] = NULL;
	}
	return L;
}

void PRINTLIST(int * L){
	
	if(L[0] == NULL){
		printf("empty list");
	}

	int i = 0;
	while(L[i] != NULL){
		printf("%d ",L[i]);
		i++;
	}
	printf("\n");
}

int main(void){

	int  List [100] = {0};
	int* L = List;



	/*int first = FIRST(L);
	printf("%d\n", first);
	PRINTLIST(L);*/
	
	L = INSERT(1,0,L);
	L = INSERT(3,1,L);
	PRINTLIST(L);

	L = INSERT(2,1,L);
	PRINTLIST(L);

	L = INSERT(9,1,L);
	L = INSERT(8,1,L);
	L = INSERT(7,1,L);
	L = INSERT(6,1,L);
	PRINTLIST(L);

	L = DELETE(5,L);
	PRINTLIST(L);

	printf("%d\n", RETRIEVE(3,L));
	printf("%d\n", LOCATE(6,L));

	MAKENULL(L);
	PRINTLIST(L);
	
	return 0;
}
