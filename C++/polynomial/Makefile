PolynomialDemo:	PolynomialDemo.o Polynomial.o
	g++ -std=c++11 -Wall -g -o PolynomialDemo PolynomialDemo.o Polynomial.o

PolynomialDemo.o:	PolynomialDemo.cpp Polynomial.h
	g++ -std=c++11 -Wall -g -c PolynomialDemo.cpp

Polynomial.o:	Polynomial.cpp Polynomial.h
	g++ -std=c++11 -Wall -g -c Polynomial.cpp

clean:	
	rm -f *.o PolynomialDemo
