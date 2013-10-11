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
    CHECK( 1 == documentEditorFacade.sayOne() );
    LONGS_EQUAL( 1 , documentEditorFacade.sayOne() );
    CHECK( "Hello!" == documentEditorFacade.sayHello() );
}

TEST( DocumentEditorFacade, drawScreen) {
    // Given
    DocumentEditorFacade documentEditorFacade("Do not dwell in the past, do not dream of the future, concentrate the mind on the present moment.");
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
    CHECK("red" == documentEditorFacade.getColor(0, 7));
    CHECK("orange" == documentEditorFacade.getColor(0, 20));
    CHECK("yellow" == documentEditorFacade.getColor(0, 33));
    CHECK("green" == documentEditorFacade.getColor(1, 7));
    CHECK("blue" == documentEditorFacade.getColor(1, 15));
    CHECK("indigo" == documentEditorFacade.getColor(1, 31));
    CHECK("violet" == documentEditorFacade.getColor(2, 12));

}
