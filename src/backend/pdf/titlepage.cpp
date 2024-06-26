#include "titlepage.h"
#include "PageContentContext.h"
#include <QDate>
#include <QFile>

TitlePage::TitlePage()
{
    //Set date
    date = "Datum: " + QDate::currentDate().toString().toStdString();

    //Loading fonts
    //loadTitleFont();
    //loadTextFont();

    //Load logo
    //loadLogo();

    //Call parent
    PDFPage();

    //Set the page size to standard A4
    SetMediaBox(PDFRectangle(0,0,595,842));
}

void TitlePage::FillPageContent()
{
    //Check if the content context is set
    if (pageContentContext == nullptr)
        return;

    //1. Add title
    //Set title size, font and add it to the context
    pageContentContext->BT();
    pageContentContext->k(0,0,0,1);
    pageContentContext->Tf(titleFont, titleSize);
    pageContentContext->Tm(1,0,0,1,100,700);
    pageContentContext->Tj(title);
    pageContentContext->ET();
    //2. Add date
    //Set date size, font and add it to the context
    pageContentContext->BT();
    pageContentContext->k(0,0,0,1);
    pageContentContext->Tf(textFont, dateSize);
    pageContentContext->Tm(1,0,0,1,100,650);
    pageContentContext->Tj(date);
    pageContentContext->ET();
    //3. Add description header and text

    //4. Add calculated results

    //5. Add orientational summary
}


/*TitlePage::loadTitleFont()
{
    //Font is added to the app using QFile
    QFile file(":/src/fonts/msjh.ttc"); //We must use qfile to extract the file from the resources
    auto temporary_file = QTemporaryFile::createNativeFile(file); //Temp file is created in the root where the app is
    auto full_path = temporary_file->fileName(); // Get system path to the font
    auto full_path_string = full_path.toStdString(); // Convert the path to std::string

    PDFUsedFont* msjh_ttf = pdfWriter.GetFontForFile(
        full_path_string); //Now the font can be loaded by the PDFHummus library, the library isn't part of QT so it can't use qt resources
}*/
