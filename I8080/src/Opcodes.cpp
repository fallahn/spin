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

#include <I8080/I8080.hpp>

#include <cassert>

using namespace I8080;

void CPU::setParity(std::int16_t value)
{
    Byte byte = 0;

    value = (value & (1 << 16) - 1);
    for (auto i = 0; i < 16; ++i)
    {
        if (value & 0x1) byte++;

        value >>= 1;
    }

    m_flags.p = !(byte & 0x1);
}

void CPU::notImpl()
{
    throw("Opcode not implemented, or illegal");
}

//----8 bit transfer instructions----//

//0x7f MOV A, A
void CPU::movaa()
{
    m_registers.A = m_registers.A;
    m_registers.programCounter++;
}
//0x78 MOV A, B
void CPU::movab()
{
    m_registers.A = m_registers.B;
    m_registers.programCounter++;
}
//0x79 MOV A, C
void CPU::movac()
{
    m_registers.A = m_registers.C;
    m_registers.programCounter++;
}
//0x7A MOV A, D
void CPU::movad()
{
    m_registers.A = m_registers.D;
    m_registers.programCounter++;
}
//0x7B MOV A, E
void CPU::movae()
{
    m_registers.A = m_registers.E;
    m_registers.programCounter++;
}
//0x7C MOV A, H
void CPU::movah()
{
    m_registers.A = m_registers.H;
    m_registers.programCounter++;
}
//0x7D MOV A, L
void CPU::moval()
{
    m_registers.A = m_registers.L;
    m_registers.programCounter++;
}
//0x7E MOV A, M
void CPU::movam()
{
    m_registers.A = m_memory[m_registers.M];
    m_registers.programCounter++;
}

//0x47 MOV B, A
void CPU::movba()
{
    m_registers.B = m_registers.A;
    m_registers.programCounter++;
}
//0x40 MOV B, B
void CPU::movbb()
{
    m_registers.B = m_registers.B;
    m_registers.programCounter++;
}
//0x41 MOV B, C
void CPU::movbc()
{
    m_registers.B = m_registers.C;
    m_registers.programCounter++;
}
//0x42 MOV B, D
void CPU::movbd()
{
    m_registers.B = m_registers.D;
    m_registers.programCounter++;
}
//0x43 MOV B, E
void CPU::movbe()
{
    m_registers.B = m_registers.E;
    m_registers.programCounter++;
}
//0x44 MOV B, H
void CPU::movbh()
{
    m_registers.B = m_registers.H;
    m_registers.programCounter++;
}
//0x45 MOV B, L
void CPU::movbl()
{
    m_registers.B = m_registers.L;
    m_registers.programCounter++;
}
//0x46 MOV B, M
void CPU::movbm()
{
    m_registers.B = m_memory[m_registers.M];
    m_registers.programCounter++;
}

//0x4F MOV C, A
void CPU::movca()
{
    m_registers.C = m_registers.A;
    m_registers.programCounter++;
}
//0x48 MOV C, B
void CPU::movcb()
{
    m_registers.C = m_registers.B;
    m_registers.programCounter++;
}
//0x49 MOV C, C
void CPU::movcc()
{
    m_registers.C = m_registers.C;
    m_registers.programCounter++;
}
//0x4A MOV C, D
void CPU::movcd()
{
    m_registers.C = m_registers.D;
    m_registers.programCounter++;
}
//0x4B MOV C, E
void CPU::movce()
{
    m_registers.C = m_registers.E;
    m_registers.programCounter++;
}
//0x4C MOV C, H
void CPU::movch()
{
    m_registers.C = m_registers.H;
    m_registers.programCounter++;
}
//0x4D MOV C, L
void CPU::movcl()
{
    m_registers.C = m_registers.L;
    m_registers.programCounter++;
}
//0x4E MOV C, M
void CPU::movcm()
{
    m_registers.C = m_memory[m_registers.M];
    m_registers.programCounter++;
}

//0x57 MOV D, A
void CPU::movda()
{
    m_registers.D = m_registers.A;
    m_registers.programCounter++;
}
//0x50 MOV D, B
void CPU::movdb()
{
    m_registers.D = m_registers.B;
    m_registers.programCounter++;
}
//0x51 MOV D, C
void CPU::movdc()
{
    m_registers.D = m_registers.C;
    m_registers.programCounter++;
}
//0x52 MOV D, D
void CPU::movdd()
{
    m_registers.D = m_registers.D;
    m_registers.programCounter++;
}
//0x53 MOV D, E
void CPU::movde()
{
    m_registers.D = m_registers.E;
    m_registers.programCounter++;
}
//0x54 MOV D, H
void CPU::movdh()
{
    m_registers.D = m_registers.H;
    m_registers.programCounter++;
}
//0x55 MOV D, L
void CPU::movdl()
{
    m_registers.D = m_registers.L;
    m_registers.programCounter++;
}
//0x56 MOV D, M
void CPU::movdm()
{
    m_registers.D = m_memory[m_registers.M];
    m_registers.programCounter++;
}

