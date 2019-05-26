CPUScheduler:	CPUScheduler.o Heap.o
	g++ -std=c++11 -Wall -g -o CPUScheduler CPUScheduler.o Heap.o

CPUScheduler.o:	CPUScheduler.cpp Heap.cpp PCB.h
	g++ -std=c++11 -Wall -g -c CPUScheduler.cpp

Heap.o:	Heap.cpp Heap.h
	g++ -std=c++11 -Wall -g -c Heap.cpp

clean:	
	rm -f *.o CPUScheduler
