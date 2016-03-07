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

using namespace I8080;

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
    m_registers.B = m_registers.D;
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