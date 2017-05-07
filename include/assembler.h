//
// Created by Ahmed Yakout on 5/1/17.
//

/**
 *   A S S U M P T I O N S
 *
 *   - any hex value must be in the form 0x[hex value]
 *   - empty line are not allowed, all lines must be a valid statement or a comment.
 *   - we don't check for the undefined label   
 *   - pass one and two stop reading after finding end directive and will ignore any following instructions.
 *   so if another end directive or any instruction is found later no error will be thrown.
 *   - there is no LC for invalid instructions
 *   - if there is errors in pass 1 there will be only intermediate file and the obj file will be incorrect.
 *
 */


/**
 *  Features
 *  we handled array    word 1,2,3
 *  
 */

/**
 *  TODO
 *  test *
 *  end operand is optional so we sould handle that
 *  should not allw using array in invalid mnemonic e.g  byte 1,2,3
 *  handling array of word in pass 2 and object writer
 */

#ifndef SIC_XE_ASSEMBLER_ASSEMBLER_H
#define SIC_XE_ASSEMBLER_ASSEMBLER_H



#include <iostream>
#include <iomanip>
#include <sstream>

class sic_assembler {
public:
    static const int INSTRUCTION_LENGTH = 3;
    static int location_counter;
    static int location_counter_old; // phase 2
    static int starting_address;
    static int program_length;
    static std::string program_name;
    static const std::string directives[];
    static const int TAB_WIDTH = 8;

    static int hex_to_int(std::string hex);
    static std::string decimal_to_hex(int decimal, int width = -1);
    static std::string to_lower(std::string str);
    static std::string to_upper(std::string str);
    static std::string trim(std::string str);
    static bool is_directive(std::string);
    static std::string remove_tabs(std::string str);
};

#endif //SIC_XE_ASSEMBLER_ASSEMBLER_H
