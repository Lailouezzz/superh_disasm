#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <spiritx3.hpp>
#include <utils.hpp>
#include "InstructionDescriptorParser.hpp"
#include "InstructionDescriptor.hpp"
#include "DisasmTable.hpp"


namespace SHD
{

    bool DisasmTable::readFromFile(std::filesystem::path const& filePath)
    {

        std::ifstream file(filePath);

        if(!file)
            return false;

        for(std::string line; std::getline(file, line); )
        {

            InstructionDescriptor newDesc;

            bool ret = spirit::parse(     line.begin(),
                                          line.end(),
                                          Parser::InstructionDescriptorParser,
                                          newDesc
                                          );
            
            if(ret)
                m_instnsDesc.push_back(newDesc);

        }

        return true;
    }
    
    InstructionDescriptor DisasmTable::matchInstn(uint16_t const& opcode) const
    {

        for(auto const& idesc : m_instnsDesc)
        {
            if((opcode & idesc.opcode_mask) == (idesc.opcode_def & idesc.opcode_mask)) // match
                return idesc;
        }

        // TODO : handle exception
        return InstructionDescriptor();

    }

} /// namespace SHD
