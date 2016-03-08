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

#ifndef I8080_OP_HPP_
#define I8080_OP_HPP_

//these should only be defined within the I8080 CPU class
//so including this elsewhere should result in nada.

//full list of opcodes:
//http://nemesis.lonestar.org/computers/tandy/software/apps/m4/qd/opcodes.html

#ifdef OP_INCLUDE
void notImpl(); //illegal or not yet implemented

//8 bit transfer instructions
void movaa(); void movab(); void movac(); void movad(); void movae(); void movah(); void moval(); void movam();
void movba(); void movbb(); void movbc(); void movbd(); void movbe(); void movbh(); void movbl(); void movbm();
void movca(); void movcb(); void movcc(); void movcd(); void movce(); void movch(); void movcl(); void movcm();
void movda(); void movdb(); void movdc(); void movdd(); void movde(); void movdh(); void movdl(); void movdm();
void movea(); void moveb(); void movec(); void moved(); void movee(); void moveh(); void movel(); void movem();
void movha(); void movhb(); void movhc(); void movhd(); void movhe(); void movhh(); void movhl(); void movhm();
void movla(); void movlb(); void movlc(); void movld(); void movle(); void movlh(); void movll(); void movlm();
void movma(); void movmb(); void movmc(); void movmd(); void movme(); void movmh(); void movml();

//16 bit transfer instructions
void lxib();  void lxid();  void lxih(); void lxisp(); void lhld();  void shld(); void sphl();
void ldaxb(); void ldaxd(); void lda();  void staxb(); void staxd(); void sta();

//register exchange instructions
void xchg(); void xthl();

//8 bit ADD instructions
void inline accumulate(std::int16_t);
void adda(); void addb(); void addc(); void addd(); void adde(); void addh(); void addl(); void addm(); void adi();

//8 bit ADC add with carry instructions
void adca(); void adcb(); void adcc(); void adcd(); void adce(); void adch(); void adcl(); void adcm(); void aci();

//8 bit SUB instructions
void suba(); void subb(); void subc(); void subd(); void sube(); void subh(); void subl(); void subm(); void sui();

//16 bit SBB sub with borrow instructions
void sbba(); void sbbb(); void sbbc(); void sbbd(); void sbbe(); void sbbh(); void sbbl(); void sbbm(); void sbi();

//16 bit DAD add instructions
void dadb(); void dadd(); void dadh(); void dadsp();

//8 bit control instructions
void di(); void ei(); void nop(); void hlt();

//8 bit INC instructions
void inline inc8(std::int16_t, std::uint8_t);
void inra(); void inrb(); void inrc(); void inrd(); void inre(); void inrh(); void inrl(); void inrm();

//8 bit DEC instructions
void dcra(); void dcrb(); void dcrc(); void dcrd(); void dcre(); void dcrh(); void dcrl(); void dcrm();

//8 bit INX pair instructions
void inxb(); void inxd(); void inxh(); void inxsp();

//8 bit DCX pair instructions
void dcxb(); void dcxd(); void dcxh(); void dcxsp();

//accumulator and flag special instructions
void daa(); void cma(); void stc(); void cmc();

//rotate instructions
void rlc(); void rrc(); void ral(); void rar();

//-----logic instructions-----//
//AND
void inline bitlogic(std::int16_t);
void anaa(); void anab(); void anac(); void anad(); void anae(); void anah(); void anal(); void anam(); void ani();
//XOR
void xraa(); void xrab(); void xrac(); void xrad(); void xrae(); void xrah(); void xral(); void xram(); void xri();
//OR
void oraa(); void orab(); void orac(); void orad(); void orae(); void orah(); void oral(); void oram(); void ori();
//compare
void inline compare(std::int16_t);
void cmpa(); void cmpb(); void cmpc(); void cmpd(); void cmpe(); void cmph(); void cmpl(); void cmpm(); void cpi();

//----branching instructions----//
//jump
void jmp(); void jnz(); void jz(); void jnc(); void jc(); void jpo(); void jpe(); void jp(); void jm(); void pchl();
//call
void call(); void cnz(); void cz(); void cnc(); void cc(); void cpo(); void cpe(); void cp(); void cm();
//return
void ret(); void rnz(); void rz(); void rnc(); void rc(); void rpo(); void rpe(); void rp(); void rm();
//RST
void rst0(); void rst1(); void rst2(); void rst3(); void rst4(); void rst5(); void rst6(); void rst7();

//stack operation instructions
void pushb(); void pushd(); void pushh(); void pushpsw(); void popb(); void popd(); void poph(); void poppsw();

//IO
void in(); void out();

//16 bit transfer immediate instructions
void mvia(); void mvib(); void mvic(); void mvid(); void mvie(); void mvih(); void mvil(); void mvim();

#endif //OP_INCLUDE

#endif //I8080_OP_HPP_