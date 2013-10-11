#include "CppUnitLite/TestHarness.h"
#include "CppUnitLite/TestDefaultConfig.h"
#include "DocumentEditorFacade.h"

int main(int argc, char* argv[]) {
	CommandLineTestRunner::RunAllTests(argc, argv);
	return 0;
}

TEST( DocumentEditorFacade, creation) {
    // Given
    DocumentEditorFacade documentEditorFacade;

    // When & Then
    CHECK ( 1 == documentEditorFacade.sayOne() );
    LONGS_EQUAL ( 1 , documentEditorFacade.sayOne() );
    CHECK ( "Hello!" == documentEditorFacade.sayHello() );
}

TEST( DocumentEditorFacade, drawASentenceOnScreen) {
    // Given
    DocumentEditorFacade documentEditorFacade(3, 40
        , "Do not dwell in the past, do not dream of the future, concentrate the mind on the present moment.");
    documentEditorFacade.setColor(0, 7, 5, "red");
    documentEditorFacade.setColor(0, 20, 4, "orange");
    documentEditorFacade.setColor(0, 33, 5, "yellow");
    documentEditorFacade.setColor(1, 7, 6, "green");
    documentEditorFacade.setColor(1, 15, 11, "blue");
    documentEditorFacade.setColor(1, 31, 4, "indigo");
    documentEditorFacade.setColor(2, 12, 6, "violet");
    // When

    // Then

}