//0x5F MOV E, A
void CPU::movea()
{
    m_registers.E = m_registers.A;
    m_registers.programCounter++;
}
//0x58 MOV E, B
void CPU::moveb()
{
    m_registers.E = m_registers.B;
    m_registers.programCounter++;
}
//0x59 MOV E, C
void CPU::movec()
{
    m_registers.E = m_registers.C;
    m_registers.programCounter++;
}
//0x5A MOV E, D
void CPU::moved()
{
    m_registers.E = m_registers.D;
    m_registers.programCounter++;
}
//0x5B MOV E, E
void CPU::movee()
{
    m_registers.E = m_registers.E;
    m_registers.programCounter++;
}
//0x5C MOV E, H
void CPU::moveh()
{
    m_registers.E = m_registers.H;
    m_registers.programCounter++;
}
//0x5D MOV E, L
void CPU::movel()
{
    m_registers.E = m_registers.L;
    m_registers.programCounter++;
}
//0x5E MOV E, M
void CPU::movem()
{
    m_registers.E = m_memory[m_registers.M];
    m_registers.programCounter++;
}

//0x67 MOV H, A
void CPU::movha()
{
    m_registers.H = m_registers.A;
    m_registers.programCounter++;
}
//0x60 MOV H, B
void CPU::movhb()
{
    m_registers.H = m_registers.B;
    m_registers.programCounter++;
}
//0x61 MOV H, C
void CPU::movhc()
{
    m_registers.H = m_registers.C;
    m_registers.programCounter++;
}
//0x62 MOV H, D
void CPU::movhd() 
{
    m_registers.H = m_registers.D;
    m_registers.programCounter++;
}
//0x63 MOV H, E
void CPU::movhe()
{
    m_registers.H = m_registers.E;
    m_registers.programCounter++;
}
//0x64 MOV H, H
void CPU::movhh()
{
    m_registers.H = m_registers.H;
    m_registers.programCounter++;
}
//0x65 MOV H, L
void CPU::movhl()
{
    m_registers.H = m_registers.L;
    m_registers.programCounter++;
}
//0x66 MOV H, M
void CPU::movhm()
{
    m_registers.H = m_memory[m_registers.M];
    m_registers.programCounter++;
}

//0x6F MOV L, A
void CPU::movla()
{
    m_registers.L = m_registers.A;
    m_registers.programCounter++;
}
//0x68 MOV L, B
void CPU::movlb()
{
    m_registers.L = m_registers.B;
    m_registers.programCounter++;
}
//0x69 MOV L, C
void CPU::movlc()
{
    m_registers.L = m_registers.C;
    m_registers.programCounter++;
}
//0x6A MOV L, D
void CPU::movld()
{
    m_registers.L = m_registers.D;
    m_registers.programCounter++;
}
//0x6B MOV L, E
void CPU::movle()
{
    m_registers.L = m_registers.E;
    m_registers.programCounter++;
}
//0x6C MOV L, H
void CPU::movlh() 
{
    m_registers.L = m_registers.H;
    m_registers.programCounter++;
}
//0x6D MOV L, L
void CPU::movll()
{
    m_registers.L = m_registers.L;
    m_registers.programCounter++;
}
//0x6E MOV L, M
void CPU::movlm()
{
    m_registers.L = m_memory[m_registers.M];
    m_registers.programCounter++;
}

//0x77 MOV M, A
void CPU::movma()
{
    m_memory[m_registers.M] = m_registers.A;
    m_registers.programCounter++;
}
//0x70 MOV M, B
void CPU::movmb() 
{
    m_memory[m_registers.M] = m_registers.B;
    m_registers.programCounter++;
}
//0x71 MOV M, C
void CPU::movmc()
{
    m_memory[m_registers.M] = m_registers.C;
    m_registers.programCounter++;
}
//0x72 MOV M, D
void CPU::movmd()
{
    m_memory[m_registers.M] = m_registers.D;
    m_registers.programCounter++;
}
//0x73 MOV M, E
void CPU::movme()
{
    m_memory[m_registers.M] = m_registers.E;
    m_registers.programCounter++;
}
//0x74 MOV M, H
void CPU::movmh()
{
    m_memory[m_registers.M] = m_registers.H;
    m_registers.programCounter++;
}
//0x75 MOV M, L
void CPU::movml()
{
    m_memory[m_registers.M] = m_registers.L;
    m_registers.programCounter++;
}


