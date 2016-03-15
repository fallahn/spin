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

#ifdef OP_TEST

#include <I8080/I8080.hpp>

#include <iostream>

using namespace I8080;

void CPU::testLXIB()
{
    m_registers.programCounter = 0;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;
    m_registers.BC = 0;

    lxib();

    if (m_registers.programCounter != 3)
    {
        std::cout << "LXIB test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.BC != 0x2010)
    {
        std::cout << "LXIB test failed: BC value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LXIB test passed!" << std::endl;
    }
}
void CPU::testLXID()
{
    m_registers.programCounter = 0;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;
    m_registers.DE = 0;
    lxid();

    if (m_registers.programCounter != 3)
    {
        std::cout << "LXID test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.DE != 0x2010)
    {
        std::cout << "LXID test failed: DE value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LXID test passed!" << std::endl;
    }
}
void CPU::testLXIH()
{
    m_registers.programCounter = 0;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;
    m_registers.HL = 0;
    lxih();

    if (m_registers.programCounter != 3)
    {
        std::cout << "LXIH test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.HL != 0x2010)
    {
        std::cout << "LXIH test failed: HL value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LXIH test passed!" << std::endl;
    }
}
void CPU::testLXISP()
{
    m_registers.programCounter = 0;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;
    m_registers.stackPointer = 0;

    lxisp();

    if (m_registers.programCounter != 3)
    {
        std::cout << "LXISP test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0x2010)
    {
        std::cout << "LXISP test failed: SP value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LXISP test passed!" << std::endl;
    }
}
void CPU::testLHLD()
{
    m_registers.programCounter = 0;
    m_memory[1] = 20;
    m_memory[2] = 0;
    m_memory[20] = 0x10;
    m_memory[21] = 0x20;
    m_registers.HL = 0;

    lhld();

    if (m_registers.programCounter != 3)
    {
        std::cout << " LHLD test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.HL != 0x2010)
    {
        std::cout << "LHLD test failed: HL register value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LHLD test passed!" << std::endl;
    }
}
void CPU::testSHLD()
{
    m_registers.programCounter = 0;
    m_memory[1] = 20;
    m_registers.HL = 0x2010;
    m_memory[20] = 0;
    m_memory[21] = 0;

    shld();

    if (m_registers.programCounter != 3)
    {
        std::cout << "SHLD test failed: program counter incorrect" << std::endl;
    }
    else if (m_memory[20] != 0x10 || m_memory[21] != 0x20)
    {
        std::cout << "SHLD test failed: memory value incorrect" << std::endl;
    }
    else
    {
        std::cout << "SHLD test passed!" << std::endl;
    }
}
void CPU::testSPHL()
{
    m_registers.programCounter = 0;
    m_registers.HL = 0x2010;
    m_registers.stackPointer = 0;

    sphl();

    if (m_registers.programCounter != 1)
    {
        std::cout << "SPHL test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0x2010)
    {
        std::cout << "SPHL test failed: stack pointer value incorrect" << std::endl;
    }
    else
    {
        std::cout << "SPHL test passed!" << std::endl;
    }
}

void CPU::testXCHG()
{
    m_registers.programCounter = 0;
    m_registers.HL = 0x2010;
    m_registers.DE = 0x4030;

    xchg();

    if (m_registers.programCounter != 1)
    {
        std::cout << "XCHG test failed: program counter value incorrect" << std::endl;
    }
    else if(m_registers.HL != 0x4030 || m_registers.DE != 0x2010)
    {
        std::cout << "XCHG test failed: register values incorrect" << std::endl;
    }
    else
    {
        std::cout << "XCHG test passed!" << std::endl;
    }
}
void CPU::testXTHL()
{
    m_registers.programCounter = 0;
    m_registers.stackPointer = 0xEFF8;
    m_memory[0xEFF8] = 0x10;
    m_memory[0xEFF9] = 0x20;
    m_registers.HL = 0;

    xthl();

    if (m_registers.programCounter != 1)
    {
        std::cout << "XTHL test failed: program counter incorrect" << std::endl;
    }
    else if (m_memory[0xEFF8] != 0 || m_memory[0xEFF9] != 0)
    {
        std::cout << "XTHL test failed: resulting memory value incorrect" << std::endl;
    }
    else if (m_registers.HL != 0x2010)
    {
        std::cout << "XTHL test failed: HL register value incorrect" << std::endl;
    }
    else
    {
        std::cout << "XTHL test passed!" << std::endl;
    }
}

void CPU::testLDAXB()
{
    m_registers.programCounter = 0;
    m_registers.A = 0;
    m_registers.BC = 20;
    m_memory[20] = 0x10;

    ldaxb();

    if (m_registers.programCounter != 1)
    {
        std::cout << "LDAXB test failed: program counter value incorrect" << std::endl;
    }
    else if (m_registers.A != 0x10)
    {
        std::cout << "LDAXB test failed: A value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LDAXB test passed!" << std::endl;
    }
}
void CPU::testLDAXD()
{
    m_registers.programCounter = 0;
    m_registers.A = 0;
    m_registers.DE = 20;
    m_memory[20] = 0x10;

    ldaxd();

    if (m_registers.programCounter != 1)
    {
        std::cout << "LDAXD test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.A != 0x10)
    {
        std::cout << "LDAXD test failed: A value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LDAXD test passed!" << std::endl;
    }
}
void CPU::testSTAXB()
{
    m_registers.programCounter = 0;
    m_registers.A = 0x10;
    m_registers.BC = 20;
    m_memory[20] = 0;

    staxb();

    if (m_registers.programCounter != 1)
    {
        std::cout << "STAXB test failed: program counter value incorrect" << std::endl;
    }
    else if (m_memory[20] != 0x10)
    {
        std::cout << "STAXB test failed: memory value incorrect" << std::endl;
    }
    else
    {
        std::cout << "STAXB test passed!" << std::endl;
    }
}
void CPU::testSTAXD() 
{
    m_registers.programCounter = 0;
    m_registers.A = 0x10;
    m_registers.DE = 20;
    m_memory[20] = 0;

    staxd();

    if (m_registers.programCounter != 1)
    {
        std::cout << "STAXD test failed: program counter incorrect" << std::endl;
    }
    else if (m_memory[20] != 0x10)
    {
        std::cout << "STAXD test failed: memory value incorrect" << std::endl;
    }
    else
    {
        std::cout << "STAXD test passed!" << std::endl;
    }
}
void CPU::testLDA() 
{
    m_registers.programCounter = 0;
    m_registers.A = 0;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;

    m_memory[0x2010] = 20;

    lda();

    if (m_registers.programCounter != 3)
    {
        std::cout << "LDA test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.A != 20)
    {
        std::cout << "LDA test failed: A value incorrect" << std::endl;
    }
    else
    {
        std::cout << "LDA test passed!" << std::endl;
    }
}
void CPU::testSTA()
{
    m_registers.programCounter = 0;
    m_registers.A = 20;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;
    m_memory[0x2010] = 0;

    sta();

    if (m_registers.programCounter != 3)
    {
        std::cout << "STA test failed: program counter incorrect" << std::endl;
    }
    else if (m_memory[0x2010] != 20)
    {
        std::cout << "STA test failed: memory value incorrect" << std::endl;
    }
    else
    {
        std::cout << "STA test passed!" << std::endl;
    }
}

void CPU::testINC8()
{
    m_registers.programCounter = 0;
    m_registers.A = 0;
    m_registers.B = 0;
    m_registers.C = 0;
    m_registers.D = 0;
    m_registers.E = 0;
    m_registers.H = 0;
    m_registers.L = 0;

    m_memory[0x0101] = 20;

    inra();
    inrb();
    inrc();
    inrd();
    inre();
    inrh();
    inrl();
    inrm();

    if (m_registers.programCounter != 8)
    {
        std::cout << "INC8 test failed: incorrect program counter" << std::endl;
    }
    else if (m_registers.A != 1)
    {
        std::cout << "INC8 test failed: A not incrememnted" << std::endl;
    }
    else if (m_registers.B != 1)
    {
        std::cout << "INC8 test failed: B not incremented" << std::endl;
    }
    else if (m_registers.C != 1)
    {
        std::cout << "INC8 test failed: C not incremented" << std::endl;
    }
    else if (m_registers.D != 1)
    {
        std::cout << "INC8 test failed: D not incremented" << std::endl;
    }
    else if (m_registers.E != 1)
    {
        std::cout << "INC8 test failed: E not incremented" << std::endl;
    }
    else if (m_registers.H != 1)
    {
        std::cout << "INC8 test failed: H not incremented" << std::endl;
    }
    else if (m_registers.L != 1)
    {
        std::cout << "INC8 test failed: L not incremented" << std::endl;
    }
    else if (m_memory[m_registers.M] != 21)
    {
        std::cout << "INC8 test failed: M not incremented" << std::endl;
    }
    else
    {
        std::cout << "INC8 test passed!" << std::endl;
    }
}
void CPU::testDEC8()
{
    m_registers.programCounter = 0;
    m_registers.A = 1;
    m_registers.B = 1;
    m_registers.C = 1;
    m_registers.D = 1;
    m_registers.E = 1;
    m_registers.H = 1;
    m_registers.L = 1;

    m_memory[0] = 20;

    dcra();
    dcrb();
    dcrc();
    dcrd();
    dcre();
    dcrh();
    dcrl();
    dcrm();

    if (m_registers.programCounter != 8)
    {
        std::cout << "DEC8 test failed: program counter incorrect" << std::endl;
    }
    else if(m_registers.A != 0)
    {
        std::cout << "DEC8 test failed: A incorrect" << std::endl;
    }
    else if (m_registers.B != 0)
    {
        std::cout << "DEC8 test failed: B incorrect" << std::endl;
    }
    else if (m_registers.C != 0)
    {
        std::cout << "DEC8 test failed: C incorrect" << std::endl;
    }
    else if (m_registers.D != 0)
    {
        std::cout << "DEC8 test failed: D incorrect" << std::endl;
    }
    else if (m_registers.E != 0)
    {
        std::cout << "DEC8 test failed: E incorrect" << std::endl;
    }
    else if (m_registers.H != 0)
    {
        std::cout << "DEC8 test failed: H incorrect" << std::endl;
    }
    else if (m_registers.L != 0)
    {
        std::cout << "DEC8 test failed: L incorrect" << std::endl;
    }
    else if (m_memory[m_registers.M] != 19)
    {
        std::cout << "DEC8 test failed: M incorrect" << std::endl;
    }
    else
    {
        std::cout << "DEC8 test passed!" << std::endl;
    }
}

void CPU::testINC16()
{
    m_registers.programCounter = 0;
    m_registers.BC = 0;
    m_registers.DE = 0;
    m_registers.HL = 0;
    m_registers.stackPointer = 0;

    inxb();
    inxd();
    inxh();
    inxsp();

    if (m_registers.programCounter != 4)
    {
        std::cout << "INC16 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.BC != 1)
    {
        std::cout << "INC16 test failed: BC incorrect" << std::endl;
    }
    else if (m_registers.DE != 1)
    {
        std::cout << "INC16 test failed: DE incorrect" << std::endl;
    }
    else if (m_registers.HL != 1)
    {
        std::cout << "INC16 test failed: HL incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 1)
    {
        std::cout << "INC16 test failed: SP incorrect" << std::endl;
    }
    else
    {
        std::cout << "INC16 test passed!" << std::endl;
    }
}
void CPU::testDEC16()
{
    m_registers.programCounter = 0;
    m_registers.BC = 1;
    m_registers.DE = 1;
    m_registers.HL = 1;
    m_registers.stackPointer = 1;

    dcxb();
    dcxd();
    dcxh();
    dcxsp();

    if (m_registers.programCounter != 4)
    {
        std::cout << "DEC16 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.BC != 0)
    {
        std::cout << "DEC16 test failed: BC incorrect" << std::endl;
    }
    else if (m_registers.DE != 0)
    {
        std::cout << "DEC16 test failed: DE incorrect" << std::endl;
    }
    else if (m_registers.HL != 0)
    {
        std::cout << "DEC16 test failed: HL incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0)
    {
        std::cout << "DEC16 test failed: SP incorrect" << std::endl;
    }
    else
    {
        std::cout << "DEC16 test passed!" << std::endl;
    }
}

void CPU::testRRC()
{
    m_registers.programCounter = 0;
    m_registers.A = 2;

    rrc();

    if (m_registers.programCounter != 1)
    {
        std::cout << "RRC test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.A != 1)
    {
        std::cout << "RRC test failed: value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RRC test passed!" << std::endl;
    }
}
void CPU::testRLC()
{
    m_registers.programCounter = 0;
    m_registers.A = 1;

    rlc();

    if (m_registers.programCounter != 1)
    {
        std::cout << "RLC test failed: program counter incorrect" <<std::endl;
    }
    else if (m_registers.A != 2)
    {
        std::cout << "RLC test failed: A incorrect value" << std::endl;
    }
    else
    {
        std::cout << "RLC test passed!" << std::endl;
    }
}
void CPU::testRAR()
{
    m_registers.programCounter = 0;
    m_registers.A = 2;

    rrc();

    if (m_registers.programCounter != 1)
    {
        std::cout << "RAR test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.A != 1)
    {
        std::cout << "RAR test failed: value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RAR test passed!" << std::endl;
    }
}
void CPU::testRAL()
{
    m_registers.programCounter = 0;
    m_registers.A = 1;

    rlc();

    if (m_registers.programCounter != 1)
    {
        std::cout << "RAL test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.A != 2)
    {
        std::cout << "RAL test failed: A incorrect value" << std::endl;
    }
    else
    {
        std::cout << "RAL test passed!" << std::endl;
    }
}

void CPU::testLogic()
{
    //TODO expand this out to every opcode
    m_registers.programCounter = 0;
    m_registers.A = 0;
    m_registers.B = 1;
    m_registers.C = 2;
    m_registers.D = 4;

    anab();
    if (m_registers.A != 0)
    {
        std::cout << "AND test failed: A incorrect" << std::endl;
        return;
    }
    xrac();
    if (m_registers.A != 2)
    {
        std::cout << "XOR test failed: A incorrect" << std::endl;
        return;
    }
    orad();
    if (m_registers.A != 6)
    {
        std::cout << "OR test failed: A incorrect" << std::endl;
        return;
    }

    if (m_registers.programCounter != 3)
    {
        std::cout << "LOGIC test failed: program counter incorrect" << std::endl;
    }
    else
    {
        std::cout << "LOGIC test passed!" << std::endl;
    }
}

void CPU::testJMP()
{
    m_registers.programCounter = 0;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;

    jmp();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JMP failed test" << std::endl;
    }
    else
    {
        std::cout << "JMP passed test!" << std::endl;
    }
}
void CPU::testJNZ()
{
    m_flags.z = 1;
    m_registers.programCounter = 0;

    jnz();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JNZ test failed: 1" << std::endl;
        return;
    }

    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.z = 0;

    jnz();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JNZ test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JNZ test passed!" << std::endl;
    }
}
void CPU::testJZ()
{
    m_flags.z = 0;
    m_registers.programCounter = 0;

    jz();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JZ test failed: 1" << std::endl;
        return;
    }

    m_flags.z = 1;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;

    jz();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JZ test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JZ test passed!" << std::endl;
    }
}
void CPU::testJNC()
{
    m_flags.cy = 1;
    m_registers.programCounter = 0;

    jnc();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JNC test failed: 1" << std::endl;
        return;
    }

    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.cy = 0;

    jnc();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JNC test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JNC test passed!" << std::endl;
    }
}
void CPU::testJC()
{
    m_flags.cy = 0;
    m_registers.programCounter = 0;

    jc();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JC test failed: 1" << std::endl;
        return;
    }

    m_flags.cy = 1;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;

    jc();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JC test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JC test passed!" << std::endl;
    }
}
void CPU::testJPO()
{
    m_flags.p = 1;
    m_registers.programCounter = 0;

    jpo();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JPO test failed: 1" << std::endl;
        return;
    }

    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.p = 0;

    jpo();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JPO test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JPO test passed!" << std::endl;
    }
}
void CPU::testJPE()
{
    m_flags.p = 0;
    m_registers.programCounter = 0;

    jpe();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JPE test failed: 1" << std::endl;
        return;
    }

    m_flags.p = 1;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;

    jpe();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JPE test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JPE test passed!" << std::endl;
    }
}
void CPU::testJP()
{
    m_flags.s = 1;
    m_registers.programCounter = 0;

    jp();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JP test failed: 1" << std::endl;
        return;
    }

    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.s = 0;

    jp();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JP test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JP test passed!" << std::endl;
    }
}
void CPU::testJM()
{
    m_flags.s = 0;
    m_registers.programCounter = 0;

    jm();

    if (m_registers.programCounter != 3)
    {
        std::cout << "JM test failed: 1" << std::endl;
        return;
    }

    m_flags.s = 1;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;

    jm();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "JM test failed: 2" << std::endl;
    }
    else
    {
        std::cout << "JM test passed!" << std::endl;
    }
}
void CPU::testPCHL()
{
    m_registers.programCounter = 0;
    m_registers.HL = 0x2010;

    pchl();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "PCHL test failed" << std::endl;
    }
    else
    {
        std::cout << "PCHL test passed!" << std::endl;
    }
}

