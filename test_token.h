
#include"item_struct.h"
#include"sort.h"
#define BUFFER_SIZE 1024

int header_count(char str1[]){
int count = 0;
	for(int i = 0; item_info[i].count != 0; i++){
		if(strcmp(str1, item_info[i].name)==0)
			return item_info[i].count;
		}
	return 0;
}

//It returns frequency of given items
int item_count(struct item item_info[], char str1[]){
	
	int count = 0;
	for(int i = 0; item_info[i].count != 0; i++){
		if(strcmp(str1, item_info[i].name)==0)
			return item_info[i].count;
		}
	return 0;

}


void add_count(char str[], struct item item_info[]){
	//printf("\ncurrent token is: %s\n", str);
	int i = 0;
	for(i = 0; i<1000; i++){
		if(item_info[i].count == 0){
			strcpy(item_info[i].name, str);
			//printf("\nInserted token:%s\n", item_info[i].name);
			
			item_info[i].count = 1;
			break;
			}
		else{
		      if((strcmp(item_info[i].name, str)) == 0){
		           item_info[i].count++;
		           //printf("\nCount Increment of token:%s\n", item_info[i].name);
		      	    break;
		       } 
		      
		}
		
	}
}

void  add_transaction( char arr[], int count,struct item transaction_info[]){

	int i = 0;
	while(transaction_info[i].count!=0)
		i++;
	strcpy(transaction_info[i].name, arr);
	transaction_info[i].count = count;
	}

//It generates fequency table
void text_to_token(struct item item_info[], const char *filename){
    const char *delimiter_characters = ",";
    //const char *filename = "transaction.txt";
    FILE *input_file = fopen( filename, "r" );
    char buffer[ BUFFER_SIZE ];
    char *last_token;
    char arr[100];
    int length;
    
   // int i;
    //for(i = 0; i<10; i++){
	//item_info[i].count = 0;
	//3}


    if( input_file == NULL ){

        fprintf( stderr, "Unable to open file %s\n", filename );

    }else{
	int i = 0;
        // Read each line into the buffer
        while( fgets(buffer, BUFFER_SIZE, input_file) != NULL ){
		record_count++;
            // Write the line to stdout
            //fputs( buffer, stdout );

            // Gets each token as a string and prints it
            last_token = strtok(buffer, delimiter_characters );
            
		//printf("\n%s",last_token);
            last_token = strtok( NULL, delimiter_characters );
            //printf("\n%s",last_token);
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
                //else
                	//arr[length - 1] = '\0';
                            
                add_count(arr, item_info);
                
                last_token = strtok( NULL, delimiter_characters );
            

        }
        }

        if( ferror(input_file) ){
            perror( "The following error occurred" );
        }

        fclose( input_file );
       
    	}
    	
    	}
    	
  void sort_the_transaction(struct item transaction_info[], struct item item_info[], const char *filename, const char *filename1){ 
    const char *delimiter_characters = ",";
    //const char *filename = "transaction.txt";
    FILE *input_file = fopen( filename, "r" );
    FILE *output_file = fopen(filename1, "w");
    if(output_file == NULL) printf("Error in creating a file");
    char buffer[ BUFFER_SIZE ];
    char *last_token;
    char arr[100];
    int length;
    int support = MIN_SUP;
    printf("\n The record count and support is %d  %d\n", record_count, support);

    if( input_file == NULL ){

        fprintf( stderr, "Unable to open file %s\n", filename );

    }else{
	
        // Read each line into the buffer
        while( fgets(buffer, BUFFER_SIZE, input_file) != NULL ){

            // Write the line to stdout
            //fputs( buffer, stdout );

            // Gets each token as a string and prints it
            last_token = strtok( buffer, delimiter_characters );
            last_token = strtok(NULL, delimiter_characters);
            while( last_token != NULL ){
                //printf( "%s\n", last_token);
                length = strlen(last_token);
                strcpy(arr, last_token);
                //printf("\n%d %s %s\n", length, arr, last_token);    
                if(arr[length - 1] == '\n'){
                	//printf("\nI have a new line %s \n", arr);
                	arr[length - 1] = '\0';
                	//printf("\n I am %s present_lemgth %d", arr, strlen(arr)) ;
                	           }
                //else
                	//arr[length - 1] = '\0';
                            
                int count = item_count(item_info, arr);
               // printf("\n item %s count is %d\n", arr, count);
                
                if(count>=support)
                
                
			add_transaction(arr, count, transaction_info);
                
                last_token = strtok( NULL, delimiter_characters );
            

        }
        
     // int n = sizeof(transaction_info)/sizeof(transaction_info[0]);
      //printf("\n transaction size %d\n", n);
        int tot = 0;
        while (transaction_info[tot].count != 0) ++tot;
        printf(" ==== %d\n", tot);
    	bubbleSort(transaction_info, tot);
    	int flag = 0;
    	for(int i = 0; transaction_info[i].count!=0; i++){
		if(strcmp(transaction_info[i].name, "")!=0){
    			fprintf(output_file, "%s,", transaction_info[i].name);
    			flag = 1;
    			}
  		}
  	if(flag == 1)
  		fprintf(output_file, "\n");
  	  	
  	for(int i =0; i<tot; i++)
  		transaction_info[i].count = 0;
  	}

        if( ferror(input_file) ){
            perror( "The following error occurred" );
        }

        fclose( input_file );
        fclose(output_file);
       
    	}
    	
    	
     }
    
