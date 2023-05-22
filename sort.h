#include "item_struct.h"


void bubbleSort(struct item arr[], int n) {
    int i, j;
   // n = sizeof(arr)/sizeof(arr[0]);
    struct item temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i].count < arr[j].count) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
           else if (arr[i].count == arr[j].count){
           		if (strcmp(arr[i].name, arr[j].name) < 0) {
                    		temp = arr[i];
                    		arr[i] = arr[j];
                    		arr[j] = temp;
                    		}
                    	}
                  }
               }
          }
                
       
