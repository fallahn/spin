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

#ifndef I8080_HPP_
#define I8080_HPP_

#include <cstdint>
#include <string>
#include <array>

using Byte = std::uint8_t;
using Word = std::uint16_t;

namespace I8080
{
    constexpr std::uint16_t MEM_SIZE = 0xFFFF;
    constexpr std::uint8_t  PORT_COUNT = 9;

    /*!
    \brief Emulates the Intel 8080 CPU
    */
    class CPU final
    {
    public:
        CPU();
        ~CPU() = default;

        CPU(const CPU&) = delete;
        CPU& operator = (const CPU&) = delete;

        /*!
        \brief Reset the CPU
        */
        void reset();
        /*!
        \brief Execute given number of emulation cycles
        */
        void update(std::int32_t);
        /*!
        \brief Raise an interrupt with the given ID
        */
        void raiseInterrupt(Byte);
        /*!
        \brief Load a ROM file into the given address.
        ROMS tend to be split into multiple files and
        each loaded into different parts of memory
        */
        bool loadROM(const std::string&, Word);

        /*!
        \brief Outputs some info in a string
        */
        std::string getInfo() const;

    private:

        using Opcode = void (CPU::*)();
        std::array<Opcode, 256> m_opcodes;

        struct Registers final
        {
        public:
            Registers();
            ~Registers() = default;
            Registers(const Registers&) = delete;
            Registers& operator = (const Registers&) = delete;

            Byte& A;
            Byte& B;
            Byte& C;
            Byte& D;
            Byte& E;
            Byte& H;
            Byte& L;
            Word& M;
            Word& BC;
            Word& DE;
            Word& HL;

            Word& programCounter;
            Word& stackPointer;

        private:
            //register pair (little endian on 8080)
            union Register
            {
                Word w;
                struct
                {
                    Byte l, h;
                }b;
            };
            Byte m_a;
            Register m_bc;
            Register m_de;
            Register m_hl;
            Register m_programCounter;
            Register m_stackPointer; //stack is at end of RAM and moves downwards
        }m_registers;

        struct
        {            
            Byte s       : 1; //sign flag
            Byte z       : 1; //zero flag
            Byte ac      : 1; //aux carry flag
            Byte p       : 1; //parity flag
            Byte cy      : 1; //carry flag
            Byte padding : 3;
            Byte psw     = 0;         //processor status word
        }m_flags;

        std::int32_t m_cycleCount;

        Byte m_currentOpcode;
        std::array<Byte, MEM_SIZE> m_memory;

        std::array<Word, PORT_COUNT> m_ports;

        Byte m_shiftByte0;
        Byte m_shiftByte1;
        Byte m_shiftOffset;

        bool m_stopped;
        bool m_interruptEnabled;
        Byte m_interruptPending; //flags of interrupt IDs

        void pushWord(Word);
        Word popWord();

        Word getWord(Word);

        void inline setParity(std::int16_t);
        void inline setPSW();
        void inline getFlagsFromPSW();

        //opcode list is pretty large so it has its
        //own header file included here
#define OP_INCLUDE
#include <I8080/Opcodes.hpp>
#undef OP_INCLUDE
    };
}
#endif //I8080_HPP_