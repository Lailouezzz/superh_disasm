#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <utils.hpp>
#include "Instruction.hpp"
#include "ArgumentDescriptor.hpp"
#include "Argument.hpp"


namespace SHD
{

    Argument::Argument(std::shared_ptr<Instruction> instn, ArgumentDescriptor const& argDesc) :
        m_instn(instn),
        m_argDesc(argDesc)
    { }

    std::string Argument::toString()
    {
        switch (m_argDesc.type)
        {
        case arg_type::IMM:
            return "0x" + SHD::toHexStr(SHD::littleToBigEdian(m_instn->getImm()));
            break;
        case arg_type::RN:
            return "r" + std::to_string(m_instn->getN());
            break;
        case arg_type::RM:
            return "r" + std::to_string(m_instn->getM());
            break;
        case arg_type::JUMP8:
            return SHD::toHexStr(SHD::littleToBigEdian(m_instn->getDisp()));
            break;
        case arg_type::JUMP12:
            return SHD::toHexStr(SHD::littleToBigEdian(m_instn->getDisp()));
            break;
        case arg_type::PCDISP:
            return "@(0x" + SHD::toHexStr(SHD::littleToBigEdian(m_instn->getDisp())) + ", pc)";
            break;
        case arg_type::AT_RN:
            return "@r" + std::to_string(m_instn->getN());
            break;
        case arg_type::AT_RM:
            return "@r" + std::to_string(m_instn->getM());
            break;
        case arg_type::AT_RNP:
            return "@r" + std::to_string(m_instn->getN()) + "+";
            break;
        case arg_type::AT_RMP:
            return "@r" + std::to_string(m_instn->getM()) + "+";
            break;
        case arg_type::AT_MRN:
            return "@-r" + std::to_string(m_instn->getN());
            break;
        case arg_type::AT_DRN:
            return "@(0x" + SHD::toHexStr(SHD::littleToBigEdian(m_instn->getDisp())) + ", r" + std::to_string(m_instn->getN()) + ")";
            break;
        case arg_type::AT_DRM:
            return "@(0x" + SHD::toHexStr(SHD::littleToBigEdian(m_instn->getDisp())) + ", r" + std::to_string(m_instn->getM()) + ")";
            break;
        case arg_type::AT_R0RN:
            return "@(r0, r" + std::to_string(m_instn->getN()) + ")";
            break;
        case arg_type::AT_R0RM:
            return "@(r0, r" + std::to_string(m_instn->getM()) + ")";
            break;
        case arg_type::AT_DGBR:
            return "@(0x" + SHD::toHexStr(SHD::littleToBigEdian(m_instn->getDisp())) + ", gbr)";
            break;
        case arg_type::LITERAL:
            return m_argDesc.arg_literal;
            break;
        case arg_type::NONE:
            return "NONE";
            break;
        default:
            return "UNK";
            break;
        }
    }

} /// namespace SHD
