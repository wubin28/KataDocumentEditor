#include "CppUnitLite/TestHarness.h"
#include "CppUnitLite/TestDefaultConfig.h"
#include "DocumentEditorFacade.h"


int main(int argc, char* argv[]) {
	CommandLineTestRunner::RunAllTests(argc, argv);
	return 0;
}

TEST( DocumentEditorFacade, drawScreen) {
    // Given
    DocumentEditorFacade documentEditorFacade("Do not dwell in the past, do not dream  of the future, concentrate the mind on  the present moment.");
    documentEditorFacade.setColor(0, 7, 5, "red");
    documentEditorFacade.setColor(0, 20, 4, "orange");
    documentEditorFacade.setColor(0, 33, 5, "yellow");
    documentEditorFacade.setColor(1, 7, 6, "green");
    documentEditorFacade.setColor(1, 15, 11, "blue");
    documentEditorFacade.setColor(1, 31, 4, "indigo");
    documentEditorFacade.setColor(2, 12, 6, "violet");

    // When
    documentEditorFacade.drawScreen();

    // Then
    STRCMP_EQUAL("D-black", documentEditorFacade.getScreenDrawnResult(0,0).c_str());
    STRCMP_EQUAL("d-red", documentEditorFacade.getScreenDrawnResult(0, 7).c_str());
    STRCMP_EQUAL("l-red", documentEditorFacade.getScreenDrawnResult(0, 11).c_str());
    STRCMP_EQUAL("p-orange", documentEditorFacade.getScreenDrawnResult(0, 20).c_str());
    STRCMP_EQUAL("d-yellow", documentEditorFacade.getScreenDrawnResult(0, 33).c_str());
    STRCMP_EQUAL("u-green", documentEditorFacade.getScreenDrawnResult(1, 8).c_str());
    STRCMP_EQUAL("c-blue", documentEditorFacade.getScreenDrawnResult(1, 15).c_str());
    STRCMP_EQUAL("m-indigo", documentEditorFacade.getScreenDrawnResult(1, 31).c_str());
    STRCMP_EQUAL("m-violet", documentEditorFacade.getScreenDrawnResult(2, 12).c_str());
    STRCMP_EQUAL("t-violet", documentEditorFacade.getScreenDrawnResult(2,17).c_str());
}
