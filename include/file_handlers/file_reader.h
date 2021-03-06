//
// Created by Marwan Tammam on 4/30/17.
//

#ifndef SIC_ASSEMBLER_FILE_READER_H__
#define SIC_ASSEMBLER_FILE_READER_H__

#include <fstream>
#include <string>
#include <regex>
#include <instruction.h>

class file_reader {
protected:
    std::ifstream source_file;
    std::string buffer;
    std::string line;

public:
    file_reader(std::string);
    virtual ~file_reader();

    bool has_next_instruction();
    bool is_comment_line();
    virtual instruction* get_next_instruction();
    std::string get_line();
    
};

#endif //SIC_ASSEMBLER_FILE_READER_H__
