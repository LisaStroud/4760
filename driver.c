//Author: Lisa Stroud
//Date: 9/13/21
//Sources:
//https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/ 
//https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html :help with getopt
#include "driver.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
	int c;
	int sec;
	int *secValue = NULL;

	while((c = getopt(argc, argv, "ht:")) != -1)
	{
		switch(c)
		{
		   case 'h':
			printf("\nHelp Message:\n-h: Displays help message\n-t: Create log messages to save at a certain rate\n");
			exit(1);
			break;
		   case 't':
			sec = optarg;
			addmsg('E',"Error");
			savelog("messages.log");
			sleep(sec);
			addmsg('F',"Fatal");
			savelog("messages.log");
			
			// read from file to get log messages
			// save to messages.log at certain time rate
			break;
		   case '?':
			perror
			break;
		   default:
			fprintf(stderr, "getopt");
		}
	}

//	void do_t (void)
//	{
	//	data_t log1, log2, log3, log4;
	//	log1.type = 'W';
	//	log2.type = 'E';
	//	log3.type = 'F';
	//	log4.type = 'I';

	//	log1.string = "WARNING";
	//	log2.string ="ERROR";
	//	log3.string ="FATAL";
	//	log4.string ="INFO";

	//	addmsg(log1);
	//	addmsg('E',"ERROR!");
		//add some sort of time thing here to make it wait
	//	savelog(messages.log);
	//	getlog();
//	}
	return 0;
}


