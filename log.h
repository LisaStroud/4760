
#include <time.h>
#include <errno.h>

#ifndef LOG_H
#define LOG_H
typedef struct data_struct {
	time_t time;
	char type;
	char *string;
} data_t;

void perror(char const *s);

int addmsg(const char type, const char * msg);
void clearlog();
char *getlog();
int savelog(char *filename);
#endif
