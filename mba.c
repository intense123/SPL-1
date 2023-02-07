#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_table {
  char *key;
  int value;
  int replace_value;
};

int hash_string(char *str) {
  int hash = 0;
  for (int i = 0; i < strlen(str); i++) {
    hash= hash + str[i];
  }
  //printf(" %d",hash);
  return hash;
}


int main() {
    FILE *fp, *fp1;
    char line[1000];
    int  count[20], index;
    int constant[17]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int input_hash = 0;
    struct hash_table table[] = {
    {"egg", hash_string("egg"),1},
    {"bread", hash_string("bread"),2},
    {"potato", hash_string("potato"),3},
    {"banana", hash_string("banana"),4},
    {"garlic", hash_string("garlic"),5},
    {"cardamom", hash_string("cardamom"),6},
    {"teabag", hash_string("teabag"),7},
    {"pineapple", hash_string("pineapple"),8},
    {"broccoli", hash_string("broccoli"),9},
    {"coffee", hash_string("coffee"),10},
    {"milk", hash_string("milk"),11},
    {"guava", hash_string("guava"),12},
    {"chicken", hash_string("chicken"),13},
    {"kite", hash_string("kite"),14},
    {"sprite", hash_string("sprite"),15},
    {"chili", hash_string("chili"),16},
    {"nut", hash_string("nut"),17}
    };
    
    
    int table_size = sizeof(table) / sizeof(table[0]);
   
     
    for(int i = 0; i<20; i++){
        count[i] = 0;
    }
    fp = fopen("transaction.txt", "r");
    if(fp == NULL)
        return 1;
    
    fp1 = fopen("mapped.txt", "a");
    if(fp1 == NULL)
        return 1;
        
   
    int flag=0;
    while(fgets(line, 1000, fp)){
        printf("\n%s", line);
        char *token = strtok(line, ",");
        //printf("%s\n", token);
         while (token != NULL) {
             printf("\n%s", token);
             if (flag == 0){
            
                input_hash = hash_string(token);
                flag = 1;
             }
             else{
                 input_hash=hash_string(token)-32;
             }
                
            
            //printf("\n %s %d",token, input_hash);
            //printf("\n%d", input_hash);
            //printf("%s\n", token);
           // printf("%d", hash_string(token));
            for (int i = 0; i < table_size; i++) {
                //printf("\n %d", strcmp(token, table[i].key));
               //if (!strcmp(table[i].key,token)) { 
                  //fprintf(fp1, "%d, " , table[i].replace_value);
                    //break;
                //}
                //&&
               // printf("\n %d  %d", table[i].value, input_hash);
                if(table[i].value == input_hash){
                printf("\n %s %d %d", token, table[i].value, table[i].replace_value);
                fprintf(fp1, "%d, " , table[i].replace_value);
                break;
                   
               
                    
                }
                
            }
            
            input_hash = 0;
           
            token = strtok(NULL, ",");
            
            //printf("\n%s", token);
        }
        fprintf(fp1, "\n");
    }
    fclose(fp);
    fclose(fp1);
    
    /*for(int i = 0; i<20; i++){
        printf("\n%d", count[i]);
    }*/
    
    
    fp = fopen("mapped.txt", "r");
    if(fp == NULL)
        return 1;
    
    while(fgets(line, 1000, fp)){
        char *token = strtok(line, ",");
         while (token != NULL) {
            
            //printf("%s\n", token);
            index = atoi(token);
            count[index] =count[index]+1;
            
            token = strtok(NULL, ",");
        }
    }
    fclose(fp);
    
    for(int i = 1; i<20; i++){
        printf("\n%d", count[i]);
    }
    
    return 0;
}