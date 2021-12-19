sejours: sejours.o Trajet.o TC.o TS.o Catalogue.o ListeTrajet.o MaillonTrajet.o
	g++ -o sejours sejours.o Trajet.o TC.o TS.o Catalogue.o ListeTrajet.o MaillonTrajet.o -g 
Trajet.o: Trajet.cpp
	g++ -o Trajet.o -c Trajet.cpp -g -ansi -pedantic -Wall -std=c++11
TS.o: TS.cpp
	g++ -o TS.o -c TS.cpp -g -ansi -pedantic -Wall -std=c++11
TC.o: TC.cpp
	g++ -o TC.o -c TC.cpp -g -ansi -pedantic -Wall -std=c++11
ListeTrajet.o: ListeTrajet.cpp
	g++ -o ListeTrajet.o -c ListeTrajet.cpp -g -ansi -pedantic -Wall -std=c++11
MaillonTrajet.o: MaillonTrajet.cpp
	g++ -o MaillonTrajet.o -c MaillonTrajet.cpp -g -ansi -pedantic -Wall -std=c++11
Catalogue.o: Catalogue.cpp
	g++ -o Catalogue.o -c Catalogue.cpp -g -ansi -pedantic -Wall -std=c++11
sejours.o: sejours.cpp
	g++ -o sejours.o -c sejours.cpp -g -ansi -pedantic -Wall -std=c++11