//------16 bit transfer instructions-----//
//0x01 LD B, word
void CPU::lxib()
{
    m_registers.BC = getWord(m_registers.programCounter + 1);
    m_registers.programCounter += 3; //also skip the value we just loaded
}
//0x11 LD D, word
void CPU::lxid()
{
    m_registers.DE = getWord(m_registers.programCounter + 1);
    m_registers.programCounter += 3;
}
//0x21 LD H, word
void CPU::lxih()
{
    m_registers.HL = getWord(m_registers.programCounter + 1);
    m_registers.programCounter += 3;
}
//0x31 LD SP, word
void CPU::lxisp()
{
    m_registers.stackPointer = getWord(m_registers.programCounter + 1);
    m_registers.programCounter += 3;
}
//0x2A LHLD SP word
void CPU::lhld()
{
    m_registers.HL = ((m_memory[getWord(m_registers.programCounter + 1) + 1] << 8) | m_memory[getWord(m_registers.programCounter + 1)]);
    m_registers.programCounter += 3;
}
//0x22 SHLD SP, word
void CPU::shld()
{
    m_memory[getWord(m_registers.programCounter + 1)] = m_registers.L;
    m_memory[getWord(m_registers.programCounter + 1) + 1] = m_registers.H;
    m_registers.programCounter += 3;
}
//0xF9 SP, HL
void CPU::sphl()
{
    m_registers.stackPointer = m_registers.HL;
    m_registers.programCounter++;
}
//0x0A
void CPU::ldaxb()
{
    m_registers.A = m_memory[m_registers.BC];
    m_registers.programCounter++;
}
//0x1A
void CPU::ldaxd()
{
    m_registers.A = m_memory[m_registers.DE];
    m_registers.programCounter++;
}
//0x02
void CPU::staxb()
{
    m_memory[m_registers.BC] = m_registers.A;
    m_registers.programCounter++;
}
//0x12
void CPU::staxd()
{
    m_memory[m_registers.DE] = m_registers.A;
    m_registers.programCounter++;
}
//0x3A
void CPU::lda()
{
    m_registers.A = m_memory[getWord(m_registers.programCounter + 1)];
    m_registers.programCounter += 3;
}
//0x32
void CPU::sta()
{
    m_memory[getWord(m_registers.programCounter + 1)] = m_registers.A;
    m_registers.programCounter += 3;
}

//-----register exchange instructions-----//
//0xEB
void CPU::xchg()
{
    Word temp = m_registers.HL;
    m_registers.HL = m_registers.DE;
    m_registers.DE = temp;
    m_registers.programCounter++;
}
//0xE3
void CPU::xthl()
{
    Byte temp = m_registers.L;
    m_registers.L = m_memory[m_registers.stackPointer];
    m_memory[m_registers.stackPointer] = temp;

    temp = m_registers.H;
    m_registers.H = m_memory[m_registers.stackPointer + 1];
    m_memory[m_registers.stackPointer + 1] = temp;

    m_registers.programCounter++;
}

//----8 bit ADD instructions----//
//----adds src register to accumulator----//
void CPU::accumulate(std::int16_t result)
{
    m_flags.ac = ((m_registers.A & 0xF) > (result & 0xF));
    m_flags.cy = ((result > 0xFF) || (result < 0));
    m_flags.s = (result >> 7);
    m_flags.z = !result;
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter++;
}
//0x87
void CPU::adda()
{
    accumulate(m_registers.A + m_registers.A);
}
//0x80
void CPU::addb()
{
    accumulate(m_registers.A + m_registers.B);
}
//0x81
void CPU::addc()
{
    accumulate(m_registers.A + m_registers.C);
}
//0x82
void CPU::addd()
{
    accumulate(m_registers.A + m_registers.D);
}
//0x83
void CPU::adde()
{
    accumulate(m_registers.A + m_registers.E);
}
//0x84
void CPU::addh()
{
    accumulate(m_registers.A + m_registers.H);
}
//0x85
void CPU::addl()
{
    accumulate(m_registers.A + m_registers.L);
}
//0x86
void CPU::addm()
{
    accumulate(m_registers.A + m_memory[m_registers.M]);
}
//0xC6
void CPU::adi()
{
    std::int16_t result = m_registers.A + m_memory[m_registers.programCounter + 1];
    m_flags.ac = ((m_registers.A & 0xF) > (result & 0xF));
    m_flags.cy = ((result > 0xFF) || (result < 0));
    m_flags.s = result >> 7;
    m_flags.z = !result;
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter += 2;
}

