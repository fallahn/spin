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
        std::cout << "CALL test failed: stack return valkue incorrect" << std::endl;
    }
    else
    {
        std::cout << "CALL test passed!" << std::endl;
    }
}