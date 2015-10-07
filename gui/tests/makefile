all: guiTest.o runall.o unity.o unity_fixture.o

.PHONY: guiTest.o runall.o unity.o unity_fixture.o

guiTest.o:
	gcc -c guiTest.c -o ../build/logicTest.o

runall.o:
	gcc -c runall.c -o ../build/runall.o

unity.o:
	gcc -c ../../unity/unity.c -o ../build/unity.o

unity_fixture.o:
	gcc -c ../../unity/unity_fixture.c -o ../build/unity_fixture.o
