#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "OpcodeTable.h"
#include "RegisterTable.h"
#include <sstream>

/* This class provides an internal representation for a MIPS assembly instruction.
 * Any of the fields can be queried.  Additionally, the class stores a 32 bit binary
 * encoding of the MIPS instruction.
 */
class Instruction {

 public:

  // Creates a default instruction that has the opcode UNDEFINED
  Instruction();

  // Constructs new instruction and initializes fields according to arguments:
  // opcode, first source register, second source register, destination
  // register, and immediate value
  Instruction(Opcode op, string op_name, Register rs, Register rt, Register rd, int imm);

  // Destructor for the instruction
  ~Instruction() {};

  // Allows you to set all the fields of the Instruction:
  // opcode, first source register, second source register, destination
  // register, and immediate value
  void setValues(Opcode op, string op_name, Register rs, Register rt, Register rd, int imm);

  // This function sets a binary string as the encoding of 
  // an instruction
  void setEncoding(string encoding) { myEncoding = encoding;}

  // Return instruction's encoding
  string getEncoding() { return myEncoding; }

  // Returns the Opcode of the instruction
  Opcode getOpcode()   { return myOpcode; }

  // Return's the opcode name as a string
  string getOpcodeName()  { return myOpcodeName; }

  // Returns the register used as the first source operand
  Register getRS()     { return myRS; };

  // Returns the register used as the second source operand
  Register getRT()     { return myRT; };

  // Returns the register used as the destination register
  Register getRD()     { return myRD; };

  // Returns the value of the instruction's immediate field
  int getImmediate()   { return myImmediate; };

  // Returns a string which represents all of the fields 
  string getString();

  // Set the string representing the instruction's assembly
  void setAssembly(string s) { myAssembly = s;};

  // Return the string representing the instruction's assembly
  string getAssembly() { return myAssembly; };

 private:

  Opcode myOpcode;
  string myOpcodeName;

  Register myRS;
  Register myRT;
  Register myRD;
  int myImmediate;

  string myAssembly; //The string containing the MIPS instruction
  string myEncoding; //This string containing the Encoded instruction

};

#endif