//-----adds src register to accumulator with carry----//
//0x8F
void CPU::adca()
{
    accumulate(m_registers.A + m_registers.A + m_flags.cy);
}
//0x88
void CPU::adcb()
{
    accumulate(m_registers.A + m_registers.B + m_flags.cy);
}
//0x89
void CPU::adcc()
{
    accumulate(m_registers.A + m_registers.C + m_flags.cy);
}
//0x8A
void CPU::adcd()
{
    accumulate(m_registers.A + m_registers.D + m_flags.cy);
}
//0x8B
void CPU::adce()
{
    accumulate(m_registers.A + m_registers.E + m_flags.cy);
}
//0x8C
void CPU::adch() 
{
    accumulate(m_registers.A + m_registers.H + m_flags.cy);
}
//0x8D
void CPU::adcl()
{
    accumulate(m_registers.A + m_registers.L + m_flags.cy);
}
//0x8E
void CPU::adcm()
{
    accumulate(m_registers.A + m_memory[m_registers.M] + m_flags.cy);
}
//0xCE
void CPU::aci()
{
    std::int16_t result = m_registers.A + m_memory[m_registers.programCounter + 1] + m_flags.cy;
    m_flags.ac = ((m_registers.A & 0xF) > (result & 0xF));
    m_flags.cy = ((result > 0xFF) || (result < 0));
    m_flags.s = result >> 7;
    m_flags.z = !result;
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter += 2;
}

//------subtracts src register from accumulator----//
//0x97
void CPU::suba()
{
    accumulate(m_registers.A - m_registers.A);
}
//0x90
void CPU::subb()
{
    accumulate(m_registers.A - m_registers.B);
}
//0x91
void CPU::subc()
{
    accumulate(m_registers.A - m_registers.C);
}
//0x92
void CPU::subd()
{
    accumulate(m_registers.A - m_registers.D);
}
//0x93
void CPU::sube()
{
    accumulate(m_registers.A - m_registers.E);
}
//0x94
void CPU::subh()
{
    accumulate(m_registers.A - m_registers.H);
}
//0x95
void CPU::subl()
{
    accumulate(m_registers.A - m_registers.L);
}
//0x96
void CPU::subm()
{
    accumulate(m_registers.A - m_memory[m_registers.M]);
}
//0xD6
void CPU::sui()
{
    std::int16_t result = m_registers.A - m_memory[m_registers.programCounter + 1];

    m_flags.ac = ((m_registers.A & 0xF) > (result & 0xF));
    m_flags.cy = ((result > 0xFF) || (result < 0));
    m_flags.s = result >> 7;
    m_flags.z = !result;
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter += 2;
}

//----subtracts src register from accumulator with borrow----//
//0x9F
void CPU::sbba()
{
    accumulate(m_registers.A - m_registers.A - m_flags.cy);
}
//0x98
void CPU::sbbb()
{
    accumulate(m_registers.A - m_registers.B - m_flags.cy);
}
//0x99
void CPU::sbbc()
{
    accumulate(m_registers.A - m_registers.C - m_flags.cy);
}
//0x9A
void CPU::sbbd()
{
    accumulate(m_registers.A - m_registers.D - m_flags.cy);
}
//0x9B
void CPU::sbbe()
{
    accumulate(m_registers.A - m_registers.E - m_flags.cy);
}
//0x9C
void CPU::sbbh()
{
    accumulate(m_registers.A - m_registers.H - m_flags.cy);
}
//0x9D
void CPU::sbbl()
{
    accumulate(m_registers.A - m_registers.L - m_flags.cy);
}
//0x9E
void CPU::sbbm()
{
    accumulate(m_registers.A - m_memory[m_registers.M] - m_flags.cy);
}
//0xDE
void CPU::sbi()
{
    std::int16_t result = m_registers.A - m_memory[m_registers.programCounter + 1] - m_flags.cy;

    m_flags.ac = ((m_registers.A & 0xF) > (result & 0xF));
    m_flags.cy = ((result > 0xFF) || (result < 0));
    m_flags.s = result >> 7;
    m_flags.z = !result;
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter += 2;
}


//----DAD (double add) instructions----//
//0x09
void CPU::dadb()
{
    std::int32_t result = m_registers.HL + m_registers.BC;

    m_flags.cy = (result > 0xFFFF || result < 0);
    m_registers.HL = result & 0xFFFF;
    m_registers.programCounter++;
}
//0x19
void CPU::dadd()
{
    std::int32_t result = m_registers.HL + m_registers.DE;

    m_flags.cy = (result > 0xFFFF || result < 0);
    m_registers.HL = result & 0xFFFF;
    m_registers.programCounter++;
}
//0x29
void CPU::dadh()
{
    std::int32_t result = m_registers.HL + m_registers.HL;

    m_flags.cy = (result > 0xFFFF || result < 0);
    m_registers.HL = result & 0xFFFF;
    m_registers.programCounter++;
}
//0x39
void CPU::dadsp()
{
    std::int32_t result = m_registers.HL + m_registers.stackPointer;

    m_flags.cy = (result > 0xFFFF || result < 0);
    m_registers.HL = result & 0xFFFF;
    m_registers.programCounter++;
}

