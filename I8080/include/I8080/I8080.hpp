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
#include <functional>
#include <vector>

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
        /*!
        \brief Used to handle the Input Opcode.
        Function receives a byte representing the
        port number of the I/O to be affected, and
        returns a value which is the result of the
        operation on that port
        */
        using InputHandler = std::function<Byte(Byte)>;
        /*!
        \brief Used to handle the Output Opcode.
        Function receives a byte representing the output
        port number, and the current value of the A register
        */
        using OutputHandler = std::function<void(Byte, Byte)>;

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
        \returns Number of cycles actually executed
        */
        std::int32_t update(std::int32_t);
        /*!
        \brief Raise an interrupt with the given ID
        */
        void raiseInterrupt(Byte);
        /*!
        \brief Load a ROM file into the given address.
        ROMS tend to be split into multiple files and
        each loaded into different parts of memory
        */
        bool loadROM(const std::string&, Word, bool reset = true);

        /*!
        \brief Outputs some info in a string
        */
        std::string getInfo() const;

        /*!
        \brief Returns a pointer to the start of VRAM
        */
        const Byte* getVRAM() const;

        /*!
        \brief Sets the input handling function
        */
        void setInputHandler(const InputHandler& ih) { handleInput = ih; }

        /*!
        \brief Sets the output handling function
        */
        void setOutputHandler(const OutputHandler& oh) { handleOutput = oh; }

#ifdef DEBUG_TOOLS
        void disassemble();
#endif //DEBUG_TOOLS

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
            Byte cy     : 1; //carry flag
            Byte pad1   : 1;
            Byte p      : 1; //parity flag
            Byte pad2   : 1;
            Byte ac     : 1; //aux carry flag
            Byte pad3   : 1;
            Byte z      : 1; //zero flag
            Byte s      : 1; //sign flag
        }m_flags;

        std::int32_t m_cycleCount;

        Byte m_currentOpcode;
        std::array<Byte, MEM_SIZE> m_memory;

        bool m_interruptEnabled;
        Byte m_interruptPending; //flags of interrupt IDs

        void pushWord(Word);
        Word popWord();

        Word getWord(Word);

        void inline setParity(std::int16_t);

        std::function<Byte(Byte)> handleInput;
        std::function<void(Byte, Byte)> handleOutput;

        //opcode list is pretty large so it has its
        //own header file included here
#define OP_INCLUDE
#include <I8080/Opcodes.hpp>
#undef OP_INCLUDE

        //unit tests for opcodes
#ifdef OP_TEST
#include <I8080/OpTests.hpp>
#endif // OP_TEST

#ifdef DEBUG_TOOLS
        struct Dasm final
        {
            enum class Type
            {
                Opcode,
                Operand
            };
            
            std::string mnem;
            Byte operand0 = 0;
            Byte operand1 = 0;
            Type type = Type::Opcode;
        };
        std::vector<Dasm> m_disassembly;

        class RBuff final
        {
        public:
            void push(Word);
            Word operator [](std::size_t) const;
        private:
            std::array<Word, 20> m_buff;
            std::size_t m_idx = 0;
        }m_callstack;
#endif //DEBUG_TOOLS

    };
}
#endif //I8080_HPP_