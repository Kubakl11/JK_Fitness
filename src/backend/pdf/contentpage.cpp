#include "ContentPage.h"
#include "PDFWriter.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include <iomanip>
#include "PDFUsedFont.h"

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

void ContentPage::FillPageContent(int contentPageIndex)
{
    if (pageContentContext == nullptr)
        return;

    double currentY = mealYStart;

    pageContentContext->BT();
    // Title handling, only if defined
    if (contentPageIndex == 0)
    {
        //Essentially centering the title
        auto titleDimensions = headerFont->CalculateTextDimensions(title, titleSize);
        double titleX = (pageWidth - titleDimensions.width) / 2;
        pageContentContext->Tm(1, 0, 0, 1, titleX, titleY);
        printLine(title, titleSize, headerFont, 1.5, red);
        currentY -= lineSpacing;
    }

    //menu.dayMenuList[0]
    //Loop through all dishes and print them,
    std::cout << std::endl;
    auto dayMenuIt = menu.dayMenuList[contentPageIndex];

    int dayId = contentPageIndex;
    //printHeading("Day " + std::to_string(dayId), headerSize, headerFont, 1.5, black, currentY);
    std::cout << "Day " << dayId << std::endl;
    auto mealListIt = dayMenuIt.begin(); // Iterator for meals within the day
    for (auto mealIter = mealListIt; mealIter != dayMenuIt.end(); ++mealIter)
    {
        int mealId = (int) std::distance(mealListIt, mealIter);
        printHeading(idToHeading(mealId), headerSize, headerFont, 1.5, black, currentY);
        std::cout << "Meal " << mealId << std::endl;
        for (const auto& food : *mealIter)
        {
            // Print food details
            std::cout << std::setw(4) << std::left << food.id
                      << std::setw(20) << std::left << food.title
                      << std::setw(12) << std::left << food.type
                      << food.kcal << " " << food.gram << std::endl;
            if((food.title.compare("Vejce")) == 0)
                printFoodItem(food.title, food.gram, "ks", food.kcal, textSize, textFont, 1.2, black, currentY);
            else
                printFoodItem(food.title, food.gram, "g", food.kcal, textSize, textFont, 1.2, black, currentY);
        }
        currentY -= lineSpacing;
    }

    //Add logo bottom center
    AbstractContentContext::ImageOptions opt;
    opt.transformationMethod = AbstractContentContext::eMatrix;
    opt.matrix[0] = opt.matrix[3] = 0.90;

    pageContentContext->DrawImage((pageWidth-0.9*202)/2, 75, logo_path, opt);

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

void ContentPage::printHeading(const std::string& heading, double text_size, PDFUsedFont* font, double leading, const int cmyk[4], double& currentY)
{
    // Set text color
    pageContentContext->k((double)cmyk[0]/100, (double)cmyk[1]/100, (double)cmyk[2]/100, (double)cmyk[3]/100);
    // Set font and size
    pageContentContext->Tf(font, text_size);
    // Print heading text
    pageContentContext->Tm(1, 0, 0, 1, mealX, currentY);
    pageContentContext->Tj(heading);
    currentY -= lineSpacing; // Move down for next line
}

void ContentPage::printFoodItem(const std::string& name, int amount, const std::string& unit, int calories, double text_size, PDFUsedFont* font, double leading, const int cmyk[4], double& currentY)
{

    calories = (int) ((double) calories * (double) fp.scalar);
    amount = (int) ((double) amount * (double) fp.scalar);
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Calories: " << calories << std::endl;
    std::cout << "Scalar: " << fp.scalar << std::endl;
    // Set text color
    pageContentContext->k((double)cmyk[0]/100, (double)cmyk[1]/100, (double)cmyk[2]/100, (double)cmyk[3]/100);
    // Set font and size
    pageContentContext->Tf(font, text_size);

    // Calculate text dimensions
    auto nameDimensions = font->CalculateTextDimensions(name, text_size);
    auto amountStr = std::to_string(amount);
    auto amountDimensions = font->CalculateTextDimensions(amountStr, text_size);
    auto unitDimensions = font->CalculateTextDimensions(unit, text_size);
    auto caloriesStr = std::to_string(calories) + " kcal";
    auto caloriesDimensions = font->CalculateTextDimensions(caloriesStr, text_size);

    // Debugging: Output dimensions to console
    std::cout << "nameDimensions: " << nameDimensions.width << " " << nameDimensions.height << std::endl;
    std::cout << "amountDimensions: " << amountDimensions.width << " " << amountDimensions.height << std::endl;
    std::cout << "unitDimensions: " << unitDimensions.width << " " << unitDimensions.height << std::endl;
    std::cout << "caloriesDimensions: " << caloriesDimensions.width << " " << caloriesDimensions.height << std::endl;

    // Define column positions
    double nameX = mealX;
    double amountX = mealX + 350; // Fixed position for amount (adjust as needed)
    double unitX = amountX + 5; // Fixed position for unit (adjust as needed)
    double caloriesX = unitX + 80; // Fixed position for calories (adjust as needed)

    // Adjust positions to align to the right
    double adjustedAmountX = amountX - amountDimensions.width;
    double adjustedCaloriesX = caloriesX - caloriesDimensions.width;

    // Print food item
    if (calories != 0 && amount != 0)
    {
        pageContentContext->Tm(1, 0, 0, 1, nameX, currentY);
        pageContentContext->Tj(name);
        pageContentContext->Tm(1, 0, 0, 1, adjustedAmountX, currentY);
        pageContentContext->Tj(amountStr);
        pageContentContext->Tm(1, 0, 0, 1, unitX, currentY);
        pageContentContext->Tj(unit);
        pageContentContext->Tm(1, 0, 0, 1, adjustedCaloriesX, currentY);
        pageContentContext->Tj(caloriesStr);
    }
    else
    {
        // dont print amount and cals
        pageContentContext->Tm(1, 0, 0, 1, nameX, currentY);
        pageContentContext->Tj(name);
    }
    // Move down for the next line
    currentY -= lineSpacing;
}

std::string ContentPage::idToHeading(int id)
{
    switch (id)
    {
    case 0:
        return "Snídaně";
    case 1:
        return "Oběd";
    case 2:
        return "Svačina";
    case 3:
        return "Večeře";
    case 4:
        return "Ostatní";
    }
}
