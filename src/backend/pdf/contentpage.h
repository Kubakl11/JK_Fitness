#ifndef CONTENTPAGE_H
#define CONTENTPAGE_H

#include "PageContentContext.h"
#include <string>
#include <vector>
#include <PDFPage.h>
#include "../Foodmenu.cpp"
#include "titlepage.h"
class ContentPage : public PDFPage
{
public:
    //Variables
    PageContentContext* pageContentContext;
    PDFUsedFont* textFont;
    PDFUsedFont* headerFont;

    //Methods
    ContentPage();
    void FillPageContent(int contentPageIndex = 0);
    void setMealData(const std::vector<std::string>& meals) { this->meals = meals; }
    //Paths
    std::string logo_path;
    FoodMenu menu;
    void printFoodItem(const std::string& name, int amount, const std::string& unit, int calories, double text_size, PDFUsedFont* font, double leading, const int cmyk[4], double& currentY);
    void printHeading(const std::string& heading, double text_size, PDFUsedFont* font, double leading, const int cmyk[4], double& currentY);
    std::string idToHeading(int id);
    FitnessPerson fp;
private:
    void printLine(const std::string& text, double text_size, PDFUsedFont* font, double leading, const int cmyk[4]);
    void print(const std::string& text, double text_size, PDFUsedFont* font, double leading, const int cmyk[4]);

    //Page size
    const double pageWidth = 595;
    const double pageHeight = 842;


    std::vector<std::string> meals;

    //Constants for layout
    const double textSize = 12;
    const double headerSize = 14;
    const double mealX = 50;
    const double mealYStart = 700;
    const double lineSpacing = 20;

    const bool showTitle = false;
    const std::string title = "Jídelníček";
    const double titleSize = 24;
    //TODO: calculate from word place and page width
    const double titleX = 50;
    const double titleY = 800;


    //Colors in cyan, magenta, yellow, black (0 - 100 %)

    const int black[4] = {0, 0, 0, 100};
    const int magenta[4] = {0, 100, 0, 0};
    const int red[4] = {0, 75, 100, 20};

};

#endif // CONTENTPAGE_H
