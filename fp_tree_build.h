#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"item_struct.h"
#define BUFFER_SIZE 1024
#define MAX 100

 typedef  struct Node{
	char item[MAX];
	int freq;
	int child_count;
	struct Node *children[MAX];
	struct Node *parent;
	struct Node *next;
	//struct Node *next;
}node;

typedef struct header{
	char item[MAX];
	int freq;
	node *first_node;
	struct header *next1;
	struct header *prev1;
} header_node;

typedef struct condition{
	char item[MAX];
	int freq;
	struct conditon *child[MAX];
	struct condition *next;
	}condition_node;
header_node *start = NULL;
node *root = NULL;
int index1;

/*condition_node *create_condition_header(char str[]){
		condition_node *temp = (condition_node *) malloc(sizeof(condition_node));
		strcpy(temp->item, str);
		temp->next = NULL;
		for (int i=0; i<MAX; i++)
			temp->child[i] = NULL;
		return temp;
		}
condition_node *create_conditon(char str[], int freq1){
			condition_node *temp = (condition_node *) malloc(sizeof(condition_node));
			strcpy(temp->item, str);
			temp->freq =freq1
			temp->next = NULL;
			for (int i=0; i<MAX; i++)
				temp->child[i] = NULL;
		return temp;
		}*/

node *create_node(char str[]){
	
	node *temp1 = (node*) malloc(sizeof(node)); 
	
	strcpy(temp1->item, str);
	
	temp1->freq = 1;
	temp1->child_count = 0;
	temp1->parent = NULL;
	temp1->next = NULL;
	for(int i = 0; i<MAX; i++){
	temp1->children[i] = NULL;
	
		}
	return temp1;
	
	}
	
void create_header_list(char str[], node *current)
     { 
     //header_node *prev, *curr, *temp;
     //prev = NULL;
     //curr = start;
     
     if (start == NULL) {
     		header_node *temp = (header_node *)malloc(sizeof(header_node));
		strcpy(temp->item, str);
		temp->freq = header_count(str);
		temp->first_node = current;
		temp->next1 = NULL;
		temp->prev1 = NULL;
		start = temp;
		}
	else
		{
	 	header_node *temp= start;
	 	header_node *prev= NULL;
	 	while (temp!= NULL){
	 		if (strcmp(temp->item, str)==0)
	 			break;
	 		else {
	 			prev = temp;
	 			temp= temp->next1;
	 		}
	 	}
	 	if(temp == NULL){
	 		header_node *temp1 = (header_node *)malloc(sizeof(header_node));
			strcpy(temp1->item, str);
			temp1->freq =header_count(str);
			temp1->first_node = current;
			temp1->next1 = NULL;
			temp1 ->prev1 = NULL;
			
			header_node *curr, *prev= NULL;
			
			curr = start;
			if (start->freq <temp1->freq) {
				temp1->next1 = start;
				start->prev1= temp;
				start = temp1;
				}
			else{
				while ((curr->freq > temp1->freq)&& (curr->next1 != NULL))
					{
						prev = curr;
						curr = curr->next1;
						}
				if(curr->next1 == NULL) {
					/*if (curr->freq == temp1->freq){
						if(strcmp(curr->item, temp1->item)>0)
							curr->next1 = temp1;
						else {
						
							temp1->next1 = prev->next1;;
							prev->next1 = temp;
							}	
						} */
						curr->next1 = temp1;
						temp1->prev1 = curr;
				}
				else {
					if(curr->freq == temp1->freq){
						if(strcmp(curr->item, temp1->item)>0){
							temp1->next1 = curr->next1;
							curr->next1->prev1 = temp1;
							temp1->prev1 = curr;
							curr->next1 = temp1;
							}
						else {
					
							temp1->next1 = prev->next1;
							prev->next1->prev1 = temp1;
							prev->next1 = temp1;
							temp1->prev1 = prev;
						}
					}
				else { 
					temp1->next1 = prev->next1;
							prev->next1->prev1 = temp1;
							prev->next1 = temp1;
							temp1->prev1 = prev;
					}
				}
			}
							
				
		}
	
			//prev->next1= temp1;
	else {
		
		 	node *prev, *curr;
		 	curr = temp->first_node;
		 	prev = NULL;
		 	while(curr!= NULL)
		 	{
		 		prev = curr;
		 		curr= curr->next;
		 	}
		 	prev->next = current;
		 	}
	 	}
	}

	


