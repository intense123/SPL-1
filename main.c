#include <stdio.h>
#include <string.h>
#include "item_struct.h"
#include "test_token.h"
#include "fp_tree_build.h"
//struct item item_info[1000];
 //  struct item transaction_info[1000];

int main( )
{
 
   //struct item item_info[1000];
   //struct item transaction_info[1000];
  // text_to_token(item_info);
   int i;
    for(i = 0; i<1000; i++){
	item_info[i].count = 0;
	transaction_info[i].count = 0;
	}
   const char *filename = "groc.txt";
   const char *filename1 = "sorted_transaction.txt";
   const char *output_filename = "frequent_itemsets.txt";
   const char *association_filename = "association_rules.txt";
   text_to_token(item_info, filename);
   
    
    int size = sizeof(item_info)/sizeof(item_info[0]);
    bubbleSort(item_info, size);
    printf("\n \t Output of Frequncy count\n");
    printf("\n item\t\t\t\t\t count \n");

    for (int i = 0; i<size; i++)
	{
		if(item_info[i].count >= MIN_SUP){
			if(strcmp(item_info[i].name, " ") != 0)
		    	printf("%-40s  %d\n", item_info[i].name, item_info[i].count);
		}
    }
    //Sort the frequency table in descending order
    bubbleSort(item_info, size);
    	
   // printf("\nThe content of structure\n");
     //   for(i = 0; item_info[i].count!=0; i++){
       // 	printf("\n%s %d\n", item_info[i].name, item_info[i].count);

    	//	}
    sort_the_transaction(transaction_info, item_info, filename, filename1);
    // printf("YO\n");
    build_tree(filename1);
    print_header();
    header_node *temp;
    temp = start;
    while (temp->next1 != NULL)
    		temp = temp->next1;
    printf("\n ************* \n");		
    while(temp!=NULL){
    	printf("\n");
    	if(strcmp(temp->item, "") != 0)
    	print_path(temp);
    	printf("\n");
    	temp = temp->prev1;
    	}
    printf("\n ************ \n");
    generate_fp(output_filename);
    generate_associations(association_filename);
    return 0;
}
