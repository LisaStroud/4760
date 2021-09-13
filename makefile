
driver: driver.o loglib.o
	gcc -o $@ driver.o loglib.o
driver.o: driver.c log.h
	gcc -c driver.c

loglib.o: loglib.c log.h
	gcc -c loglib.c

clean:
	rm **.o ouput 