void CPU::testCALL()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[1] = 0x10;
    m_memory[2] = 0x20;

    call();

    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CALL test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CALL test failed: stack pointer incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 3)
    {
        std::cout << "CALL test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CALL test passed!" << std::endl;
    }
}
void CPU::testCNZ()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.z = 1;

    cnz();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CNZ test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.z = 0;

    cnz();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CNZ test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CNZ test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CNZ test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CNZ test passed!" << std::endl;
    }
}
void CPU::testCZ()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.z = 0;

    cz();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CZ test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.z = 1;

    cz();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CZ test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CZ test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CZ test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CZ test passed!" << std::endl;
    }
}
void CPU::testCNC()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.cy = 1;

    cnc();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CNC test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.cy = 0;

    cnc();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CNC test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CNC test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CNC test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CNC test passed!" << std::endl;
    }
}
void CPU::testCC()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.cy = 0;

    cc();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CC test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.cy = 1;

    cc();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CC test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CC test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CC test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CC test passed!" << std::endl;
    }
}
void CPU::testCPO()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.p = 1;

    cpo();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CPO test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.p = 0;

    cpo();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CPO test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CPO test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CPO test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CPO test passed!" << std::endl;
    }
}
void CPU::testCPE()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.p = 0;

    cpe();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CPE test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.p = 1;

    cpe();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CPE test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CPE test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CPE test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CPE test passed!" << std::endl;
    }
}
void CPU::testCP()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.s = 1;

    cp();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CP test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.s = 0;

    cp();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CP test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CP test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CP test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CP test passed!" << std::endl;
    }
}
void CPU::testCM()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_memory[4] = 0x10;
    m_memory[5] = 0x20;
    m_flags.s = 0;

    cm();

    if (m_registers.programCounter != 3)
    {
        std::cout << "CM test failed: program counter incorrect" << std::endl;
        return;
    }

    m_flags.s = 1;

    cm();
    if (m_registers.programCounter != 0x2010)
    {
        std::cout << "CM test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "CM test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != 6)
    {
        std::cout << "CM test failed: stack return value incorrect" << std::endl;
    }
    else
    {
        std::cout << "CM test passed!" << std::endl;
    }
}

