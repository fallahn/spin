/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

SpIn - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#ifdef DEBUG_TOOLS
#include <I8080/I8080.hpp>

#include <cassert>

using namespace I8080;

void CPU::disassemble()
{
    std::function<void()> addOperand = [this]()
    {
        Dasm op;
        op.type = Dasm::Type::Operand;
        m_disassembly.push_back(op);
    };
    
    //this won't work for ROMs larger than space invaders, which ends at 0x1FFF
    for (auto i = 0; i < 0x2000; ++i)
    {
        m_disassembly.emplace_back();
        Dasm& dasm = m_disassembly.back();

        auto code = m_memory[i];
        switch (code)
        {
        case 0: dasm.mnem = "NOP"; break;
        case 0x1:
        {
            dasm.mnem = "LXIB";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x02: dasm.mnem = "STAXB"; break;
        case 0x03: dasm.mnem = "INXB"; break;
        case 0x04: dasm.mnem = "INRB"; break;
        case 0x05: dasm.mnem = "DCRB"; break;
        case 0x06:
        {
            dasm.mnem = "MVIB";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x07: dasm.mnem = "RLC"; break;
        case 0x08: dasm.mnem = "NIL"; break;
        case 0x09: dasm.mnem = "DADB"; break;
        case 0x0A: dasm.mnem = "LDAXB"; break;
        case 0x0B: dasm.mnem = "DCXB"; break;
        case 0x0C: dasm.mnem = "INRC"; break;
        case 0x0D: dasm.mnem = "DCRC"; break;
        case 0x0E:
        {
            dasm.mnem = "MVIC";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x0F: dasm.mnem = "RRC"; break;
            //
        case 0x10: dasm.mnem = "NIL"; break;
        case 0x11:
        {
            dasm.mnem = "LXID";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x12: dasm.mnem = "STAXD"; break;
        case 0x13: dasm.mnem = "INXD"; break;
        case 0x14: dasm.mnem = "INRD"; break;
        case 0x15: dasm.mnem = "DCRD"; break;
        case 0x16:
        {
            dasm.mnem = "MVID";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x17: dasm.mnem = "RAL"; break;
        case 0x18: dasm.mnem = "NIL"; break;
        case 0x19: dasm.mnem = "DADD"; break;
        case 0x1A: dasm.mnem = "LDAXD"; break;
        case 0x1B: dasm.mnem = "DCXD"; break;
        case 0x1C: dasm.mnem = "INRE"; break;
        case 0x1D: dasm.mnem = "DCRE"; break;
        case 0x1E:
        {
            dasm.mnem = "MVIE";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x1F: dasm.mnem = "RAR"; break;
            //
        case 0x20: dasm.mnem = "NIL"; break;
        case 0x21: 
        {
            dasm.mnem = "LXIH";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x22: 
        {
            dasm.mnem = "SHLD";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x23: dasm.mnem = "INXH"; break;
        case 0x24: dasm.mnem = "INRH"; break;
        case 0x25: dasm.mnem = "DCRH"; break;
        case 0x26:
        {
            dasm.mnem = "MVIH";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x27: dasm.mnem = "DAA"; break;
        case 0x28: dasm.mnem = "NIL"; break;
        case 0x29: dasm.mnem = "DADH"; break;
        case 0x2A:
        {
            dasm.mnem = "LHLD";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x2B: dasm.mnem = "DCXH"; break;
        case 0x2C: dasm.mnem = "INRL"; break;
        case 0x2D: dasm.mnem = "DCRL"; break;
        case 0x2E:
        {
            dasm.mnem = "MVIL";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x2F: dasm.mnem = "CMA"; break;
            //
        case 0x30: dasm.mnem = "NIL"; break;
        case 0x31:
        {
            dasm.mnem = "LXISP";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x32:
        {
            dasm.mnem = "STA";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x33: dasm.mnem = "INXSP"; break;
        case 0x34: dasm.mnem = "INRM"; break;
        case 0x35: dasm.mnem = "DCRM"; break;
        case 0x36: 
        {
            dasm.mnem = "MVIM";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x37: dasm.mnem = "STC"; break;
        case 0x38: dasm.mnem = "NIL"; break;
        case 0x39: dasm.mnem = "DADSP"; break;
        case 0x3A:
        {
            dasm.mnem = "LDA";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0x3B: dasm.mnem = "DCXSP"; break;
        case 0x3C: dasm.mnem = "INRA"; break;
        case 0x3D: dasm.mnem = "DCRA"; break;
        case 0x3E:
        {
            dasm.mnem = "MVIA";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0x3F: dasm.mnem = "CMC"; break;
            //
        case 0x40: dasm.mnem = "MOVBB"; break;
        case 0x41: dasm.mnem = "MOVBC"; break;
        case 0x42: dasm.mnem = "MOVBD"; break;
        case 0x43: dasm.mnem = "MOVBE"; break;
        case 0x44: dasm.mnem = "MOVBH"; break;
        case 0x45: dasm.mnem = "MOVBL"; break;
        case 0x46: dasm.mnem = "MOVBM"; break;
        case 0x47: dasm.mnem = "MOVBA"; break;
        case 0x48: dasm.mnem = "MOVCB"; break;
        case 0x49: dasm.mnem = "MOVCC"; break;
        case 0x4A: dasm.mnem = "MOVCD"; break;
        case 0x4B: dasm.mnem = "MOVCE"; break;
        case 0x4C: dasm.mnem = "MOVCH"; break;
        case 0x4D: dasm.mnem = "MOVCL"; break;
        case 0x4E: dasm.mnem = "MOVCM"; break;
        case 0x4F: dasm.mnem = "MOVCA"; break;
            //
        case 0x50: dasm.mnem = "MOVDB"; break;
        case 0x51: dasm.mnem = "MOVDC"; break;
        case 0x52: dasm.mnem = "MOVDD"; break;
        case 0x53: dasm.mnem = "MOVDE"; break;
        case 0x54: dasm.mnem = "MOVDH"; break;
        case 0x55: dasm.mnem = "MOVDL"; break;
        case 0x56: dasm.mnem = "MOVDM"; break;
        case 0x57: dasm.mnem = "MOVDA"; break;
        case 0x58: dasm.mnem = "MOVEB"; break;
        case 0x59: dasm.mnem = "MOVEC"; break;
        case 0x5A: dasm.mnem = "MOVED"; break;
        case 0x5B: dasm.mnem = "MOVEE"; break;
        case 0x5C: dasm.mnem = "MOVEH"; break;
        case 0x5D: dasm.mnem = "MOVEL"; break;
        case 0x5E: dasm.mnem = "MOVEM"; break;
        case 0x5F: dasm.mnem = "MOVEA"; break;
            //
        case 0x60: dasm.mnem = "MOVHB"; break;
        case 0x61: dasm.mnem = "MOVHC"; break;
        case 0x62: dasm.mnem = "MOVHD"; break;
        case 0x63: dasm.mnem = "MOVHE"; break;
        case 0x64: dasm.mnem = "MOVHH"; break;
        case 0x65: dasm.mnem = "MOVHL"; break;
        case 0x66: dasm.mnem = "MOVHM"; break;
        case 0x67: dasm.mnem = "MOVHA"; break;
        case 0x68: dasm.mnem = "MOVLB"; break;
        case 0x69: dasm.mnem = "MOVLC"; break;
        case 0x6A: dasm.mnem = "MOVLD"; break;
        case 0x6B: dasm.mnem = "MOVLE"; break;
        case 0x6C: dasm.mnem = "MOVLH"; break;
        case 0x6D: dasm.mnem = "MOVLL"; break;
        case 0x6E: dasm.mnem = "MOVLM"; break;
        case 0x6F: dasm.mnem = "MOVLA"; break;
            //
        case 0x70: dasm.mnem = "MOVMB"; break;
        case 0x71: dasm.mnem = "MOVMC"; break;
        case 0x72: dasm.mnem = "MOVMD"; break;
        case 0x73: dasm.mnem = "MOVME"; break;
        case 0x74: dasm.mnem = "MOVMH"; break;
        case 0x75: dasm.mnem = "MOVML"; break;
        case 0x76: dasm.mnem = "HLT"; break;
        case 0x77: dasm.mnem = "MOVMA"; break;
        case 0x78: dasm.mnem = "MOVAB"; break;
        case 0x79: dasm.mnem = "MOVAC"; break;
        case 0x7A: dasm.mnem = "MOVAD"; break;
        case 0x7B: dasm.mnem = "MOVAE"; break;
        case 0x7C: dasm.mnem = "MOVAH"; break;
        case 0x7D: dasm.mnem = "MOVAL"; break;
        case 0x7E: dasm.mnem = "MOVAM"; break;
        case 0x7F: dasm.mnem = "MOVAA"; break;
            //
        case 0x80: dasm.mnem = "ADDB"; break;
        case 0x81: dasm.mnem = "ADDC"; break;
        case 0x82: dasm.mnem = "ADDD"; break;
        case 0x83: dasm.mnem = "ADDE"; break;
        case 0x84: dasm.mnem = "ADDH"; break;
        case 0x85: dasm.mnem = "ADDL"; break;
        case 0x86: dasm.mnem = "ADDM"; break;
        case 0x87: dasm.mnem = "ADDA"; break;
        case 0x88: dasm.mnem = "ADCB"; break;
        case 0x89: dasm.mnem = "ADCC"; break;
        case 0x8A: dasm.mnem = "ADCD"; break;
        case 0x8B: dasm.mnem = "ADCE"; break;
        case 0x8C: dasm.mnem = "ADCH"; break;
        case 0x8D: dasm.mnem = "ADCL"; break;
        case 0x8E: dasm.mnem = "ADCM"; break;
        case 0x8F: dasm.mnem = "ADCA"; break;
            //
        case 0x90: dasm.mnem = "SUBB"; break;
        case 0x91: dasm.mnem = "SUBC"; break;
        case 0x92: dasm.mnem = "SUBD"; break;
        case 0x93: dasm.mnem = "SUBE"; break;
        case 0x94: dasm.mnem = "SUBH"; break;
        case 0x95: dasm.mnem = "SUBL"; break;
        case 0x96: dasm.mnem = "SUBM"; break;
        case 0x97: dasm.mnem = "SUBA"; break;
        case 0x98: dasm.mnem = "SBBB"; break;
        case 0x99: dasm.mnem = "SBBC"; break;
        case 0x9A: dasm.mnem = "SBBD"; break;
        case 0x9B: dasm.mnem = "SBBE"; break;
        case 0x9C: dasm.mnem = "SBBH"; break;
        case 0x9D: dasm.mnem = "SBBL"; break;
        case 0x9E: dasm.mnem = "SBBM"; break;
        case 0x9F: dasm.mnem = "SBBA"; break;
            //
        case 0xA0: dasm.mnem = "ANAB"; break;
        case 0xA1: dasm.mnem = "ANAC"; break;
        case 0xA2: dasm.mnem = "ANAD"; break;
        case 0xA3: dasm.mnem = "ANAE"; break;
        case 0xA4: dasm.mnem = "ANAH"; break;
        case 0xA5: dasm.mnem = "ANAL"; break;
        case 0xA6: dasm.mnem = "ANAM"; break;
        case 0xA7: dasm.mnem = "ANAA"; break;
        case 0xA8: dasm.mnem = "XRAB"; break;
        case 0xA9: dasm.mnem = "XRAC"; break;
        case 0xAA: dasm.mnem = "XRAD"; break;
        case 0xAB: dasm.mnem = "XRAE"; break;
        case 0xAC: dasm.mnem = "XRAH"; break;
        case 0xAD: dasm.mnem = "XRAL"; break;
        case 0xAE: dasm.mnem = "XRAM"; break;
        case 0xAF: dasm.mnem = "XRAA"; break;
            //
        case 0xB0: dasm.mnem = "ORAB"; break;
        case 0xB1: dasm.mnem = "ORAC"; break;
        case 0xB2: dasm.mnem = "ORAD"; break;
        case 0xB3: dasm.mnem = "ORAE"; break;
        case 0xB4: dasm.mnem = "ORAH"; break;
        case 0xB5: dasm.mnem = "ORAL"; break;
        case 0xB6: dasm.mnem = "ORAM"; break;
        case 0xB7: dasm.mnem = "ORAA"; break;
        case 0xB8: dasm.mnem = "CMPB"; break;
        case 0xB9: dasm.mnem = "CMPC"; break;
        case 0xBA: dasm.mnem = "CMPD"; break;
        case 0xBB: dasm.mnem = "CMPE"; break;
        case 0xBC: dasm.mnem = "CMPH"; break;
        case 0xBD: dasm.mnem = "CMPL"; break;
        case 0xBE: dasm.mnem = "CMPM"; break;
        case 0xBF: dasm.mnem = "CMPA"; break;
            //
        case 0xC0: dasm.mnem = "RNZ"; break;
        case 0xC1: dasm.mnem = "POPB"; break;
        case 0xC2:
        {
            dasm.mnem = "JNZ";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xC3:
        {
            dasm.mnem = "JMP";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xC4:
        {
            dasm.mnem = "CNZ";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xC5: dasm.mnem = "PUSHB"; break;
        case 0xC6:
        {
            dasm.mnem = "ADI";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xC7: dasm.mnem = "RST0"; break;
        case 0xC8: dasm.mnem = "RZ"; break;
        case 0xC9: dasm.mnem = "RET"; break;
        case 0xCA:
        {
            dasm.mnem = "JZ";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xCB:
        {
            //e101 has this also as jmp??
            dasm.mnem = "NIL_SEEME!";
        }
        break;
        case 0xCC:
        {
            dasm.mnem = "CZ";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xCD:
        {
            dasm.mnem = "CALL";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xCE:
        {
            dasm.mnem = "ACI";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xCF: dasm.mnem = "RST1"; break;
            //
        case 0xD0: dasm.mnem = "RNC"; break;
        case 0xD1: dasm.mnem = "POPD"; break;
        case 0xD2:
        {
            dasm.mnem = "JNC";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xD3:
        {
            dasm.mnem = "OUT";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xD4:
        {
            dasm.mnem = "CNC";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xD5: dasm.mnem = "PUSHD"; break;
        case 0xD6:
        {
            dasm.mnem = "SUI";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xD7: dasm.mnem = "RST2"; break;
        case 0xD8: dasm.mnem = "RC"; break;
        case 0xD9: dasm.mnem = "NIL(RET)"; break; //e101 says this is RET
        case 0xDA:
        {
            dasm.mnem = "JC";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xDB:
        {
            dasm.mnem = "IN";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xDC:
        {
            dasm.mnem = "CC";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xDD: dasm.mnem = "NIL(CALL)"; break; //e101 has this as CALL
        case 0xDE:
        {
            dasm.mnem = "SBI";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xDF: dasm.mnem = "RST3"; break;
            //
        case 0xE0: dasm.mnem = "RPO"; break;
        case 0xE1: dasm.mnem = "POPH"; break;
        case 0xE2:
        {
            dasm.mnem = "JPO";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xE3: dasm.mnem = "XTHL"; break;
        case 0xE4:
        {
            dasm.mnem = "CPO";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xE5: dasm.mnem = "PUSHH"; break;
        case 0xE6: 
        {
            dasm.mnem = "ANI";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xE7: dasm.mnem = "RST4"; break;
        case 0xE8: dasm.mnem = "RPE"; break;
        case 0xE9: dasm.mnem = "PCHL"; break;
        case 0xEA:
        {
            dasm.mnem = "JPE";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xEB: dasm.mnem = "XCHG"; break;
        case 0xEC:
        {
            dasm.mnem = "CPE";
            dasm.operand1 = m_memory[++i];
            dasm.operand1 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xED: dasm.mnem = "NIL(CALL)"; break;//e101 has CALL
        case 0xEE:
        {
            dasm.mnem = "XRI";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xEF: dasm.mnem = "RST5"; break;
            //
        case 0xF0: dasm.mnem = "RP"; break;
        case 0xF1: dasm.mnem = "POPPSW"; break;
        case 0xF2:
        {
            dasm.mnem = "JP";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xF3: dasm.mnem = "DI"; break;
        case 0xF4:
        {
            dasm.mnem = "CP";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xF5: dasm.mnem = "PUSHPSW"; break;
        case 0xF6:
        {
            dasm.mnem = "ORI";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xF7: dasm.mnem = "RST6"; break;
        case 0xF8: dasm.mnem = "RM"; break;
        case 0xF9: dasm.mnem = "SPHL"; break;
        case 0xFA:
        {
            dasm.mnem = "JM";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xFB: dasm.mnem = "EI"; break;
        case 0xFC:
        {
            dasm.mnem = "CM";
            dasm.operand1 = m_memory[++i];
            dasm.operand0 = m_memory[++i];
            addOperand();
            addOperand();
        }
        break;
        case 0xFD: dasm.mnem = "NIL(CALL)"; break; //e101 has this as CALL
        case 0xFE:
        {
            dasm.mnem = "CPI";
            dasm.operand0 = m_memory[++i];
            addOperand();
        }
        break;
        case 0xFF: dasm.mnem = "RST7"; break;
        default: break;
        }
        
    }
    assert(m_disassembly.size() == 0x2000);
}

#endif //DEBUG_TOOLS