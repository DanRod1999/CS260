#include <stdio.h>

#define MAX_LEN 100

typedef struct cell
{
    int right_sibling;
    int leftmost_child;
    char label;
} cell;

cell cellspace[100];

int find_avail(void){
    int avail = 1;
    while(cellspace[avail].label != ' '){
        avail++;
    }
    return avail;
}


int create_0(char v){

	int avail = find_avail();
	
	cellspace[avail].leftmost_child = 0;
	cellspace[avail].label = v;
	cellspace[avail].right_sibling = 0;

	return avail;
}

int create_1(char v, int T1){

	int avail = find_avail();
	
	cellspace[avail].leftmost_child = T1;
	cellspace[avail].label = v;
	cellspace[avail].right_sibling = 0;

	cellspace[T1].right_sibling = 0;
	
	return avail;
}

int create_2(char v, int T1, int T2){
	
	int avail = find_avail();

	cellspace[avail].leftmost_child = T1;
	cellspace[avail].label = v;
	cellspace[avail].right_sibling = 0;
	
	cellspace[T1].right_sibling = T2;
	cellspace[T2].right_sibling = 0;

	return avail;
}

int create_3(char v, int T1, int T2, int T3){
	
	int avail = find_avail();

	cellspace[avail].leftmost_child = T1;
	cellspace[avail].label = v;
	cellspace[avail].right_sibling = 0;
	
	cellspace[T1].right_sibling = T2;
	cellspace[T2].right_sibling = T3;
	cellspace[T3].right_sibling = 0;

	return avail;
}


int LEFTMOST_CHILD(int n, int T){
	
	return cellspace[n].leftmost_child;
}

int RIGHT_SIBLING(int n, int T){

	int right_sib = cellspace[n].right_sibling;
	return right_sib;
}

char LABEL(int n, int T){

	return cellspace[n].label;
}

int ROOT(int T){

	return T;
}

void MAKENULL(void){

	for( int i = 0; i < MAX_LEN; i++){
		cellspace[i].label = ' ';
		cellspace[i].right_sibling = 0;
		cellspace[i].leftmost_child = 0;
	}
}


int main(){

	MAKENULL();



//                      A     T_final result
//                   B     C
//                  / \   / \ 
//                 D   E F   G
//                    /|\ 
//                   H I J


    int T1 = create_0('H');
    int T2 = create_0('I');
    int T3 = create_0('J');

    T2 = create_3('E', T1, T2, T3);  
    T1 = create_0('D');                
                                     
    T1 = create_2('B', T1, T2); 
   
    int T_1 = create_0('F');               
    int T_2 = create_0('G');

    T2 = create_2('C', T_1, T_2);

    int T_final = create_2('A', T1, T2);



	int i = 1;
	printf("Index   LC      Label   RS\n");
	while(cellspace[i].label != ' '){

		printf("%d       %d         %c      %d\n", i, cellspace[i].leftmost_child, cellspace[i].label, cellspace[i].right_sibling);
		i++;
	}	

    printf("Left child of B: %d\n", LEFTMOST_CHILD(6, T_final));
    printf("Right sibling of F: %d\n", RIGHT_SIBLING(8, T_final));
    printf("Label of node 10: %c\n", LABEL(10, T_final));
    printf("ROOT: %d\n", T_final);
    MAKENULL();
	while(cellspace[i].label != ' '){

		printf("%d       %d         %c      %d\n", i, cellspace[i].leftmost_child, cellspace[i].label, cellspace[i].right_sibling);
		i++;
	}
}
