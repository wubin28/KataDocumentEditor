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
    STRCMP_EQUAL("black", documentEditorFacade.getColor(0,0).c_str());
    STRCMP_EQUAL("D", std::string(1, documentEditorFacade.getChar(0,0)).c_str());
    STRCMP_EQUAL("black", documentEditorFacade.getColor(0,1).c_str());
    STRCMP_EQUAL("red", documentEditorFacade.getColor(0, 8).c_str());
    STRCMP_EQUAL("red", documentEditorFacade.getColor(0,9).c_str());
    STRCMP_EQUAL("d", std::string(1, documentEditorFacade.getChar(0,7)).c_str());
    STRCMP_EQUAL("orange", documentEditorFacade.getColor(0, 20).c_str());
    STRCMP_EQUAL("p", std::string(1, documentEditorFacade.getChar(0,20)).c_str());
    STRCMP_EQUAL("yellow", documentEditorFacade.getColor(0, 33).c_str());
    STRCMP_EQUAL("d", std::string(1, documentEditorFacade.getChar(0,33)).c_str());
    STRCMP_EQUAL("green", documentEditorFacade.getColor(1, 7).c_str());
    STRCMP_EQUAL("blue", documentEditorFacade.getColor(1, 15).c_str());
    STRCMP_EQUAL("indigo", documentEditorFacade.getColor(1, 31).c_str());
    STRCMP_EQUAL("violet", documentEditorFacade.getColor(2, 12).c_str());
    STRCMP_EQUAL("t", std::string(1, documentEditorFacade.getChar(2,17)).c_str());
}
