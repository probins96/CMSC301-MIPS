#include "BinaryParser.h"
#include <iostream>

using namespace std;

/* This file reads in a filename which contains 32 bit MIPS instruction binary encodings
 * If the file is correct syntactically, each instruction in the file
 * will be translated from its 32 bit MIPS binary encoding and printed
 * to stdout, one per line.
 */

int main(int argc, char *argv[]) {
  BinaryParser *parser;

  if (argc < 2) {
    cerr << "Need to specify an encoded file to translate."<< endl;
    exit(1);
  }

  parser = new BinaryParser(argv[1]);

  if (parser->isFormatCorrect() == false) {
    cerr << "Format of input file is incorrect." << endl;
    exit(1);
  }

  Instruction i;

  // Iterate through instructions, printing each encoding.
  i = parser->getNextInstruction();
  while (i.getOpcode() != UNDEFINED) {
    cout << i.getEncoding() << "\t" << i.getAssembly() << endl;
    i = parser->getNextInstruction();
  }
  
  delete parser;
}