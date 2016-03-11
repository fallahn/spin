#include "stdafx.h"
#include "CppUnitTest.h"

#include <I8080/I8080.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace I8080;

namespace UnitTest8080
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(movab)
		{
            I8080::CPU cpu;
            //cpu.m_registers.A = 0;
            
		}

	};
}