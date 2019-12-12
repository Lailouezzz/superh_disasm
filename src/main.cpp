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
    if(table.readFromFile("asm_sh3.txt") && table.readFromFile("asm_sh4.txt"))
    {
        std::cout << "file asm loaded" << std::endl;
    }
    else
    {
        return -1;
    }

    std::cout << SHD::toHexStr(SHD::littleToBigEdian(static_cast<int32_t>(2156))) << std::endl;
    
    SHD::InstructionDescriptor instnDesc = table.matchInstn(0b1000000001010010);
    SHD::Instruction instn(instnDesc, 0b1000000001010010);
    std::cout << instn.toString() << std::endl;

    std::ifstream file("OS_205_E.bin", std::ios::in | std::ios::binary);
    file.seekg(0x10080);

    if(!file)
    {
        return 0;
    }

    uint16_t buf[50];
    file.read(reinterpret_cast<char*>(buf), sizeof(buf));
    for(size_t i = 0; i < sizeof(buf) / 2; i++)
    {
        uint16_t opcode = buf[i];
        SHD::InstructionDescriptor ID = table.matchInstn(SHD::littleToBigEdian(opcode));
        SHD::Instruction I(ID, SHD::littleToBigEdian(opcode));
        std::cout << SHD::toHexStr(opcode) << " : " << I.toString() << std::endl;
    }

    return 0;
}
