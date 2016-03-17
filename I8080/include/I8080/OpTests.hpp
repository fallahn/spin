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

#ifndef I8080_TESTS_HPP_
#define I8080_TESTS_HPP_

#ifdef OP_TEST

//move instructions
void testMOV();


//load immediate register BC
void testLXIB();
//load immediate register DE
void testLXID();
//load immediate register LH
void testLXIH();
//load immediate register SP
void testLXISP();
//
void testLHLD();
//
void testSHLD();
//
void testSPHL();


//swap register DE, HL
void testXCHG();
//swap register HL with value on stack
void testXTHL();

//load mem@BC into A
void testLDAXB();
//load mem@DE into A
void testLDAXD();
//store A into mem @BC
void testSTAXB();
//store A in mem@DE
void testSTAXD();
//load mem@PC into A
void testLDA();
//store A in mem@PC
void testSTA();

//move immediate instructions
void testMVI();

//add register to accumulator
void testADD();
//
void testADC();

//subtract register from accumulator
void testSUB();
//
void testSBB();

//double add instructions
void testDAD();


//tests control instructions
void testCONT();

//increment 8 bit registers
void testINC8();
//decrement 8 bit registers
void testDEC8();

//increment 16 bit registers
void testINC16();
//decrement 16 bit registers
void testDEC16();

//
void testRLC();
//
void testRRC();
//
void testRAL();
//
void testRAR();

//test 8 bit AND, XOR, OR
void testLogic();

//
void testJMP();
//
void testJNZ();
//
void testJZ();
//
void testJNC();
//
void testJC();
//
void testJPO();
//
void testJPE();
//
void testJP();
//
void testJM();
//
void testPCHL();

//
void testCALL();
//
void testCNZ();
//
void testCZ();
//
void testCNC();
//
void testCC();
//
void testCPO();
//
void testCPE();
//
void testCP();
//
void testCM();

//
void testRET();
//
void testRNZ();
//
void testRZ();
//
void testRNC();
//
void testRC();
//
void testRPO();
//
void testRPE();
//
void testRP();
//
void testRM();

//
void testRST0();
//
void testRST1();
//
void testRST2();
//
void testRST3();
//
void testRST4();
//
void testRST5();
//
void testRST6();
//
void testRST7();


//
void testPUSHB();
//
void testPUSHD();
//
void testPUSHH();
//
void testPUSHPSW();
//
void testPOPB();
//
void testPOPD();
//
void testPOPH();
//
void testPOPPSW();

void runTests()
{
    testMOV();

    testLXIB();
    testLXID();
    testLXIH();
    testLXISP();
    testLHLD();
    testSHLD();
    testSPHL();

    testXCHG();
    testXTHL();

    testLDAXB();
    testLDAXD();
    testSTAXB();
    testSTAXD();
    testLDA();
    testSTA();

    testMVI();

    testADD();
    testADC();

    testSUB();
    testSBB();

    testDAD();

    testCONT();

    testINC8();
    testDEC8();

    testINC16();
    testDEC16();

    testRRC();
    testRLC();
    testRAR();
    testRAL();

    testLogic();

    testJMP();
    testJNZ();
    testJZ();
    testJNC();
    testJC();
    testJPO();
    testJPE();
    testJP();
    testJM();
    testPCHL();

    testCALL();
    testCNZ();
    testCZ();
    testCNC();
    testCC();
    testCPO();
    testCPE();
    testCP();
    testCM();

    testRET();
    testRNZ();
    testRZ();
    testRNC();
    testRC();
    testRPO();
    testRPE();
    testRP();
    testRM();

    testRST0();
    testRST1();
    testRST2();
    testRST3();
    testRST4();
    testRST5();
    testRST6();
    testRST7();

    testPUSHB();
    testPUSHD();
    testPUSHH();
    testPUSHPSW();
    testPOPB();
    testPOPD();
    testPOPH();
    testPOPPSW();
}

#endif //OP_TEST

#endif //I8080_TESTS_HPP_