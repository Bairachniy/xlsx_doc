//
//  main.cpp
//  xlsx_doc2
//
//  Created by User on 02.03.2025.
//

#include "Workbook.h"

#include <iostream>


int main(int argc, const char * argv[]) {
    SimpleXlsx::CWorkbook Book("Incognito");
    SimpleXlsx::CWorksheet & Sheet = Book.AddSheet("Sheet 1");
    SimpleXlsx::CWorksheet & SecondSheet = Book.AddSheet("Sheet 2");

    Book.AddDefinedName("HalfRad", 0.5, "Half radian").AddDefinedName("TestSin", "sin(HalfRad)");
    Book.AddDefinedName("SingleCell", Sheet, SimpleXlsx::CellCoord(1, 0));
    Book.AddDefinedName("RangeCells", Sheet, SimpleXlsx::CellCoord(1, 0), SimpleXlsx::CellCoord(2, 0));
    Book.AddDefinedName("TestScope", Sheet, SimpleXlsx::CellCoord(1, 0), "", &SecondSheet);

    Sheet.AddSimpleRow("=HalfRad").AddSimpleRow("=TestSin");
    Sheet.AddSimpleRow("=SingleCell").AddSimpleRow("=sum(RangeCells)");

    SecondSheet.AddSimpleRow("=TestScope");

    if (Book.Save("OneMoreTime.xlsx")) std::cout << "The book has been saved successfully" << std::endl;
            else std::cout << "The book saving has been failed" << std::endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