//----control instructions----//
//0xF3 - disable interrupt
void CPU::di()
{
    m_interruptEnabled = false;
    m_registers.programCounter++;
}
//0xFB - enable interrupt
void CPU::ei()
{
    m_interruptEnabled = true;
    if (m_interruptPending & 0x80)
    {
        raiseInterrupt(m_interruptPending & 0x7F);
    }
    m_registers.programCounter++;
}
//0x00
void CPU::nop()
{
    m_registers.programCounter++;
}
//0x76
void CPU::hlt()
{
    //TODO stop emulation or quit altogether??
}


//----increment/decrement instructions----//
void CPU::inc8(std::int16_t result, std::uint8_t reg)
{
    m_flags.ac = ((reg & 0xF) > (result & 0xF));
    m_flags.s = result >> 7;
    m_flags.z = !(result);
    setParity(result);
}
//0x3C
void CPU::inra()
{
    std::int16_t result = m_registers.A + 1;
    inc8(result, m_registers.A);
    m_registers.A = result & 0xFF;
    m_registers.programCounter++;
}
//0x04
void CPU::inrb()
{
    std::int16_t result = m_registers.B + 1;
    inc8(result, m_registers.B);
    m_registers.B = result & 0xFF;
    m_registers.programCounter++;
}
//0x0C
void CPU::inrc()
{
    std::int16_t result = m_registers.C + 1;
    inc8(result, m_registers.C);
    m_registers.C = result & 0xFF;
    m_registers.programCounter++;
}
//0x14
void CPU::inrd()
{
    std::int16_t result = m_registers.D + 1;
    inc8(result, m_registers.D);
    m_registers.D = result & 0xFF;
    m_registers.programCounter++;
}
//0x1C
void CPU::inre()
{
    std::int16_t result = m_registers.E + 1;
    inc8(result, m_registers.E);
    m_registers.E = result & 0xFF;
    m_registers.programCounter++;
}
//0x24
void CPU::inrh()
{
    std::int16_t result = m_registers.H + 1;
    inc8(result, m_registers.H);
    m_registers.H = result & 0xFF;
    m_registers.programCounter++;
}
//0x2C
void CPU::inrl()
{
    std::int16_t result = m_registers.L + 1;
    inc8(result, m_registers.L);
    m_registers.L = result & 0xFF;
    m_registers.programCounter++;
}
//0x34
void CPU::inrm()
{
    std::int16_t result = m_memory[m_registers.M] + 1;
    inc8(result, m_memory[m_registers.M]);
    m_memory[m_registers.M] = result & 0xFF;
    m_registers.programCounter++;
}

//0x3D
void CPU::dcra()
{
    std::int16_t result = m_registers.A - 1;
    inc8(result, m_registers.A);
    m_registers.A = result & 0xFF;
    m_registers.programCounter++;
}
//0x05
void CPU::dcrb()
{
    std::int16_t result = m_registers.B - 1;
    inc8(result, m_registers.B);
    m_registers.B = result & 0xFF;
    m_registers.programCounter++;
}
//0x0D
void CPU::dcrc()
{
    std::int16_t result = m_registers.C - 1;
    inc8(result, m_registers.C);
    m_registers.C = result & 0xFF;
    m_registers.programCounter++;
}
//0x15
void CPU::dcrd()
{
    std::int16_t result = m_registers.D - 1;
    inc8(result, m_registers.D);
    m_registers.D = result & 0xFF;
    m_registers.programCounter++;
}
//0x1D
void CPU::dcre()
{
    std::int16_t result = m_registers.E - 1;
    inc8(result, m_registers.E);
    m_registers.E = result & 0xFF;
    m_registers.programCounter++;
}
//0x25
void CPU::dcrh()
{
    std::int16_t result = m_registers.H - 1;
    inc8(result, m_registers.H);
    m_registers.H = result & 0xFF;
    m_registers.programCounter++;
}
//0x2D
void CPU::dcrl()
{
    std::int16_t result = m_registers.L - 1;
    inc8(result, m_registers.L);
    m_registers.L = result & 0xFF;
    m_registers.programCounter++;
}
//0x35
void CPU::dcrm()
{
    std::int16_t result = m_memory[m_registers.M] - 1;
    inc8(result, m_memory[m_registers.M]);
    m_memory[m_registers.M] = result & 0xFF;
    m_registers.programCounter++;
}

//----increment / decrement register pairs----//
//0x03
void CPU::inxb()
{
    m_registers.BC++;
    m_registers.programCounter++;
}
//0x13
void CPU::inxd()
{
    m_registers.DE++;
    m_registers.programCounter++;
}
//0x23
void CPU::inxh()
{
    m_registers.HL++;
    m_registers.programCounter++;
}
//0x33
void CPU::inxsp()
{
    m_registers.stackPointer++;
    m_registers.programCounter++;
}
//0x0B
void CPU::dcxb()
{
    m_registers.BC--;
    m_registers.programCounter++;
}
//0x1B
void CPU::dcxd()
{
    m_registers.DE--;
    m_registers.programCounter++;
}
//0x2B
void CPU::dcxh()
{
    m_registers.HL--;
    m_registers.programCounter++;
}
//0x3B
void CPU::dcxsp()
{
    m_registers.stackPointer--;
    m_registers.programCounter++;
}

