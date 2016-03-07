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

#include <cstring>
#include <cassert>

using namespace I8080;

namespace
{
    //opcode IDs and jump table - TODO make this a member
    using Opcode = void(*)();
    std::array<Opcode, 256> opcodes; //TODO initialise this when opcode implemented

    //maps number of I8080 cycles take by each opcode
    const std::array<Byte, 256> opCycles = 
    {
        4,  10, 7,  5,  5,  5,  7,  4,  0,  10, 7,  5,  5,  5,  7,  4,
        0,  10, 7,  5,  5,  5,  7,  4,  0,  10, 7,  5,  5,  5,  7,  4,
        0,  10, 16, 5,  5,  5,  7,  4,  0,  10, 7,  5,  5,  5,  7,  11,
        0,  10, 13, 0,  5,  5,  7,  0,  0,  10, 13, 5,  5,  5,  7,  0,
        5,  5,  5,  5,  5,  5,  5,  4,  5,  5,  5,  5,  5,  5,  5,  11,
        5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
        5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
        5,  5,  5,  5,  5,  5,  7,  5,  5,  5,  5,  5,  5,  5,  5,  5,
        4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
        4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
        4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
        4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
        5,  10, 10, 10, 11, 11, 0,  11, 11, 10, 0,  10, 11, 17, 7,  11,
        5,  10, 10, 10, 11, 11, 7,  11, 11, 0,  10, 10, 11, 0,  7,  11,
        11, 10, 10, 18, 11, 11, 7,  11, 11, 5,  10, 4,  11, 0,  7,  11,
        11, 10, 10, 4,  11, 11, 7,  11, 11, 5,  10, 4,  11, 0,  7,  11
    };
}

CPU::Registers::Registers()
    : A(m_a), B(m_bc.b.h), C(m_bc.b.l), D(m_de.b.h), E(m_de.b.l), H(m_hl.b.h), L(m_hl.b.l),
    M(m_hl.w), BC(m_bc.w), DE(m_de.w), HL(m_hl.w), programCounter(m_programCounter.w), stackPointer(m_stackPointer.w),
    m_a(0)
{
    m_bc.w = 0;
    m_de.w = 0;
    m_hl.w = 0;
    m_programCounter.w = 0;
    m_stackPointer.w = 0xFFFF; //stack is at end of RAM and moves downwards
}

CPU::CPU()
    : m_cycleCount      (0),
    m_currentOpcode     (0),
    m_shiftByte0        (0),
    m_shiftByte1        (0),
    m_shiftOffset       (0),
    m_stopped           (false),
    m_interruptEnabled  (false),
    m_interruptPending  (0)
{
    m_registers.BC = 0;
    m_registers.DE = 0;
    m_registers.HL = 0;
    m_registers.programCounter = 0;
    m_registers.stackPointer = 0xFFFF;

    m_flags.psw = 0;
    m_flags.s = 0;
    m_flags.z = 0;
    m_flags.ac = 0;
    m_flags.p = 0;
    m_flags.cy = 0;

    std::memset(m_memory.data(), 0, MEM_SIZE);
    std::memset(m_ports.data(), 0, sizeof(Word) * PORT_COUNT);
}

//public
void CPU::reset()
{   
    m_cycleCount = 0;
    m_currentOpcode = 0;
    m_shiftByte0 = 0;
    m_shiftByte1 = 0;
    m_shiftOffset = 0;
    m_stopped = false;
    m_interruptEnabled = false;
    m_interruptPending = 0;

    m_registers.A = 0;
    m_registers.BC = 0;
    m_registers.DE = 0;
    m_registers.HL = 0;
    m_registers.programCounter = 0;
    m_registers.stackPointer = 0xFFFF;

    m_flags.psw = 0;
    m_flags.s = 0;
    m_flags.z = 0;
    m_flags.ac = 0;
    m_flags.p = 0;
    m_flags.cy = 0;

    std::memset(m_memory.data(), 0, MEM_SIZE);
    std::memset(m_ports.data(), 0, sizeof(Word) * PORT_COUNT);
}

void CPU::update(std::int32_t count)
{
    assert(count > 0);

    //fetch the opcode from memory
    //then execute it and update the number of CPU
    //cycles taken for that opcode
    m_cycleCount = count;
    while (m_cycleCount)
    {
        m_currentOpcode = m_memory[m_registers.programCounter];
        opcodes[m_currentOpcode]();
        m_cycleCount -= opCycles[m_currentOpcode];
    }
}

void CPU::raiseInterrupt(Byte id)
{
    static const int ISR_Size = 8;
    static const int ISR_Cycles = 11;

    if (m_interruptEnabled)
    {
        m_interruptEnabled = false;
        m_interruptPending = 0;
        //push the current working position on to the stack
        pushWord(m_registers.programCounter);
        //jump the program counter to the ISR address
        m_registers.programCounter = id * ISR_Size;
        m_cycleCount -= ISR_Cycles;
    }
    else
    {
        m_interruptPending = 0x80 | id;
    }
}

bool CPU::loadROM(const std::string& path, Word address)
{
    return false;
}

//private
void CPU::pushWord(Word word)
{
    m_registers.stackPointer -= 2;
    m_memory[m_registers.stackPointer] = word & 0x00FF;
    m_memory[m_registers.stackPointer + 1] = ((word >> 8) & 0xFF);
}

Word CPU::popWord()
{
    auto word = (m_memory[m_registers.stackPointer] << 8) | m_memory[m_registers.stackPointer];
    m_registers.stackPointer += 2;
    return word;
}