void build_tree( const char *filename){ 
    
    const char *delimiter_characters = ",";
     FILE *input_file = fopen( filename, "r" );
    char buffer[ BUFFER_SIZE ];
    char *last_token;
    char arr[20];
    int length;
    node *temp1 = (node*) malloc(sizeof(node)); 
    root = temp1;                   
    strcpy(root->item, "");
    root->freq = 0;
    root->child_count = 0;
    
    for(int i = 0; i<MAX; i++){
	root->children[i] = NULL;
	
	}
     root->parent =  NULL;
     root->next = NULL;
    
   
    if( input_file == NULL ){

        fprintf( stderr, "Unable to open file %s\n", filename );

    }else{
        // Read each line into the buffer
        while( fgets(buffer, BUFFER_SIZE, input_file) != NULL ){
	     node *temp = root;
	     
	     printf("\n Read Line\n");
	     
            
            // Gets each token as a string and prints it
            last_token = strtok( buffer, delimiter_characters );
            while( last_token != NULL ){//It completes frequency count
                //printf( "%s\n", last_token);
                length = strlen(last_token);
                
                strcpy(arr, last_token);
                //printf("\n%d %s %s\n", length, arr, last_token);    
                if(arr[length - 1] == '\n'){
                	//printf("\nI have a new line %s \n", arr);
                	arr[length - 1] = '\0';
                	//printf("\n I am %s present_lemgth %d", arr, strlen(arr)) ;
                	           }
                
                
                int index1= 0, flag = 0;
                if(temp->children[index1]!= NULL)
                	printf("\n%s\n", (temp->children[index1])->item);
                while(temp->children[index1] != NULL){
                	node *current = temp->children[index1];
                	printf("\n %s %s\n", current->item, arr);
                	
                	if(strcmp(arr, current->item)== 0){
                		current->freq++;
                		flag = 1;
                		break;
                	}
                	index1++;
                 }
                 printf("\n%d %d\n", flag,index1);
                 
                 
                 
                 if(flag != 1){
                 	//int count = temp->child_count;
                 		
                 		node *current = create_node(arr);
                		current->parent = temp;
				for(int i = 0; i<MAX; i++){
					current->children[i] = NULL;
				
                		 }
                		 temp ->children[index1] = current;
                		 temp ->child_count++;
                		 create_header_list(arr, current);
                		 printf("\n the flag is 0 \n");
                  
                 		}
                 
                 
                  
                  temp = temp->children[index1];
		   if(temp!=NULL)
		   printf("\n %s \n", temp->item);
		   
                
                last_token = strtok( NULL, delimiter_characters );
            

        }
        printf("\n complete\n");
        }

        if( ferror(input_file) ){
            perror( "The following error occurred" );
        }

        fclose( input_file );
       
    	}
    	
    	}
    	




	void traverse_tree(node* root) {
	if(strcmp(root->item, "")!=0)
    printf("%s %d", root->item, root->freq);
        for (int i = 0; i < MAX; i++) {
        if (root->children[i] != NULL) {
            traverse_tree(root->children[i]);
        }
    }
    printf("\n");
}

void print_header()
{
 header_node *temp=start;
 while (temp != NULL)
 {
 	printf("%s %d ", temp->item, temp->freq);
 	temp = temp->next1;
 	}
 printf("\n");
 header_node *temp1 = start;
 while(temp1->next1!= NULL)
 	temp1 = temp1->next1;
 while (temp1!= NULL)
 	{
 	printf("%s %d ", temp1->item, temp1->freq);
 	temp1 = temp1->prev1;
 	 }
 	printf("\n");
 
 }
 
 