void CPU::testRET()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;

    ret();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RET test failed: incorrect stack pointer value" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RET test failed: incorrect program counter value" << std::endl;
    }
    else
    {
        std::cout << "RET test passed!" << std::endl;
    }
}
void CPU::testRNZ()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.z = 1;

    rnz();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RNZ test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.z = 0;

    rnz();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RNZ test failed: stack pointer value incorrect" << std::endl;
    }
    else if(m_registers.programCounter != 0)
    {
        std::cout << "RNZ test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RNZ test passed!" << std::endl;
    }
}
void CPU::testRZ()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.z = 0;

    rz();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RZ test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.z = 1;

    rz();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RZ test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RZ test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RZ test passed!" << std::endl;
    }
}
void CPU::testRNC()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.cy = 1;

    rnc();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RNC test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.cy = 0;

    rnc();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RNC test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RNC test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RNC test passed!" << std::endl;
    }
}
void CPU::testRC()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.cy = 0;

    rc();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RC test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.cy = 1;

    rc();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RC test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RC test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RC test passed!" << std::endl;
    }
}
void CPU::testRPO()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.p = 1;

    rpo();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RPO test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.p = 0;

    rpo();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RPO test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RPO test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RPO test passed!" << std::endl;
    }
}
void CPU::testRPE()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.p = 0;

    rpe();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RPE test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.p = 1;

    rpe();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RPE test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RPE test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RPE test passed!" << std::endl;
    }
}
void CPU::testRP()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.s = 1;

    rp();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RP test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.s = 0;

    rp();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RP test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RP test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RP test passed!" << std::endl;
    }
}
void CPU::testRM()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 3;
    m_memory[m_registers.stackPointer] = 0;
    m_flags.s = 0;

    rm();

    if (m_registers.programCounter != 4)
    {
        std::cout << "RM test failed: incorrect program counter value" << std::endl;
        return;
    }

    m_flags.s = 1;

    rm();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "RM test failed: stack pointer value incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 0)
    {
        std::cout << "RM test failed: program counvet value incorrect" << std::endl;
    }
    else
    {
        std::cout << "RM test passed!" << std::endl;
    }
}

