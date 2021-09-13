//Author:Lisa Stroud
//Date: 9/13/21
//Sources:
//https://www.geeksforgeeks.org/time-h-localtime-function-in-c-with-examples/ :Time stamp
//https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/ :clearlog()
//https://www.geeksforgeeks.org/fprintf-in-c/ :Savelog, printing to messages.log
//https://www.learn-c.org/en/Linked_lists :getlog how to go through a list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

typedef struct list_struct {
	data_t item;
	struct list_struct *next;
} log_t;

static log_t *headptr = NULL;
static log_t *tailptr =NULL;

int addmsg(const char type, const char * msg) {
	//getting time
	struct tm* local;
	time_t t = time(NULL);
	local = localtime(&t);
	
	char *newLogString[55];
	//setting data structure 
	data_t log1;
	log1.type = type;
	log1.string = *newLogString;
	strcat(log1.string, msg);
	//log1.string = msg;
	
	log1.time = asctime(local);

	log_t *newlog;
	int nodesize;
	
	nodesize = sizeof(log_t) + strlen(log1.string) + 1;
	if ((newlog = (log_t *)(malloc(nodesize))) == NULL)
		return -1; //could not add node

	newlog->item.time = log1.time;
	newlog->item.string = (char *)newlog + sizeof(log_t);
	strcpy(newlog ->item.string, log1.string);
	newlog->item.type = log1.type;
	newlog->next =NULL;
	
	if(headptr == NULL)
		headptr = newlog;
	else
		tailptr->next = newlog;
	tailptr = newlog;
	
	return 0;
}

void clearlog(void){
	log_t *log = headptr;

	while (log !=NULL)
	{
		log = headptr->next;
		free(headptr);
		headptr = log;	
	}
	headptr = NULL;
}

char *getlog(void){
	
	char *logString;
	log_t *log = headptr;
	
	int i;
	logString = (char*)malloc(sizeof(char));
	//getting the size to make space for string
	while(log !=NULL)
	{
		i++;
		logString = (char*)realloc(logString, i * sizeof(char));
	}

	if(logString == NULL)
	{
		perror("driver: Error:");
		return NULL;
	}
	else
	{
		//copying into the list
		strcpy(logString, "");
		log_t *log = headptr;
		while( log != NULL)
		{
			strcat(logString, (log->item).string);
			strcat(logString, "\n"); //newline 
			log = log->next;
		}
		return logString;
	}
	
}

int savelog(char *filename){

	char *savingLog;//string to getlog and save it in
	FILE *file;
	file = fopen(filename, "a");

	if(!file)
	{
		perror("Driver: Error");
		return -1;
	}
	else
	{
		savingLog=getlog();
		if(savingLog == NULL)
		{
			perror("Driver: Error");
			return 0;
		}
		else
		{
			fprintf(file,"%s" ,savingLog);
				
		}
		fclose(file);
	}		
	return 0;
}
