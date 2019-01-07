#include "Instruction.h"

// Creates a default instruction that has the opcode UNDEFINED
Instruction::Instruction() {
  myOpcode = UNDEFINED;
  myRS = myRT = myRD = NumRegisters;
}

// Constructs new instruction and initializes fields according to arguments:
// opcode, first source register, second source register, destination
// register, and immediate value
Instruction::Instruction(Opcode op, string op_name, Register rs, Register rt, Register rd, int imm) {
  setValues(op, op_name, rs, rt, rd, imm);
}

// Allows you to set all the fields of the Instruction:
// opcode, first source register, second source register, destination
// register, and immediate value
void Instruction::setValues(Opcode op, string op_name, Register rs, Register rt, Register rd, int imm) {
  myOpcode = op;
  myOpcodeName = op_name;
  if (op < 0 || op >= UNDEFINED)
    myOpcode = UNDEFINED;

  myRS = rs;
  myRT = rt;
  myRD = rd;
  myImmediate = imm;
}

// Returns a string which represents all of the fields 
string Instruction::getString() {
  stringstream s ;
  s << "OP: \t" << myOpcode << "\t" << "RD: " << myRD << "\t" << 
    "RS: " << myRS << "\t" << "RT: " << "\t" << myRT << "\t" <<
    "Imm: " << myImmediate;
  
  return s.str();
}