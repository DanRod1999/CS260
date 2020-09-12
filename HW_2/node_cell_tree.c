
#include <stdio.h>

#define MAX_NODES 100;



//struct for elements in nodespace
typedef struct node 
{
    char label;
    int header;
} node;

//struct for elements in cellspace array
typedef struct cell
{
    int node;
    int next;
} cell;

node nodespace[100];
cell cellspace[100];

int find_avail_node(void){
    int i = 1;
    while(nodespace[i].label != ' '){
        i++;
    }
    return i;
}

int find_avail_cell(void){
    int i = 1;
    while(cellspace[i].node != 0){
        i++;
    }
    return i;
}

int create_0(char v){

    int avail = find_avail_node();
    nodespace[avail].label = v;
    nodespace[avail].header = 0;

    return avail;
}



int create_1(char v, int T){
    int avail_cell = 1;
    int avail_node = 1;
    avail_node = find_avail_node(); // find first available spot in nodespace

    avail_cell = find_avail_cell(); // find first available spot in cellspace

    nodespace[avail_node].label = v; //set label to first available position in nodespace
    nodespace[avail_node].header = avail_cell; //set header to available spot in cellspace
    cellspace[avail_cell].node = T; //set node to same value as the index being used
    cellspace[T].next = 0; //no value for next because only one tree is being used. no sibling necessary

    return avail_node; // return nodespace index of new tree root

}

int create_2(char v, int T1, int T2){
    int avail_cell = 1;
    int avail_node = 1;
    avail_node = find_avail_node(); // find first available spot in nodespace

    avail_cell = find_avail_cell(); // find first available spot in cellspace

    nodespace[avail_node].label = v; //set label to first available position in nodespace
    nodespace[avail_node].header = avail_cell; //set header to available spot in cellspace

    cellspace[avail_cell].node = T1; //set node to same value as the index being used
    int avail_cell_2 = find_avail_cell(); // search for new available cellspace
    cellspace[avail_cell].next = avail_cell_2; //set next to index of T2

    cellspace[avail_cell_2].node = T2; //set node to index of T2 
    cellspace[avail_cell_2].next = 0; //no value for next because only one tree is being used. no sibling necessary

    return avail_node;

}

int create_3(char v, int T1, int T2, int T3){
    int avail_cell = 1;
    int avail_node = 1;
    avail_node = find_avail_node(); // find first available spot in nodespace

    avail_cell = find_avail_cell(); // find first available spot in cellspace

    nodespace[avail_node].label = v; //set label to first available position in nodespace
    nodespace[avail_node].header = avail_cell; //set header to available spot in cellspace

    cellspace[avail_cell].node = T1; //set node to same value as the index being used
    int avail_cell_2 = find_avail_cell(); // search for new available cellspace for next
    cellspace[avail_cell].next = avail_cell_2; //set next to new free space

    cellspace[avail_cell_2].node = T2; //set node to T2
    int avail_cell_3 = find_avail_cell(); // search for new available cellspace
    cellspace[avail_cell_2].next = avail_cell_3; //set next to new free space

    cellspace[avail_cell_3].node = T3; //set node to index of T3
    cellspace[avail_cell_3].next = 0; //no value for next because only one tree is being used. no sibling necessary

    return avail_node;

}

int LEFTMOST_CHILD(int n, int T){
	
	int header = nodespace[n].header;
	int left_child = cellspace[header].node;
	return left_child;
}

int RIGHT_SIBLING(int n, int T){

	//find where n == cellspace[i].node
	int i = 1;
	while(cellspace[i].node != n){
		i++;
	}
	int right_sib_pos = cellspace[i].next;
	int right_sib = cellspace[right_sib_pos].node;
	return right_sib;
}

char LABEL(int n, int T){

	return nodespace[n].label;
}

int ROOT(int T){

	return T; //Trees are described by the index of their root
}

void MAKENULL(void){

	for(int i = 0; i < 100; i++){
		nodespace[i].label = ' ';
		nodespace[i].header = 0;
		cellspace[i].node = 0;
		cellspace[i].next = 0;
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
	printf("Index   label      header       Index   node      next\n");
	while(nodespace[i].label != ' '){

		printf("%d        %c         %d               %d          %d        %d\n", i, nodespace[i].label, nodespace[i].header, i, cellspace[i].node, cellspace[i].next);
		i++;
	}
    printf("Left child of C: %d\n", LEFTMOST_CHILD(9, T_final));
    printf("Right sibling of I: %d\n", RIGHT_SIBLING(2, T_final));
    printf("Label of node 10: %c\n", LABEL(10, T_final));
    printf("ROOT: %d\n", T_final);
    MAKENULL();

}
