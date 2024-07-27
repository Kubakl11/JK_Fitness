#ifndef TITLEPAGE_H
#define TITLEPAGE_H
#include <PDFWriter.h>
#include <PDFpage.h>
#include "../FitnessPerson.hpp"

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

    //Page size
    const double pageWidth = 595;
    const double pageHeight = 842;

    //Text positions - in mm from upper left corner
    const double titleX = (11.9/210.0) * pageWidth;
    const double titleY = pageHeight - (21.9/297.0) * pageHeight;

    const double dateX = (15.1 / 210) * pageWidth;
    const double dateY = pageHeight - (83.8/297.0) * pageHeight;

    const double dataX = (53.0/133.0) * pageWidth;
    const double dataY = pageHeight - (pageHeight * 17.0 / 165.0);

    const double summaryX = dataX;
    const double summaryY = dataY - 250;

    //Colors
    const int magenta[4] = {30, 70, 0, 37};
    const int black[4] = {0, 0, 0, 100};

    //Line
    const double lineStartX = (40.0 / 115.0) * pageWidth;
    const double lineStartY = pageHeight - (pageHeight * 8.0 / 165.0);
    const double lineEndX = lineStartX;
    const double lineEndY = (pageHeight * 10.0 / 165.0);

    //Private methods

    //Loading fonts
    void loadTitleFont();
    void loadTextFont();

    //Load logo
    void loadLogo();
    //Help printing function
    void printLine(std::string text, double text_size, PDFUsedFont * font, double leading, const int cmyk[4]);
    void print(std::string text, double text_size, PDFUsedFont * font, double leading, const int cmyk[4]);

public:
    //Public methods
    TitlePage();
    void FillPageContent();
    //Logo of the company
    std::string logo_path;

    //Fonts used:
    PDFUsedFont * titleFont; //Microsoft JhengHei
    PDFUsedFont * textFont;  //Ebrima
    PDFUsedFont * textBoldFont; //Ebrima bold

    //Page content context
    PageContentContext* pageContentContext;

    //Fitness person
    FitnessPerson fp;
};

#endif // TITLEPAGE_H
