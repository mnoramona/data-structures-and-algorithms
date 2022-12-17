CC=gcc
.PHONY = clean run memcheck
 
all: build
 
list.o: list.c 
	$(CC) --std=c11 -g -c $<

task2_1.o: task2_1.c
	$(CC) --std=c11 -g -c $<
	
task2_2.o: task2_2.c
	$(CC) --std=c11 -g -c $<

task2_3.o: task2_3.c
	$(CC) --std=c11 -g -c $<

task2_4.o: task2_4.c
	$(CC) --std=c11 -g -c $<

task2_5.o: task2_5.c
	$(CC) --std=c11 -g -c $<

main.o: main.c
	$(CC) --std=c11 -g -c $<
 
build: list.o task2_1.o task2_2.o task2_3.o task2_4.o task2_5.o main.o
	$(CC) $^ -o tema1 -lm -g
 
clean:
	rm -rvf *.o tema1