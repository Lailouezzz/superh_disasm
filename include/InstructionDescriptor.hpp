#ifndef H_INSTRUCTIONDESCRIPTOR
#define H_INSTRUCTIONDESCRIPTOR
#include <cstdint>
#include <string>


namespace SHD
{

    struct InstructionDescriptor
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
            LITERAL,   // literal string
            NONE        // null arg
        }; /// enum class arg_type

        uint16_t opcode_def; // opcode_def & opcode_mask = opcode_def
        uint16_t opcode_mask; // 1 = constant ; 0 = arg

        uint8_t n_pos, m_pos, d_pos, i_pos; // arg position starting from the right ex : 011011101101nnnn n_pos = 0
                                            //                                           01101110mmmm1101 m_pos = 4
                                            //                                           if n isn't use n_pos = 16
        uint16_t n_mask, m_mask, d_mask, i_mask; // arg mask ex : if n isn't use n_mask = 0


        std::string mnemonic_name; // string mnemonic
        arg_type arg1_type, arg2_type; // type of argument
        std::string arg1_literal, arg2_literal; // literal arg if arg[number]_type == LITERAL


        InstructionDescriptor() noexcept;


        uint16_t getN(uint16_t const& opcode);    // return n as number
        uint16_t getM(uint16_t const& opcode);    // return m as number
        uint16_t getDisp(uint16_t const& opcode); // return disp as number
        uint16_t getImm(uint16_t const& opcode);  // return imm as number
        bool isUseN();      // true if n_mask != 0
        bool isUseM();      // true if m_mask != 0
        bool isUseDisp();   // true if d_mask != 0
        bool isUseImm();    // true if i_mask != 0

    }; /// struct instn_def

} /// namespace SHD


#endif /// #ifndef H_INSTRUCTIONDESCRIPTOR
