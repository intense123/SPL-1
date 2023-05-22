#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1024
#define MAX 100
 typedef  struct Node{
	char item[100];
	int freq;
	int child_count;
	struct Node *children[MAX];
	struct Node *parent;
	struct Node *next;
	//struct Node *next;
}node;

typedef struct header{
	char item[100];
	int freq;
	node *first_node;
	struct header *next1;
	struct header *prev1;
} header_node;

typedef struct condition{
	char item[100];
	int freq;
	struct conditon *child[MAX];
	struct condition *next;
	}condition_node;
header_node *start = NULL;
node *root = NULL;
int index1;


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
