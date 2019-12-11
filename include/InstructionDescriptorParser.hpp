#ifndef H_INSTRUCTION_DESCRIPTOR_PARSER
#define H_INSTRUCTION_DESCRIPTOR_PARSER
#include <cstdint>
#include <string>
#include <iostream>
#include <spiritx3.hpp>
#include "InstructionDescriptor.hpp"


namespace SHD
{

    namespace Parser
    {

        using spirit::eps;
        using spirit::eoi;
        using spirit::repeat;
        using spirit::_val;
        using spirit::_attr;
        using spirit::space;
        using spirit::char_;


        // TABLE FOR TRANSLATE char[] TO arg_type

        struct arg_type_table_ : spirit::symbols<arg_type>
        {
            arg_type_table_()
            {
                add ("#imm", arg_type::IMM)
                    ("rn", arg_type::RN)
                    ("rm", arg_type::RM)
                    ("jump8", arg_type::JUMP8)
                    ("jump12", arg_type::JUMP12)
                    ("pcdisp", arg_type::PCDISP)
                    ("@rn", arg_type::AT_RN)
                    ("@rm", arg_type::AT_RM)
                    ("@rn+", arg_type::AT_RNP)
                    ("@rm+", arg_type::AT_RMP)
                    ("@-rn", arg_type::AT_MRN)
                    ("@(disp, rn)", arg_type::AT_DRN)
                    ("@(disp, rm)", arg_type::AT_DRM)
                    ("@(r0, rn)", arg_type::AT_R0RN)
                    ("@(r0, rm)", arg_type::AT_R0RM)
                    ("@(disp, gbr)", arg_type::AT_DGBR);
            }
        } const arg_type_table;


        // ALL LAMBDA FOR PARSING

        auto reset = [&](auto& ctx) 
        {           // defaut
            _val(ctx).args.clear();
        };
        auto set_opcode = [&](auto& ctx)
        { 
            InstructionDescriptor& buf = _val(ctx); 
            std::string str_opcode = _attr(ctx);

            uint16_t selected_bit = 1;
            uint8_t pos = 0;
            while(pos < 16)
            {
                char sel_char = str_opcode[15-pos];
                switch (sel_char)
                {
                case '0':
                    buf.opcode_mask |= selected_bit;
                    break;
                case '1':
                    buf.opcode_def |= selected_bit;
                    buf.opcode_mask |= selected_bit;
                    break;
                case 'n':
                    buf.n_mask |= selected_bit;
                    break;
                case 'm':
                    buf.m_mask |= selected_bit;
                    break;
                case 'd':
                    buf.d_mask |= selected_bit;
                    break;
                case 'i':
                    buf.i_mask |= selected_bit;
                    break;
                default:
                    break;
                }

                selected_bit <<= 1;
                pos++;
            }
            if(buf.n_mask != 0)
            {
                buf.n_pos = posLeastBit(buf.n_mask);
            }
            if(buf.m_mask != 0)
            {
                buf.m_pos = posLeastBit(buf.m_mask);
            }
            if(buf.d_mask != 0)
            {
                buf.d_pos = posLeastBit(buf.d_mask);
            }
            if(buf.i_mask != 0)
            {
                buf.i_pos = posLeastBit(buf.i_mask);
            }
        };
        auto set_mnemonic = [&](auto& ctx) { _val(ctx).mnemonic_name = _attr(ctx); };
        auto set_arg1_type = [&](auto& ctx) 
        {
            ArgumentDescriptor tmp;
            tmp.type = _attr(ctx);
            _val(ctx).args.push_back(tmp);
        };
        auto set_arg1_literal = [&](auto& ctx)
        { 
            ArgumentDescriptor tmp;
            tmp.type = arg_type::LITERAL;
            tmp.arg_literal = _attr(ctx);
            _val(ctx).args.push_back(tmp);
        };
        auto set_arg2_type = [&](auto& ctx) 
        {
            ArgumentDescriptor tmp;
            tmp.type = _attr(ctx);
            _val(ctx).args.push_back(tmp);
        };
        auto set_arg2_literal = [&](auto& ctx)
        {
            ArgumentDescriptor tmp;
            tmp.type = arg_type::LITERAL;
            tmp.arg_literal = _attr(ctx);
            _val(ctx).args.push_back(tmp);
        };
        
        // RULE

        spirit::rule<class InstructionDescriptorParser, SHD::InstructionDescriptor> 
                const InstructionDescriptorParser = "InstructionDescriptorParser";
        
        
        // ALL GRAMMAR

        auto const opcode_g = repeat(16)[char_("01nmdi")];
        auto const mnemonic_g = +char_("a-z0-9./");
        auto const arg_literal = +char_("a-z0-9_");
        auto const arg1_g = 
                            (arg_type_table  [set_arg1_type] | 
                            arg_literal [set_arg1_literal])
                            ;
        auto const arg2_g = 
                            (arg_type_table  [set_arg2_type] | 
                            arg_literal [set_arg2_literal])
                            ;

        auto const InstructionDescriptorParser_def =
            eps                 [reset]
            >>
            (
                opcode_g        [set_opcode] >> +space
            >>  mnemonic_g      [set_mnemonic]
            >>  ((
                    +space >> arg1_g
                    >>  ((char_(',') >> +space >> arg2_g) | eoi)
                ) | eoi)

            )
        ;

        BOOST_SPIRIT_DEFINE(InstructionDescriptorParser);

    } /// namespace InstructionDescriptorParser

} /// namespace SHD


#endif /// #ifndef H_INSTRUCTION_DESCRIPTOR_PARSER
