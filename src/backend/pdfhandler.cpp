
#include "pdfhandler.h"
// standard library includes
#include <iostream>
#include <string>
using namespace std;
// end standard library includes

// pdfwriter library includes
#include <PDFWriter.h>
#include <PDFPage.h>
#include <PageContentContext.h>
#include <PDFFormXObject.h>
#include <ResourcesDictionary.h>
#include <QFile>
#include <QDebug>
#include <QTemporaryFile>
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <QWidget>
#include "pdf/titlepage.h"
// end pdfwriter library includes

using namespace PDFHummus;


//Tutorial: https://www.pdfhummus.com/post/45501651637/42715772
//Proper documentation
PDFHandler::PDFHandler(QWidget *parent)
{
    //Dialog where to save file - TODO: move to exportpdf.cpp and pass it in PDFhandler as argument
    std::string location = QFileDialog::getSaveFileName(parent, "Save PDF", "./train_plan.pdf", "PDF document (*.pdf)").toStdString();

    PDFWriter pdfWriter;
    EStatusCode status;
    //Start creating pdf, status is for failure check
    status = pdfWriter.StartPDF(location,ePDFVersion13);
    //DEBUG ONLY: Print the status of the pdf creation
    //qDebug() << status;

    /* -------------------------------------------------------------------- Font loading --------------------------------------------------------------------------------- */

    //Load fonts that will be needed

    //This will be the font for the title
    QFile msjh_ttf_file(":/src/fonts/msjh.ttc"); //We must use qfile to extract the file from the resources
    auto temporary_msjh_ttf_file = QTemporaryFile::createNativeFile(msjh_ttf_file); //Temp file is created in the root where the app is
    auto full_path_msjh_ttf_file = temporary_msjh_ttf_file->fileName(); // Get system path to the font
    auto full_path_msjh_ttf_file_string = full_path_msjh_ttf_file.toStdString(); // Convert the path to std::string

    PDFUsedFont* msjh_ttf = pdfWriter.GetFontForFile(
        full_path_msjh_ttf_file_string); //Now the font can be loaded by the PDFHummus library, the library isn't part of QT so it can't use qt resources

    //This will be the font for the text
    QFile ebrima_ttf_file(":/src/fonts/ebrima.ttf"); //We must use qfile to extract the file from the resources
    auto temporary_ebrima_ttf_file = QTemporaryFile::createNativeFile(ebrima_ttf_file); //Temp file is created in the root where the app is
    auto full_path_ebrima_ttf_file = temporary_ebrima_ttf_file->fileName(); // Get system path to the font
    auto full_path_ebrima_ttf_file_string = full_path_ebrima_ttf_file.toStdString(); // Convert the path to std::string

    PDFUsedFont* ebrima_ttf = pdfWriter.GetFontForFile(
        full_path_ebrima_ttf_file_string); //Now the font can be loaded by the PDFHummus library, the library isn't part of QT so it can't use qt resources

    /* -------------------------------------------------------------------- Title page creation -------------------------------------------------------------------------- */
    //Create new pdfPage - this will be the first title page
    TitlePage* pdfTitlePage = new TitlePage();

    //Create a content context for the title page
    pdfTitlePage->pageContentContext =
        pdfWriter.StartPageContentContext(pdfTitlePage);
    //Set fonts to title page
    pdfTitlePage->titleFont = msjh_ttf;
    pdfTitlePage->textFont = ebrima_ttf;
    //Call title page content filling
    pdfTitlePage->FillPageContent();


    //End the content context
    pdfWriter.EndPageContentContext(pdfTitlePage->pageContentContext);

    /* -------------------------------------------------------------------- Content page creation ------------------------------------------------------------------------ */
    /* add content to the content context



    //Text options and write text to the page
    AbstractContentContext::TextOptions textOptions(msjh_ttf,14,AbstractContentContext::eGray,0);
    pageContentContext->WriteText(10,100,"Hello World",textOptions);
    */


    /*
    //Logo is added to the app using QFile by creating a temp file and using that to import
    QFile logo(":/img/JK_fitness_logo.png");
    auto temporary_logo = QTemporaryFile::createNativeFile(logo);
    auto full_logo_path = temporary_logo->fileName();
    auto full_logo_path_string = full_logo_path.toStdString();
    */






    pdfWriter.WritePageAndRelease(pdfTitlePage);
    pdfWriter.EndPDF();

    cout << status;
};


