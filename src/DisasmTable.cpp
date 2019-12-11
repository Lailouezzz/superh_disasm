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
                m_instns.push_back(newDesc);

        }

        return true;
    }
    
} /// namespace SHD