//----accumulator and flag special instructions----//
//0x27
void CPU::daa()
{
    if ((m_registers.A & 0x0F) > 9 || m_flags.ac)
    {
        std::int16_t result = m_registers.A + 6;
        m_flags.cy = ((m_registers.A & 8) > (result & 8));
        m_registers.A = result & 0xFF;
    }

    if ((m_registers.A >> 4) > 9 || m_flags.ac)
    {
        std::int16_t result = m_registers.A + (6 << 4);
        m_flags.cy = ((m_registers.A & 0x80) > (result & 0x80));
        m_registers.A = result & 0xFF;
    }
    m_registers.programCounter++;
}
//0x2F
void CPU::cma()
{
    m_registers.A = ~m_registers.A;
    m_registers.programCounter++;
}
//0x37
void CPU::stc()
{
    m_flags.cy = 1;
    m_registers.programCounter++;
}
//0x3F
void CPU::cmc()
{
    m_flags.cy = 0;
    m_registers.programCounter++;
}

//----rotate instructions----//
//0x07
void CPU::rlc()
{
    m_flags.cy = m_registers.A >> 7;
    m_registers.A = (m_registers.A << 1) | (m_registers.A >> 7);
    m_registers.programCounter++;
}
//0x0F
void CPU::rrc()
{
    std::int16_t result = (m_registers.A >> 1) | ((m_registers.A & 0x1) << 7);
    m_flags.cy = (m_registers.A & 0x01);
    m_registers.A = result & 0xFF;
    m_registers.programCounter++;
}
//0x17
void CPU::ral()
{
    std::uint16_t temp = m_flags.cy;
    m_flags.cy = (m_registers.A & 0x80);
    m_registers.A = (m_registers.A << 1) | (temp & 0x80);
    m_registers.programCounter++;
}
//0x1F
void CPU::rar()
{
    std::int16_t result = (m_registers.A >> 1) | (m_flags.cy << 7);

    m_flags.cy = result & 0x1;

    m_registers.A = result & 0xFF;
    m_registers.programCounter++;
}


//----logic instructions----//
//----AND----//
void CPU::bitlogic(std::int16_t result)
{
    m_flags.ac = 0;
    m_flags.cy = 0;
    m_flags.s = result >> 7;
    m_flags.z = !(result);
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter++;
}
//0xA7
void CPU::anaa()
{
    bitlogic(m_registers.A & m_registers.A);
}
//0xA0
void CPU::anab() 
{
    bitlogic(m_registers.A & m_registers.B);
}
//0xA1
void CPU::anac()
{
    bitlogic(m_registers.A & m_registers.C);
}
//0xA2
void CPU::anad()
{
    bitlogic(m_registers.A & m_registers.D);
}
//0xA3
void CPU::anae()
{
    bitlogic(m_registers.A & m_registers.E);
}
//0xA4
void CPU::anah()
{
    bitlogic(m_registers.A & m_registers.H);
}
//0xA5
void CPU::anal()
{
    bitlogic(m_registers.A & m_registers.L);
}
//0xA6
void CPU::anam()
{
    bitlogic(m_registers.A & m_memory[m_registers.M]);
}
//0xE6
void CPU::ani()
{
    std::int16_t result = m_registers.A & m_memory[m_registers.programCounter + 1];

    m_flags.ac = 0;
    m_flags.cy = 0;
    m_flags.s = result >> 7;
    m_flags.z = !(result);
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter += 2;
}
//----XOR----//
//0xAF
void CPU::xraa()
{
    bitlogic(m_registers.A ^ m_registers.A);
}
//0xA8
void CPU::xrab()
{
    bitlogic(m_registers.A ^ m_registers.B);
}
//0xA9
void CPU::xrac()
{
    bitlogic(m_registers.A ^ m_registers.C);
}
//0xAA
void CPU::xrad()
{
    bitlogic(m_registers.A ^ m_registers.D);
}
//0xAB
void CPU::xrae()
{
    bitlogic(m_registers.A ^ m_registers.E);
}
//0xAC
void CPU::xrah()
{
    bitlogic(m_registers.A ^ m_registers.H);
}
//0xAD
void CPU::xral()
{
    bitlogic(m_registers.A ^ m_registers.L);
}
//0xAE
void CPU::xram()
{
    bitlogic(m_registers.A ^ m_memory[m_registers.M]);
}
//0xEE
void CPU::xri()
{
    std::int16_t result = m_registers.A ^ m_memory[m_registers.programCounter + 1];

    m_flags.ac = 0;
    m_flags.cy = 0;
    m_flags.s = result >> 7;
    m_flags.z = !(result);
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter += 2;
}
//----OR----//
//0xB7
void CPU::oraa()
{
    bitlogic(m_registers.A | m_registers.A);
}
//0xB0
void CPU::orab()
{
    bitlogic(m_registers.A | m_registers.B);
}
//0xB1
void CPU::orac()
{
    bitlogic(m_registers.A | m_registers.C);
}
//0xB2
void CPU::orad()
{
    bitlogic(m_registers.A | m_registers.D);
}
//0xB3
void CPU::orae()
{
    bitlogic(m_registers.A | m_registers.E);
}
//0xB4
void CPU::orah()
{
    bitlogic(m_registers.A | m_registers.H);
}
//0xB5
void CPU::oral()
{
    bitlogic(m_registers.A | m_registers.L);
}
//0xB6
void CPU::oram()
{
    bitlogic(m_registers.A | m_memory[m_registers.M]);
}
//0xF6
void CPU::ori()
{
    std::int16_t result = m_registers.A | m_memory[m_registers.programCounter + 1];
    m_flags.ac = 0;
    m_flags.cy = 0;
    m_flags.s = result >> 7;
    m_flags.z = !(result);
    setParity(result);

    m_registers.A = result & 0xFF;
    m_registers.programCounter += 2;
}


