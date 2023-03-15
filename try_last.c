#include <stdio.h>
#include <string.h>
#include "item_struct.h"
#include "test_token.h"
#include "sort.h"

int main( )
{
 
   struct item item_info[10];
   struct item transaction_info[10];
  // text_to_token(item_info);
   int i;
    for(i = 0; i<10; i++){
	item_info[i].count = 0;
	transaction_info[i].count = 0;
	}
   const char *filename = "transaction.txt";
   text_to_token(item_info, filename);
   
    int size = sizeof(item_info)/sizeof(item_info[0]);
    bubbleSort(item_info, size);
    	
    printf("\nThe content of structure\n");
        for(i = 0; item_info[i].count!=0; i++){
        	printf("\n%s %d\n", item_info[i].name, item_info[i].count);

    		}
    sort_the_transaction(transaction_info, item_info, filename);
    	
    
    		
	return 0;
}