void CPU::testRST0()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst0();

    if (m_registers.programCounter != 0)
    {
        std::cout << "RST0 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST0 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST0 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST0 test passed!" << std::endl;
    }
}
void CPU::testRST1()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst1();

    if (m_registers.programCounter != 0x8)
    {
        std::cout << "RST1 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST1 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST1 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST1 test passed!" << std::endl;
    }
}
void CPU::testRST2()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst2();

    if (m_registers.programCounter != 0x10)
    {
        std::cout << "RST2 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST2 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST2 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST2 test passed!" << std::endl;
    }
}
void CPU::testRST3()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst3();

    if (m_registers.programCounter != 0x18)
    {
        std::cout << "RST3 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST3 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST3 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST3 test passed!" << std::endl;
    }
}
void CPU::testRST4()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst4();

    if (m_registers.programCounter != 0x20)
    {
        std::cout << "RST4 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST4 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST4 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST4 test passed!" << std::endl;
    }
}
void CPU::testRST5()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst5();

    if (m_registers.programCounter != 0x28)
    {
        std::cout << "RST5 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST5 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST5 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST5 test passed!" << std::endl;
    }
}
void CPU::testRST6()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst6();

    if (m_registers.programCounter != 0x30)
    {
        std::cout << "RST6 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST6 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST6 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST6 test passed!" << std::endl;
    }
}
void CPU::testRST7()
{
    m_registers.programCounter = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    rst7();

    if (m_registers.programCounter != 0x38)
    {
        std::cout << "RST7 test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "RST7 test filed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "RST7 test failed: incorrect return value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "RST7 test passed!" << std::endl;
    }
}