void print_header_list()
{
 header_node  *temp = start;
 
 	while (temp!= NULL){
 
 	node *temp1 = temp->first_node;
 	
 	printf("%s ", temp->item);
 		temp1 = temp1->next;
 	 	while (temp1 != NULL)
 		{
 		printf("%s ", temp1->item);
 		temp1 = temp1->next;
 		}
 		printf("\n");
 	temp = temp->next1;
	}
}

void print_path(header_node *current)
	{
		printf("\n header item %s %d\n", current->item, current->freq);
		node *temp=current->first_node;
		//condition_node *con_head = create_condition_header(current->item)
		//node *temp1 = temp;
		while ((temp!= NULL)&&(strcmp(temp->item, ""))!=0){
			node *temp1 = temp;
			int test = temp1->freq;
				temp1 = temp1->parent;
			while (temp1 != NULL){
				printf("%s %d  ", temp1->item, test);
				temp1 =temp1->parent;
				}
			printf("\n");
			temp = temp->next;
		}
	}

int insert_item (int total_size, char current_items[MAX][MAX], int current_freq[MAX], char new_item[MAX], int new_freq) {
	for (int i = 0; i < total_size; ++i) {
		if (strcmp(current_items[i], new_item) == 0) return total_size;
	}
	current_freq[total_size] = new_freq;
	memcpy(current_items[total_size], new_item, MAX);
	int at = total_size;
	while (at > 0 && (current_freq[at - 1] > current_freq[at] || (current_freq[at - 1] == current_freq[at] && strcmp(current_items[at - 1], new_item) > 0))) {
		int temp_freq = current_freq[at - 1];
		current_freq[at - 1] = current_freq[at];
		current_freq[at] = temp_freq;
		memcpy(current_items[at], current_items[at - 1], MAX);
		memcpy(current_items[at - 1], new_item, MAX);
		--at;
	}
	return total_size + 1;
}

int total_freq (char item[MAX]) {
	header_node *temp = start;
	while (temp != NULL) {
		if (strcmp(temp->item, item) == 0) break;
		temp = temp->next1;
	}
	return temp->freq;
}

int total_itemsets;
char freq_itemsets[MAX][20][MAX];
long long keys[1000000], values[1000000], itemset_size[MAX];

void generate_fp(const char *filename) {
	FILE *output_file = fopen(filename, "w");

	header_node *temp = start;

	while (temp != NULL) {
		if (strcmp(temp->item, "") == 0) {
			temp = temp->next1;
			continue;
		}

		int total_size = 0;
		char current_items[1000][MAX];
		int current_freq[1000];
		memset(current_items, 0, sizeof(current_items));

		node *temp1 = temp->first_node;
		temp1 = temp1->next;
		
		while (temp1 != NULL) {
			node *tree_node = temp1;
			while (tree_node->parent != NULL) {
				tree_node = tree_node->parent;
				if (strcmp(tree_node->item, "") == 0) break;
				total_size = insert_item(total_size, current_items, current_freq, tree_node->item, total_freq(tree_node->item));
			}
			temp1 = temp1->next;
		} 
		memcpy(current_items[total_size], temp->item, MAX);

		int map_size = 0;
		temp1 = temp->first_node;
		temp1 = temp1->next;

		char path[MAX][MAX];
		
		while (temp1 != NULL) {
			node *tree_node = temp1;
			int path_length = 0;
			while (tree_node->parent != NULL) {
				tree_node = tree_node->parent;
				if (strcmp(tree_node->item, "") == 0) break;
				memcpy(path[path_length++], tree_node->item, MAX);
			}
			for (int path_mask = 1; path_mask < 1 << path_length; ++path_mask) {
				int at = 0;
				long long mask = 0;
				for (int i = 0; i < path_length; ++i) if (path_mask & 1 << i) {
					while (at < total_size && strcmp(current_items[at], path[i]) != 0) ++at;
					assert(at < total_size);
					mask |= 1LL << at;
				}
				int pos = 0;
				while (pos < map_size && keys[pos] != mask) ++pos;
				if (pos == map_size) ++map_size, keys[pos] = mask, values[pos] = temp1->freq;
				else values[pos] += temp1->freq;
			} 
			temp1 = temp1->next;
		}	
		assert(map_size < 1000000);
		for (int i = 0; i < map_size; ++i) {
			long long mask = keys[i] | 1LL << total_size;
			long long total_count = values[i];

			if (total_count < MIN_SUP) continue;

			int this_size = 0;
			// frequent itemset
			fprintf(output_file, "Frequency: %lld, Itemset: ", total_count);
			fprintf(output_file, "%s", temp->item);
			memcpy(freq_itemsets[total_itemsets][this_size++], temp->item, MAX);
			for (int j = 0; j < total_size; ++j) if (mask & 1LL << j) {
				fprintf(output_file, ", %s", current_items[j]);
				memcpy(freq_itemsets[total_itemsets][this_size++], current_items[j], MAX);	
			}
			fprintf(output_file, "\n");

			itemset_size[total_itemsets++] = this_size;
		}
		temp = temp->next1;

	}

	fprintf(output_file, "Total itemsets: %d\n", total_itemsets);
}

