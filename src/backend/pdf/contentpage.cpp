#include "ContentPage.h"
#include "PDFWriter.h"
#include <iostream>
#include <string.h>

ContentPage::ContentPage()
{
    // Initialize fonts (loading should be done externally as in TitlePage)
    // textFont = loadTextFont();
    // headerFont = loadHeaderFont();

    //Call parent
    PDFPage();
    //Set the page size to standard A4
    SetMediaBox(PDFRectangle(0,0,pageWidth,pageHeight));
}

void ContentPage::FillPageContent()
{
    if (pageContentContext == nullptr)
        return;

    double currentY = mealYStart;

    pageContentContext->BT();
    // Title handling, only if defined
    if (showTitle)
    {
        pageContentContext->Tm(1, 0, 0, 1, mealX, currentY);
        printLine(title, titleSize, headerFont, 1.5, black);
        currentY -= lineSpacing;
    }

    //menu.dayMenuList[0]
    //Loop through all dishes and print them,
    for (std::vector<std::vector<Food>> iter1 : menu.dayMenuList)
    {
        //std::cout << "Day " << distance(menu.dayMenuList.begin(), iter1) << std::endl;
        for (std::vector<Food> iter2 : iter1)
        {
            //std::cout << "Meal " << distance(iter1.begin(), iter2) << std::endl;
            for (Food food : iter2)
            {
                //std::cout << "Food " << distance(iter1.begin(), iter2) << std::endl;
                std::cout << std::setw(4) << std::left << food.id << std::setw(20) << std::left << food.title << std::setw(12) << std::left << food.type << food.kcal << " " << food.gram << std::endl;
            }
        }
    }

    pageContentContext->ET();
}

void ContentPage::printLine(const std::string& text, double text_size, PDFUsedFont* font, double leading, const int cmyk[4])
{
    leading = text_size * leading;
    pageContentContext->k((double)cmyk[0]/100, (double)cmyk[1]/100, (double)cmyk[2]/100, (double)cmyk[3]/100);
    pageContentContext->Tf(font, text_size);
    pageContentContext->TL(leading);
    pageContentContext->TStar();
    pageContentContext->Tj(text);
}

void ContentPage::print(const std::string& text, double text_size, PDFUsedFont* font, double leading, const int cmyk[4])
{
    //leading = text_size * leading;
    pageContentContext->k((double)cmyk[0]/100, (double)cmyk[1]/100, (double)cmyk[2]/100, (double)cmyk[3]/100);
    pageContentContext->Tf(font, text_size);
    pageContentContext->Tj(text);
}
