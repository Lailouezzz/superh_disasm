#include <iostream>
#include <string>
#include <spiritx3.hpp>
#include <DisasmTable.hpp>
#include <Instruction.hpp>
#include <utils.hpp>
#include <version.hpp>


int main()
{
#ifndef NDEBUG
    std::cout << "debug" << std::endl;
#endif
    std::cout << "version : " << VERSION_STR << std::endl;


    SHD::DisasmTable table;
    if(table.readFromFile("asm_sh3.txt"))
    {
        std::cout << "file asm loaded" << std::endl;
    }
    else
    {
        return -1;
    }
    
    SHD::InstructionDescriptor instnDesc = table.matchInstn(0b0010100001001001);
    SHD::Instruction instn(instnDesc, 0b0010100001001001);
    std::cout << instn.toString() << std::endl;

    return 0;
}
