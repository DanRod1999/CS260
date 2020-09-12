#include <stdio.h>

#define TRUE 1
#define FALSE 0


typedef struct dict{
	int key;
	char * value;
}dict;

typedef struct tree_node{
	dict data;
	struct tree_node * l_c;
	struct tree_node * r_c;
} *tree_node;



/*int MEMBER(dict node, * tree_node root){
	tree_node cur_node = root;
	while( cur_node->l_c != NULL && cur_node->r_c != NULL ){
		if(node.key == cur_node->data.key){
			return TRUE;
		}
		else{
			if (node.key < cur_node->data.key){
				cur_node = cur_node->l_c;
			}else{
				cur_node = cur_node->r_c;
			}
		}
	}
	return FALSE;
}*/

int MEMBER(int key, tree_node root){
	
	
	if( root == NULL )
		return FALSE;
	else if( root->data.key == key )
		return TRUE;
	else if( key < root->data.key )
		return MEMBER(key, root->l_c);
	else if( key > root->data.key )
		return MEMBER(key, root->r_c);
}

tree_node INSERT(dict node, tree_node root){

	tree_node new_node;
	new_node->data = node;
	new_node->l_c = NULL;
	new_node->r_c = NULL;

	if( root == NULL ){
		return new_node;
		
	}

	tree_node cur_node = root;
	while( cur_node->l_c != NULL && cur_node->r_c != NULL ){
		if(node.key == cur_node->data.key){
			return root;
		}
		if ( node.key < cur_node->data.key && cur_node->l_c == NULL ){
			cur_node->l_c = new_node;
			return root;
		}
		else if( node.key > cur_node->data.key && cur_node->r_c == NULL ){
			cur_node->r_c = new_node;
			return root;
		}
		else if (node.key < cur_node->data.key){
			cur_node = cur_node->l_c;
		}else{
			cur_node = cur_node->r_c;
		}

	}
}

tree_node DELETE(dict node, tree_node root){

	int key = node.key;
	if( root != NULL ){
		if( key < root->data.key )
			DELETE(node, root->l_c);
		else if( key > root->data.key )
			DELETE(node, root->r_c);
		else if( root->l_c == NULL && root->r_c == NULL )
			root = NULL;
		else if( root->l_c == NULL )
			root = root->r_c;
		else if( root->r_c == NULL )
			root = root->l_c;
		else
			root->data.key = DELETEMIN(root->r_c);
	}
}

int DELETEMIN(tree_node root){

	int min;
	if( root->l_c == NULL ){
		min = root->data.key;
		root = root->r_c;
		return min;
	}else{
		min = DELETEMIN(root->l_c);
        return min;
	}
}


int main(void){

	
	tree_node Root = NULL;
	
	dict first_ent; 
	first_ent.key = 50;
	first_ent.value = "HELLO";

	Root = INSERT(first_ent, Root);
	
	dict sec_ent; 
	sec_ent.key = 33;
	sec_ent.value = "THERE";
	dict third_ent; 
	third_ent.key = 66;
	third_ent.value = "GENERAL";
	dict fourth_ent; 
	fourth_ent.key = 25;
	fourth_ent.value = "KENOBI";
	dict fifth_ent; 
	fifth_ent.key = 43;
	fifth_ent.value = "AH";
	dict six_ent; 
	six_ent.key = 58;
	six_ent.value = "THE";
	dict sev_ent; 
	sev_ent.key = 77;
	sev_ent.value = "NEGOTIATOR";

	
	Root = INSERT(sec_ent, Root);
	Root = INSERT(third_ent, Root);
	Root = INSERT(fourth_ent, Root);
	Root = INSERT(fifth_ent, Root);
	Root = INSERT(six_ent, Root);
	Root = INSERT(sev_ent, Root);

	printf("Check MEMBER \n1 is true 0 is false\n");

	printf("MEMBER on 33 %d\n", MEMBER(33, Root));
	printf("MEMBER on 12 %d\n", MEMBER(12, Root));
	
	Root = DELETE(sec_ent, Root);
	printf("DELETE 33");
	printf("MEMBER on 33 %d\n", MEMBER(33, Root));

}