//----compare src register with accumulator----//
void CPU::compare(std::int16_t result)
{
    m_flags.ac = (m_registers.A & 0xF) > (result & 0xF);
    m_flags.cy = (result > 0xFF || result < 0);
    m_flags.s = (result >> 7);
    setParity(result);

    m_registers.programCounter++;
}
//0xBf
void CPU::cmpa()
{
    compare(m_registers.A - m_registers.A);
}
//0xB8
void CPU::cmpb()
{
    compare(m_registers.A - m_registers.B);
}
//0xB9
void CPU::cmpc()
{
    compare(m_registers.A - m_registers.C);
}
//0xBA
void CPU::cmpd()
{
    compare(m_registers.A - m_registers.D);
}
//0xBB
void CPU::cmpe()
{
    compare(m_registers.A - m_registers.E);
}
//0xBC
void CPU::cmph()
{
    compare(m_registers.A - m_registers.H);
}
//0xBD
void CPU::cmpl()
{
    compare(m_registers.A - m_registers.L);
}
//0xBE
void CPU::cmpm()
{
    compare(m_registers.A - m_memory[m_registers.M]);
}
//0xFE
void CPU::cpi()
{
    std::int16_t result = m_registers.A - m_memory[m_registers.programCounter + 1];

    m_flags.ac = (m_registers.A & 0xF) > (result & 0xF);
    m_flags.cy = (result > 0xFF || result < 0);
    m_flags.s = (result >> 7);
    m_flags.z = !(result);
    setParity(result);

    m_registers.programCounter += 2;
}

