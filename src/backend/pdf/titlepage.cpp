#include "titlepage.h"
#include "PageContentContext.h"
#include <QDate>
#include <QFile>
#include <QString>


// Title page constructor
TitlePage::TitlePage()
{
    //Set date
    date = "Datum: " + QDate::currentDate().toString().toStdString();

    //Loading fonts - loading is done externally, because we don't want to have pdfWriter here
    //loadTitleFont();
    //loadTextFont();

    //Load logo
    //loadLogo();

    //Call parent
    PDFPage();

    //Set the page size to standard A4
    SetMediaBox(PDFRectangle(0,0,pageWidth,pageHeight));
}

// Caution: the page context shall be set before the call of this method
void TitlePage::FillPageContent()
{
    //Check if the content context is set
    if (pageContentContext == nullptr)
        return;

    //1. Add title
    //Set title size, font and add it to the context
    pageContentContext->BT();
    pageContentContext->k(0,0,0,1);
    pageContentContext->Tm(1,0,0,1,titleX,titleY);
    printLine("Výživový", titleSize, titleFont, 1.5, black);
    printLine("Plán", titleSize, titleFont, 1.5, black);
    pageContentContext->ET();
    //2. Add date
    //Set date size, font and add it to the context
    pageContentContext->BT();
    pageContentContext->k(0,0,0,1);
    pageContentContext->Tf(textFont, dateSize);
    pageContentContext->Tm(1,0,0,1,dateX,dateY);
    pageContentContext->Tj(date);
    pageContentContext->ET();
    //3. Add description header and text
    pageContentContext->BT();
    pageContentContext->Tm(1, 0, 0, 1, dataX, dataY); // Set text matrix
    print("ÚDAJE:", headerSize, textFont, 1.5, magenta);

    /*pageContentContext->k(0, 0, 0, 1); // Set color to black
    pageContentContext->Tf(textFont, headerSize); // Set font and size
    pageContentContext->Td(0, 0); // Move text position
    pageContentContext->Tj("ÚDAJE:"); // Display header
    */
    /*pageContentContext->Tf(textFont, textSize); // Set text size
    pageContentContext->TL(textSize * 1.25); // Set line spacing
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Jméno: " + fp.name);
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Pohlaví: " + fp.genderToString.at(fp.gender));
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Věk: " + std::to_string(fp.age));
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Výška: " + std::to_string(fp.height) + " cm");
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Váha: " + std::to_string(fp.weight) + " kg");
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Tělesný tuk: " + std::to_string(fp.body_fat) + "%");
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Typ somatotypu: " + fp.somaToString.at(fp.soma_type));
    pageContentContext->TStar(); // Move to a new line
    pageContentContext->Tj("Cíl: " + fp.goalToString.at(fp.target_goal));
    */

    printLine("Jméno: ", textSize, textBoldFont, 1.5, black);
    print(fp.name, textSize, textFont, 1.5, black);
    printLine("Pohlaví: ", textSize, textBoldFont, 1.5, black);
    print(fp.genderToString.at(fp.gender), textSize, textFont, 1.5, black);
    printLine("Věk: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.age), textSize, textFont, 1.5, black);
    printLine("Výška: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.height) + " cm", textSize, textFont, 1.5, black);
    printLine("Váha: ", textSize, textBoldFont, 1.5, black);
    QString weight; //For formating to 1 dec place - TODO: don't cast (int) elesewhere but also use this "trick" - depends on what shall be decimal and what not
    print(weight.asprintf("%.1f",fp.weight).toStdString() + " kg", textSize, textFont, 1.5, black);
    printLine("Tělesný tuk: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.body_fat) + "%", textSize, textFont, 1.5, black);
    printLine("Somatotyp: ", textSize, textBoldFont, 1.5, black);
    print(fp.somaToString.at(fp.soma_type), textSize, textFont, 1.5, black);
    //4. Add calculated results
    printLine("", textSize, textFont, 1.5, black);
    printLine("VYPOČTENÉ HODNOTY: ", headerSize, textFont, 1.5, magenta);
    printLine("Lean body mass: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.LBM) + " kg", textSize, textFont, 1.5, black);
    printLine("Basal metabolism: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.BM) + " kcal", textSize, textFont, 1.5, black);
    printLine("Total calories intake: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.Calories) + " kcal", textSize, textFont, 1.5, black);
    printLine("Protein: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.P) + " g", textSize, textFont, 1.5, black);
    printLine("Carbohydrates: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.Carbohydrates) + " g", textSize, textFont, 1.5, black);
    printLine("Fats: ", textSize, textBoldFont, 1.5, black);
    print(std::to_string((int)fp.F) + " g", textSize, textFont, 1.5, black);
    pageContentContext->ET();
    //5. Add orientational summary
    pageContentContext->BT();
    pageContentContext->Tm(1, 0, 0, 1, summaryX, summaryY);
    printLine("ORIENTAČNÍ PŘEHLED:", headerSize, textFont, 1.5, magenta);
    printLine("Snídaně (", textSize, textBoldFont, 1.5, black);
    QString breakfastCalories = QString::number((int)fp.breakfastNutrients[0]) + " kcal)";
    print(breakfastCalories.toStdString(), textSize, textFont, 1.5, black);
    printLine("Protein: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.breakfastNutrients[1]) + " g", textSize, textFont, 1.5, black);
    printLine("Carbohydrates: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.breakfastNutrients[2]) + " g", textSize, textFont, 1.5, black);
    printLine("Fats: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.breakfastNutrients[3]) + " g", textSize, textFont, 1.5, black);
    printLine("Oběd (", textSize, textBoldFont, 1.5, black);
    QString lunchCalories = QString::number((int)fp.lunchNutrients[0]) + " kcal)";
    print(lunchCalories.toStdString(), textSize, textFont, 1.5, black);
    printLine("Protein: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.lunchNutrients[1]) + " g", textSize, textFont, 1.5, black);
    printLine("Carbohydrates: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.lunchNutrients[2]) + " g", textSize, textFont, 1.5, black);
    printLine("Fats: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.lunchNutrients[3]) + " g", textSize, textFont, 1.5, black);
    printLine("Svačina (", textSize, textBoldFont, 1.5, black);
    QString snackCalories = QString::number((int)fp.snackNutrients[0]) + " kcal)";
    print(snackCalories.toStdString(), textSize, textFont, 1.5, black);
    printLine("Protein: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.snackNutrients[1]) + " g", textSize, textFont, 1.5, black);
    printLine("Carbohydrates: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.snackNutrients[2]) + " g", textSize, textFont, 1.5, black);
    printLine("Fats: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.snackNutrients[3]) + " g", textSize, textFont, 1.5, black);
    printLine("Večeře (", textSize, textBoldFont, 1.5, black);
    QString dinnerCalories = QString::number((int)fp.dinnerNutrients[0]) + " kcal)";
    print(dinnerCalories.toStdString(), textSize, textFont, 1.5, black);
    printLine("Protein: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.dinnerNutrients[1]) + " g", textSize, textFont, 1.5, black);
    printLine("Carbohydrates: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.dinnerNutrients[2]) + " g", textSize, textFont, 1.5, black);
    printLine("Fats: ", textSize, textFont, 1.5, black);
    print(std::to_string((int)fp.dinnerNutrients[3]) + " g", textSize, textFont, 1.5, black);
    pageContentContext->ET();
    //Add line
    pageContentContext->k(0.25,0.2,0.25,0); //I don't understand why line is black, problem for future
    pageContentContext->w(1);
    pageContentContext->m(lineStartX, lineStartY);
    pageContentContext->l(lineEndX, lineEndY);
    pageContentContext->S();
    //Add logo
    qDebug() << "Logo path: " << logo_path.c_str();
    AbstractContentContext::ImageOptions opt;
    opt.transformationMethod = AbstractContentContext::eMatrix;
    opt.matrix[0] = opt.matrix[3] = 0.90;
    pageContentContext->DrawImage(pageHeight*0.45/21.0, pageHeight -(pageHeight*8.93/29.7) - 150, logo_path, opt);
    //pageContentContext->q();
    //pageContentContext->cm(1,0,0,1,100,100);
    //pageContentContext->Do(pageContentContext->GetResourcesDictionary().AddFormXObjectMapping("logo"));
    //pageContentContext->Q();
}

void TitlePage::printLine(std::string text, double text_size, PDFUsedFont * font, double leading, const int cmyk[4])
{
    leading = text_size * leading;
    pageContentContext->k((double)cmyk[0]/100, (double)cmyk[1]/100, (double)cmyk[2]/100, (double)cmyk[3]/100);
    pageContentContext->Tf(font, text_size);
    pageContentContext->TL(leading);
    pageContentContext->TStar();
    pageContentContext->Tj(text);
}
void TitlePage::print(std::string text, double text_size, PDFUsedFont * font, double leading, const int cmyk[4])
{
    leading = text_size * leading;
    pageContentContext->k((double)cmyk[0]/100, (double)cmyk[1]/100, (double)cmyk[2]/100, (double)cmyk[3]/100);
    pageContentContext->Tf(font, text_size);
    pageContentContext->Tj(text);
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
