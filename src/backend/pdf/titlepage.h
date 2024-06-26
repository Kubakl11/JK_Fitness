#ifndef TITLEPAGE_H
#define TITLEPAGE_H
#include <PDFWriter.h>
#include <PDFpage.h>

//This class will hold the default template for the title page, it extends the PDFPage class
class TitlePage : public PDFPage
{
private:
    //Title of the document
    const std::string title = "Výživový plán";

    //Date of creation
    std::string date;



    //Text sizes
    const double titleSize = 34;
    const double textSize = 10;
    const double dateSize = 14;
    const double headerSize = 14;

    //Private methods

    //Loading fonts
    void loadTitleFont();
    void loadTextFont();

    //Load logo
    void loadLogo();


public:
    //Public methods
    TitlePage();
    void FillPageContent();
    //Logo of the company
    std::string logo_path;

    //Fonts used:
    PDFUsedFont * titleFont; //Microsoft JhengHei
    PDFUsedFont * textFont;  //Ebrima

    //Page content context
    PageContentContext* pageContentContext;
};

#endif // TITLEPAGE_H
