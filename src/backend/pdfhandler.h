#ifndef PDFHANDLER_H
#define PDFHANDLER_H
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
#include <QString>
#include "pdf/titlepage.h"
#include "pdf/contentpage.h"
#include <QLabel>
#include <QMessageBox>

class PDFHandler
{
public:
    PDFHandler(QWidget *parent, FitnessPerson fp, bool onlyTitlePage = false);
    FitnessPerson fp;
};

#endif // PDFHANDLER_H