void CPU::testPUSHB()
{
    m_registers.programCounter = 0;
    m_registers.BC = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    pushb();

    if (m_registers.programCounter != 1)
    {
        std::cout << "PUSHB test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "PUSHB test failed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "PUSHB test failed: incorrect value on stack" << std::endl;
    }
    else
    {
        std::cout << "PUSHB test passed!" << std::endl;
    }
}
void CPU::testPUSHD()
{
    m_registers.programCounter = 0;
    m_registers.DE = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    pushd();

    if (m_registers.programCounter != 1)
    {
        std::cout << "PUSHD test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "PUSHD test failed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "PUSHD test failed: incorrect value on stack" << std::endl;
    }
    else
    {
        std::cout << "PUSHD test passed!" << std::endl;
    }
}
void CPU::testPUSHH()
{
    m_registers.programCounter = 0;
    m_registers.HL = 0x2010;
    m_registers.stackPointer = 0xFFFF;
    m_memory[m_registers.stackPointer - 2] = 0;

    pushh();

    if (m_registers.programCounter != 1)
    {
        std::cout << "PUSHH test failed: program counter incorrect" << std::endl;
    }
    else if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "PUSHH test failed: stack pointer incorrect" << std::endl;
    }
    else if (getWord(m_registers.stackPointer) != 0x2010)
    {
        std::cout << "PUSHH test failed: incorrect value on stack" << std::endl;
    }
    else
    {
        std::cout << "PUSHH test passed!" << std::endl;
    }
}
void CPU::testPUSHPSW()
{
    m_registers.stackPointer = 0xFFFF;
    m_registers.programCounter = 0;
    m_registers.A = 0x10;
    m_flags.ac = 1;
    m_flags.cy = 1;
    m_flags.p = 1;
    m_flags.s = 1;
    m_flags.z = 1;
    m_flags.psw = 0;

    pushpsw();

    if (m_registers.stackPointer != 0xFFFD)
    {
        std::cout << "PUSHPSW test failed: stack pointer incorrect" << std::endl;
    }
    else if (m_registers.programCounter != 1)
    {
        std::cout << "PUSHPSW test failed: program counter incorrect" << std::endl;
    }
    else if (m_flags.psw != 0b11010101)
    {
        std::cout << "PUSHPSW test failed: psw value incorrect" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer] != m_flags.psw)
    {
        std::cout << "PUSHPSW test failed: incorrect psw pushed on to stack" << std::endl;
    }
    else if (m_memory[m_registers.stackPointer + 1] != m_registers.A)
    {
        std::cout << "PUSHPSW test failed: incorrect A value pushed on to stack" << std::endl;
    }
    else
    {
        std::cout << "PUSHPSW test passed!" << std::endl;
    }
}
void CPU::testPOPB()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 0;
    m_registers.BC = 0;
    m_memory[m_registers.stackPointer] = 0x10;
    m_memory[m_registers.stackPointer + 1] = 0x20;

    popb();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "POPB test failed: incorrect stack pointer value" << std::endl;
    }
    else if (m_registers.programCounter != 1)
    {
        std::cout << "POPB test failed: incorrect program counter value" << std::endl;
    }
    else if (m_registers.BC != 0x2010)
    {
        std::cout << "POPB test failed: BC value incorrect" << std::endl;
    }
    else
    {
        std::cout << "POPB test passed!" << std::endl;
    }
}
void CPU::testPOPD()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 0;
    m_registers.DE = 0;
    m_memory[m_registers.stackPointer] = 0x10;
    m_memory[m_registers.stackPointer + 1] = 0x20;

    popd();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "POPD test failed: incorrect stack pointer value" << std::endl;
    }
    else if (m_registers.programCounter != 1)
    {
        std::cout << "POPD test failed: incorrect program counter value" << std::endl;
    }
    else if (m_registers.DE != 0x2010)
    {
        std::cout << "POPD test failed: BC value incorrect" << std::endl;
    }
    else
    {
        std::cout << "POPD test passed!" << std::endl;
    }
}
void CPU::testPOPH()
{
    m_registers.stackPointer = 0xFFFD;
    m_registers.programCounter = 0;
    m_registers.HL = 0;
    m_memory[m_registers.stackPointer] = 0x10;
    m_memory[m_registers.stackPointer + 1] = 0x20;

    poph();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "POPH test failed: incorrect stack pointer value" << std::endl;
    }
    else if (m_registers.programCounter != 1)
    {
        std::cout << "POPH test failed: incorrect program counter value" << std::endl;
    }
    else if (m_registers.HL != 0x2010)
    {
        std::cout << "POPH test failed: BC value incorrect" << std::endl;
    }
    else
    {
        std::cout << "POPH test passed!" << std::endl;
    }
}
void CPU::testPOPPSW()
{
    m_registers.A = 0;
    m_registers.programCounter = 0;
    m_registers.stackPointer = 0xFFFD;
    m_memory[m_registers.stackPointer] = 0b11010101;
    m_memory[m_registers.stackPointer + 1] = 0x20;

    m_flags.ac = 0;
    m_flags.cy = 0;
    m_flags.p = 0;
    m_flags.s = 0;
    m_flags.z = 0;
    m_flags.psw = 0;

    poppsw();

    if (m_registers.stackPointer != 0xFFFF)
    {
        std::cout << "POPPSW test failed: incorrect stack pointer value" << std::endl;
    }
    else if (m_registers.programCounter != 1)
    {
        std::cout << "POPPSW test failed: incorrect program counter value" << std::endl;
    }
    else if (m_registers.A != 0x20)
    {
        std::cout << "POPPSW test failed: incorrect A value" << std::endl;
    }
    else if (!m_flags.ac || !m_flags.cy || !m_flags.p || !m_flags.s || !m_flags.z)
    {
        std::cout << "POPPSW test failed: incorrect flag value" << std::endl;
    }
    else if (m_flags.psw != 0b11010101)
    {
        std::cout << "POPPSW test failed: incorrect psw value" << std::endl;
    }
    else
    {
        std::cout << "POPPPSW test passed!" << std::endl;
    }
}

#endif //OP_TESTS