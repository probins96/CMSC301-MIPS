# makefile
# use to compile and test the assembler ASM for the STACK computer and
# its various components

DEBUG_FLAG= -DDEBUG -g -Wall
CFLAGS=-DDEBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CFLAGS) -c $<


Binary: Binary.o Instruction.o OpcodeTable.o RegisterTable.o BinaryParser.o
	g++ -o Binary Binary.o OpcodeTable.o BinaryParser.o RegisterTable.o Instruction.o

BinaryParser.o: BinaryParser.h OpcodeTable.h RegisterTable.h Instruction.h 

Instruction.o: OpcodeTable.h RegisterTable.h Instruction.h 

OpcodeTable.o: OpcodeTable.h 

RegisterTable.o: RegisterTable.h  

clean:
	/bin/rm -f Binary *.o core