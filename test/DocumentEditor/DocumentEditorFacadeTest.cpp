#include "CppUnitLite/TestHarness.h"
#include "CppUnitLite/TestDefaultConfig.h"
#include "DocumentEditorFacade.h"

int main(int argc, char* argv[])
{
	CommandLineTestRunner::RunAllTests(argc, argv);
	return 0;
}

TEST( DocumentEditorFacade, creation)
{
    DocumentEditorFacade documentEditorFacade;
    CHECK ( 1 == documentEditorFacade.sayOne() );
    LONGS_EQUAL ( 1 , documentEditorFacade.sayOne() );
    CHECK ( "Hello!" == documentEditorFacade.sayHello() );
}