int buff_size;
char buff[20][MAX];

int get_count() {
	header_node *temp = start;
	int result = 0;

	while (temp != NULL) {
		if (strcmp(temp->item, buff[0]) != 0) {
			temp = temp->next1;
			continue;
		}

		node *temp1 = temp->first_node;
		temp1 = temp1->next;
		
		while (temp1 != NULL) {
			node *tree_node = temp1;
			int matched = 0;
			while (tree_node != NULL && matched < buff_size) {
				if (strcmp(tree_node->item, "") == 0) break;
				if (strcmp(tree_node->item, buff[matched]) == 0) ++matched;
				tree_node = tree_node->parent;
			}
			if (matched == buff_size) result += temp1->freq;
			temp1 = temp1->next;
		} 
		temp = temp->next1;
	}

	return result;
}

void generate_associations(const char *filename) {
	FILE *confidence_file = fopen(filename, "w");

	for (int i = 0; i < total_itemsets; ++i) {
		buff_size = 0;
		int this_size = itemset_size[i];
		for (int j = 0; j < this_size; ++j) {
			memcpy(buff[buff_size++], freq_itemsets[i][j], MAX);
		}
		int total_count = get_count();
		for (int mask = 1; mask < (1 << this_size) - 1; ++mask) {
			buff_size = 0;
			for (int j = 0; j < this_size; ++j) if (mask & 1 << j) {
				memcpy(buff[buff_size++], freq_itemsets[i][j], MAX);
			}
			int subset_count = get_count();
			if (subset_count == 0) continue;
			double confidence = (double) total_count / subset_count;
			if (confidence >= MIN_CONF) {
				for (int j = 0; j < this_size; ++j) if (mask & 1 << j) {
					fprintf(confidence_file, "%s ", freq_itemsets[i][j]);
				}
				fprintf(confidence_file, "--> ");
				for (int j = 0; j < this_size; ++j) if (!(mask & 1 << j)) {
					fprintf(confidence_file, "%s ", freq_itemsets[i][j]);
				}
				fprintf(confidence_file, "............ with confidence %0.6f percent\n", confidence * 100);
			}
		}
	}
}

/*int main( )
{
 
   
   int i;
  
   const char *filename = "sorted_transaction.txt";
   build_tree( filename);
   int test = 0;
    traverse_tree(root);
    printf("\n******\n");
    print_header();
    printf("\n*****\n");
    header_node *temp;
    temp = start;
    while(temp->next1!=NULL){
    	printf("\n");
    	print_path(temp);
    	printf("\n");
    	temp = temp->next1;
    	}
    //print_path(temp);
    return 0;
}*/

	
