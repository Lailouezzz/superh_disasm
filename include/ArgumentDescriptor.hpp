#ifndef H_ARGUMENTDESCRIPTOR
#define H_ARGUMENTDESCRIPTOR
#include <string>
#include <cstdint>


namespace SHD
{

    enum class arg_type
    {
        IMM,        // #imm
        RN,         // rn
        RM,         // rm
        JUMP8,      // jump8
        JUMP12,     // jump12
        PCDISP,     // @(disp, pc)
        AT_RN,      // @rn
        AT_RM,      // @rm
        AT_RNP,     // @rn+
        AT_RMP,     // @rm+
        AT_MRN,     // @-rn
        AT_DRN,     // @(disp, rn)
        AT_DRM,     // @(disp, rm)
        AT_R0RN,    // @(r0, rn)
        AT_R0RM,    // @(r0, rm)
        AT_DGBR,    // @(disp, gbr)
        LITERAL,    // literal string
        NONE
    }; /// enum class arg_type


    struct ArgumentDescriptor
    {
        
        arg_type type;
        std::string arg_literal;

        ArgumentDescriptor();

    }; /// struct ArgumentDescriptor
    

} /// namespace SHD


#endif /// ifndef H_ARGUMENTDESCRIPTOR
