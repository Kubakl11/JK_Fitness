
#include "pdfhandler.h"


// end pdfwriter library includes

using namespace PDFHummus;


//Tutorial: https://www.pdfhummus.com/post/45501651637/42715772
//Proper documentation
PDFHandler::PDFHandler(QWidget *parent, FitnessPerson fp) : fp(fp)
{
    //Dialog where to save file - TODO: move to exportpdf.cpp and pass it in PDFhandler as argument
    std::string location = QFileDialog::getSaveFileName(parent, "Save PDF", "./train_plan.pdf", "PDF document (*.pdf)").toStdString();
    //If file is opened show error and exit
    QFile file(location.c_str());
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug("Error opening file");
        //Show error dialog
        QMessageBox::warning(parent, "Error","File is opened can't save to it!" );
        return;
    }
    else
    {
        file.close();
    }
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

    //This will be the font for the text in bold
    QFile ebrima_bold_ttf_file(":/src/fonts/ebrimabd.ttf"); //We must use qfile to extract the file from the resources
    auto temporary_ebrima_bold_ttf_file = QTemporaryFile::createNativeFile(ebrima_bold_ttf_file); //Temp file is created in the root where the app is
    auto full_path_ebrima_bold_ttf_file = temporary_ebrima_bold_ttf_file->fileName(); // Get system path to the font
    auto full_path_ebrima_bold_ttf_file_string = full_path_ebrima_bold_ttf_file.toStdString(); // Convert the path to std::string

    PDFUsedFont* ebrima_bold = pdfWriter.GetFontForFile(
        full_path_ebrima_bold_ttf_file_string); //Now the font can be loaded by the PDFHummus library, the library isn't part of QT so it can't use qt resources

    //Logo temp file
    QFile logo(":/src/img/JK_fitness_logo.png");
    if(!logo.open(QIODevice::ReadOnly))
    {
        qDebug("Error opening logo file");
        //Show error dialog
        QMessageBox::warning(parent, "Error","Can't open logo file!" );
        return;
    }
    auto temporary_logo = QTemporaryFile::createNativeFile(logo);
    auto full_logo_path = temporary_logo->fileName();
    auto full_logo_path_string = full_logo_path.toStdString();

    //Bulking menu
    QFile json_bulk_menu(":/src/foodmenus/bulking_menu.json"); //We must use qfile to extract the file from the resources
    if(!json_bulk_menu.open(QIODevice::ReadOnly))
    {
        qDebug("Error opening bulk menu json file");
        //Show error dialog
        QMessageBox::warning(parent, "Error","Can't open bulk menu json file!" );
        return;
    }
    auto temporary_json_bulk_menu = QTemporaryFile::createNativeFile(json_bulk_menu); //Temp file is created in the root where the app is
    auto full_path_json_bulk_menu = temporary_json_bulk_menu->fileName(); // Get system path to the font
    std::string full_path_json_bulk_menu_string = full_path_json_bulk_menu.toStdString(); // Convert the path to std::string

    //Loosing menu
    QFile json_loosing_menu(":/src/foodmenus/loosing_menu.json"); //We must use qfile to extract the file from the resources
    if(!json_loosing_menu.open(QIODevice::ReadOnly))
    {
        qDebug("Error opening loosing menu json file");
        //Show error dialog
        QMessageBox::warning(parent, "Error","Can't open loosing menu json file!" );
        return;
    }
    auto temporary_json_loosing_menu = QTemporaryFile::createNativeFile(json_loosing_menu); //Temp file is created in the root where the app is
    auto full_path_json_loosing_menu = temporary_json_loosing_menu->fileName(); // Get system path to the font
    std::string full_path_json_loosing_menu_string = full_path_json_loosing_menu.toStdString(); // Convert the path to std::string


    /* -------------------------------------------------------------------- Title page creation -------------------------------------------------------------------------- */
    //Create new pdfPage - this will be the first title page
    TitlePage* pdfTitlePage = new TitlePage();
    //Load data to fitness person from exportpdf.cpp - expected set before call of constructor
    //FitnessPerson fp = FitnessPerson(18, 183, 92, 5, Somatotype::EKTOMEZOMORF, Activity::ACTIVITY_LIGHT, Goal::WEIGHT_LOOSE, "Jan Kowals", Gender::Male);
    pdfTitlePage->fp = fp; //Set fitness person to the title page

    //Create a content context for the title page
    pdfTitlePage->pageContentContext =
        pdfWriter.StartPageContentContext(pdfTitlePage);
    //Set fonts to title page
    pdfTitlePage->titleFont = msjh_ttf;
    pdfTitlePage->textFont = ebrima_ttf;
    pdfTitlePage->textBoldFont = ebrima_bold;
    //Add logo
    pdfTitlePage->logo_path = full_logo_path_string;

    //Call title page content filling
    pdfTitlePage->FillPageContent();


    //End the content context
    pdfWriter.EndPageContentContext(pdfTitlePage->pageContentContext);

    /* -------------------------------------------------------------------- Content page creation ------------------------------------------------------------------------ */
    /* add content to the content context */
    ContentPage* pdfContentPage = new ContentPage();

    pdfContentPage->pageContentContext =
        pdfWriter.StartPageContentContext(pdfContentPage);

    //TODO: Load from
    FoodMenu menu;
    if (fp.target_goal == Goal::WEIGHT_GAIN)
    {
        std::cout << "Loading bulk menu";
        menu.loadData(full_path_json_bulk_menu_string);
    }
    else if (fp.target_goal == Goal::WEIGHT_LOOSE)
    {
        std::cout << "Loading loosing menu";
        menu.loadData(full_path_json_loosing_menu_string);
    }
    else
    {
        std::cout << "Loading bulk menu, goal = " << fp.goalToString.at(fp.target_goal) << "\n";
        menu.loadData(full_path_json_bulk_menu_string);
    }
    pdfContentPage->menu = menu;
    pdfContentPage->textFont = ebrima_ttf;
    pdfContentPage->headerFont = ebrima_bold;
    fp.calculateGlobalScalar();
    pdfContentPage->fp = fp;
    pdfContentPage->logo_path = full_logo_path_string;
    DoubleAndDoublePair jpgDimensions = pdfWriter.GetImageDimensions(full_logo_path_string);
    std::cout << "Logo dimensions: " << jpgDimensions.first << " x " << jpgDimensions.second << std::endl;
    pdfContentPage->FillPageContent();
    pdfWriter.EndPageContentContext(pdfContentPage->pageContentContext);




    /*
    //Logo is added to the app using QFile by creating a temp file and using that to import
    QFile logo(":/img/JK_fitness_logo.png");
    auto temporary_logo = QTemporaryFile::createNativeFile(logo);
    auto full_logo_path = temporary_logo->fileName();
    auto full_logo_path_string = full_logo_path.toStdString();
    */






    pdfWriter.WritePage(pdfTitlePage);
    pdfWriter.WritePage(pdfContentPage);
    for (int index = 1; index < 7; ++index)
    {
        //Page 2 - content
        ContentPage* pdfContentPageNotFirst = new ContentPage();

        pdfContentPageNotFirst->pageContentContext =
            pdfWriter.StartPageContentContext(pdfContentPageNotFirst);
        pdfContentPageNotFirst->menu = menu;
        pdfContentPageNotFirst->textFont = ebrima_ttf;
        pdfContentPageNotFirst->headerFont = ebrima_bold;
        pdfContentPageNotFirst->fp = fp;
        pdfContentPageNotFirst->logo_path = full_logo_path_string;
        pdfContentPageNotFirst->FillPageContent(index);
        pdfWriter.EndPageContentContext(pdfContentPageNotFirst->pageContentContext);
        pdfWriter.WritePageAndRelease(pdfContentPageNotFirst);
    }
    //Add train plan according to if strength training or own weight

    pdfWriter.EndPDF();
    //Freeing allocated pages
    delete pdfTitlePage;
    delete pdfContentPage;
    cout << status;
};


