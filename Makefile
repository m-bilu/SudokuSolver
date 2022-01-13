CXX=g++
CXXFLAGS= -g -std=c++14 -Wall -Wextra -MMD # FOR .D FILES
OBJECTS= main.o sudoku.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=solver.exe

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}

