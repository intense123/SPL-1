//#define BUFFER_SIZE 1024
#ifndef ITEM_H
#define ITEM_H


#define MIN_SUP 100
#define MIN_CONF 0.2

struct item{
	char name[100];
	int count;
};
int record_count=0;
struct item item_info[10000];
 struct item transaction_info[10000];
#endif
