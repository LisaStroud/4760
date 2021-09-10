
driver: driver.o loglib.o
	gcc -o driver driver.o loglib.o
driver.o: driver.c driver.h
	gcc -c driver.c

loglib.o: loglib.c log.h
	gcc -c loglib.c

clean:
	rm **.o ouput 