//----branching instructions----//
//jumps
//0xC3
void CPU::jmp()
{
    m_registers.programCounter = getWord(m_registers.programCounter + 1);
}
//0xC2
void CPU::jnz()
{
    m_registers.programCounter = (!m_flags.z) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xCA
void CPU::jz()
{
    m_registers.programCounter = (m_flags.z) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xD2
void CPU::jnc()
{
    m_registers.programCounter = (!m_flags.cy) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xDA
void CPU::jc()
{
    m_registers.programCounter = (m_flags.cy) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xE2
void CPU::jpo()
{
    m_registers.programCounter = (!m_flags.p) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xEA
void CPU::jpe()
{
    m_registers.programCounter = (m_flags.p) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xF2
void CPU::jp()
{
    m_registers.programCounter = (!m_flags.s) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xFA
void CPU::jm()
{
    m_registers.programCounter = (m_flags.s) ? getWord(m_registers.programCounter + 1) : m_registers.programCounter + 3;
}
//0xE9
void CPU::pchl()
{
    m_registers.programCounter = m_registers.HL;
}

//calls
//0xCD
void CPU::call()
{
    pushWord(m_registers.programCounter + 3);
    m_registers.programCounter = getWord(m_registers.programCounter + 1);
}
//0xC4
void CPU::cnz()
{
    if (!m_flags.z)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}
//0xCC
void CPU::cz() 
{
    if (m_flags.z)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}
//0xD4
void CPU::cnc() 
{
    if (!m_flags.cy)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}
//0xDC
void CPU::cc()
{
    if (m_flags.cy)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}
//0xE4
void CPU::cpo()
{
    if (!m_flags.p)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}
//0xEC
void CPU::cpe()
{
    if (m_flags.p)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}
//0xF4
void CPU::cp()
{
    if (!m_flags.s)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}
//0xFC
void CPU::cm()
{
    if (m_flags.s)
    {
        call();
    }
    else
    {
        m_registers.programCounter += 3;
    }
}

//returns
//0xC9
void CPU::ret()
{
    assert(m_registers.stackPointer < 0xFFFF);
    m_registers.programCounter = popWord();
}
//0xC0
void CPU::rnz()
{
    if (!m_flags.z)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}
//0xC8
void CPU::rz()
{
    if (m_flags.z)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}
//0xD0
void CPU::rnc()
{
    if (!m_flags.cy)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}
//0xD8
void CPU::rc()
{
    if (m_flags.cy)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}
//0xE0
void CPU::rpo()
{
    if (!m_flags.p)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}
//0xE8
void CPU::rpe()
{
    if (m_flags.p)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}
//0xF0
void CPU::rp()
{
    if (!m_flags.s)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}
//0xF8
void CPU::rm()
{
    if (m_flags.s)
    {
        ret();
    }
    else
    {
        m_registers.programCounter++;
    }
}


//RST
void CPU::rst()
{
    m_registers.stackPointer -= 2;
    m_memory[m_registers.stackPointer] = m_registers.programCounter & 0x00FF;
    m_memory[m_registers.stackPointer + 1] = ((m_registers.programCounter >> 8) & 0xFF);
}
//0xC7
void CPU::rst0()
{
    rst();
    m_registers.programCounter = 0;
}
//0xCF
void CPU::rst1()
{
    rst();
    m_registers.programCounter = 0x0008;
}
//0xD7
void CPU::rst2()
{
    rst();
    m_registers.programCounter = 0x0010;
}
//0xDF
void CPU::rst3()
{
    rst();
    m_registers.programCounter = 0x0018;
}
//0xE7
void CPU::rst4()
{
    rst();
    m_registers.programCounter = 0x0020;
}
//0xEF
void CPU::rst5()
{
    rst();
    m_registers.programCounter = 0x0028;
}
//0xF7
void CPU::rst6()
{
    rst();
    m_registers.programCounter = 0x0030;
}
//0xFF
void CPU::rst7()
{
    rst();
    m_registers.programCounter = 0x0038;
}


//----stack operations----//
//0xC5
void CPU::pushb()
{
    pushWord(m_registers.BC);
    m_registers.programCounter++;
}
//0xD5
void CPU::pushd()
{
    pushWord(m_registers.DE);
    m_registers.programCounter++;
}
//0xE5
void CPU::pushh()
{
    pushWord(m_registers.HL);
    m_registers.programCounter++;
}
//0xF5
void CPU::pushpsw()
{
    m_memory[m_registers.stackPointer - 2] = *(Byte*)(&m_flags);
    m_memory[m_registers.stackPointer - 1] = m_registers.A;
    m_registers.stackPointer -= 2;
    m_registers.programCounter++;
}
//0xC1
void CPU::popb()
{
    m_registers.BC = popWord();
    m_registers.programCounter++;
}
//0xD1
void CPU::popd()
{
    m_registers.DE = popWord();
    m_registers.programCounter++;
}
//0xE1
void CPU::poph()
{
    m_registers.HL = popWord();
    m_registers.programCounter++;
}
//0xF1
void CPU::poppsw()
{
    m_registers.A = m_memory[m_registers.stackPointer + 1];
    *(Byte*)(&m_flags) = m_memory[m_registers.stackPointer];
    m_registers.stackPointer += 2;
    m_registers.programCounter++;
}


//----IO instructions----//
//0xDB
void CPU::in()
{
    Byte port = m_memory[m_registers.programCounter + 1];

    switch (port)
    {
    default: break;
    case 1:
        m_registers.A = m_ports[1];
        break;
    case 2:
        m_registers.A = m_ports[2];
        break;
    case 3:
    {
        Word v = (m_shiftByte1 << 8) | m_shiftByte0;
        m_registers.A = ((v >> (8 - m_shiftOffset)) & 0xFF);
    }
    break;
    }

    m_registers.programCounter += 2;
}
//0xD3
void CPU::out()
{
    Byte port = m_memory[m_registers.programCounter + 1];

    switch (port)
    {
    default: break;
    case 2:
        m_shiftOffset = m_registers.A & 0x7;
        break;
    case 4:
        m_shiftByte0 = m_shiftByte1;
        m_shiftByte1 = m_registers.A;
        break;
    }

    m_registers.programCounter += 2;
}


//-----16 bit transfer immediate instructions-----//
//0x3E
void CPU::mvia()
{
    m_registers.A = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}
//0x06
void CPU::mvib()
{
    m_registers.B = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}
//0x0E
void CPU::mvic()
{
    m_registers.C = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}
//0x16
void CPU::mvid()
{
    m_registers.D = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}
//0x1E
void CPU::mvie()
{
    m_registers.E = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}
//0x26
void CPU::mvih()
{
    m_registers.H = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}
//0x2E
void CPU::mvil()
{
    m_registers.L = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}
//0x36
void CPU::mvim()
{
    m_memory[m_registers.HL] = m_memory[m_registers.programCounter + 1];
    m_registers.programCounter += 2;
}