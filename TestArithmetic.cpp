#include <WPILib.h>

#include "RUnit/TestApparatus.h"

using namespace RUnit;

INT32 TestAdd()
{
	int a = 1;
	int b = 2;
	
	RU_ASSERT(a + b == 3);
	
	return 0;
}

INT32 TestSubtract()
{
	int a = 3;
	int b = 4;
	
	RU_ASSERT_EQU(a - b, -1);
	
	return 0;
}

INT32 TestMean()
{
	int a = 3;
	int b = 2;
	int c = 7;
	
	int mean = (a + b + c) / 3;
	
	RU_ASSERT_EQU(mean, 4);
	
	return 0;
}

extern "C"
{
	INT32 FRC_UserProgram_StartupLibraryInit()
	{
		TestApparatus app;
		
		app.EnableOption(TestApparatus::OPT_BASIC);
		
		app.RegisterTest((RU_FUNCPTR)TestAdd, "Test Addition");
		app.RegisterTest((RU_FUNCPTR)TestSubtract, "Test Subtraction");
		app((RU_FUNCPTR)TestMean, "Test Mean"); // shorthand register
		
		app.Run();
		
		return 0;
	}
}
