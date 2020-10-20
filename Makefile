# build an executable named roster
all:
	g++ -g -o roster roster.cpp student.cpp networkStudent.cpp securityStudent.cpp softwareStudent.cpp

clean:
	rm roster