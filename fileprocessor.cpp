#include "fileprocessor.h"
#include <QMessageBox>
#include <QGridLayout>
#include <QFileDialog>
#include <QSplitter>
#include <QTextStream>
#include <QRegExp>
/*
QRegExp test ("(\\(?(\\d{3})\\)?[\\s-]?(\\d{3})[\\s-]?(\\d{4}");
QRegExp phoneNumber32 ("((\\\(\d{3}\\) ?)|(\\d{3}-))+\\d{3}-\\d{4}"); // 088-000-0000 | 111-999-9876.
//QRegExp phoneNumber2 ("111-999-9876");
QRegExp phoneNumber33 ("\\b[0-9.-]{3}[0-9.-]{3}[0-9]{4}\\b"); //Checks for 10 digits
QRegExp phoneNumber4 ("\\b[0-9.-]{3}+[0-9.-]{3}+[0-9.-]{4}\\b");
QRegExp phoneNumber5 ("(\\+?1[- ]?)?\\(?(\\d{3})\\)?[\\s-]?(\\d{3})[\\s-]?(\\d{4})");
QRegExp phoneNumber6 ("(\\d\\d)(\\d\\d)(\\d{3})");
QRegExp phoneNumber662 ("\(\\d{3}\\)");
QRegExp phoneNumber222 ("\\([0-9]{3}\\)+[0-9]{4,10}"); // (999)1233456
QRegExp email1("\\b[a-z0-9,!#\$%&'\*\+/=\?\^_`\{\|}~-]+(\.[a-z0-9,!#\$%&'\*\+/=\?\^_`\{\|}~-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*\.([a-z]{2,})$\\b");
*/
//QRegExp phoneNumber23 ("\\([0-9]{3}\\)[0-9.-]{3}[0-9.-]{4,10}");
//Phone Numbers
QRegExp phoneNumber1 ("\\([0-9]{3}\\)[0-9.-]{3}[0-9.-]{4,10}"); //(111)111-11111111 | (999)1233456
QRegExp phoneNumber2 ("[0-9]{3}\\-[0-9]{3,7}(\\-[0-9]{4})*"); // 088-000-0000  011-471-2130 222-2222222  111-999-9876
QRegExp phoneNumber3 ("[0-9]{10}");

//Emails
QRegExp email("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,7}\\.[A-Z]{2,7}\\b"); // Emails with two parts
QRegExp email2("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,7}\\b"); // Emails with one part


FileProcessor::FileProcessor()
{
    setWindowTitle("Search");
    setupUI();

}
FileProcessor::~FileProcessor()
{
//
}

void FileProcessor::setupUI()
{
    //Create Widgets
    loadBtn = new QPushButton("Load");
    processBtn = new QPushButton("Process");
    textEdit = new QTextEdit;
    QGridLayout* layout = new QGridLayout();
    QSplitter *split1 = new QSplitter;
    QSplitter *split2 = new QSplitter;

    textEdit->setMinimumHeight(220);
    textEdit->setMinimumWidth(400);

    split1->addWidget(loadBtn);
    split1->addWidget(processBtn);

    split2->setOrientation(Qt::Vertical);
    split2->addWidget(split1);
    split2->addWidget(textEdit);

    layout->addWidget(split2);

    this->setLayout(layout);

    connect(loadBtn, SIGNAL(clicked()), this, SLOT(loadFile()));
    connect(processBtn, SIGNAL(clicked()), this, SLOT(processText()));
}

void FileProcessor::loadFile()
{

    QString fname = QFileDialog::getOpenFileName(this);
    QFile file(fname);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream readFile(&file);
    textEdit->setText(readFile.readAll());
    file.close();

}

void FileProcessor::processText()
{
    //Check for phone numbers
    phoneNumber1.setCaseSensitivity(Qt::CaseInsensitive);
    phoneNumber1.setPatternSyntax(QRegExp::RegExp);
    textEdit->moveCursor(QTextCursor::Start);
    textEdit->find(phoneNumber1);
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    textEdit->textCursor().mergeCharFormat(format);


    while(textEdit->find(phoneNumber1))//->textCursor().atEnd() != true)
    {
        textEdit->find(phoneNumber1);
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        textEdit->textCursor().mergeCharFormat(format);

    }
    // Check second phone number
    phoneNumber2.setCaseSensitivity(Qt::CaseInsensitive);
    phoneNumber2.setPatternSyntax(QRegExp::RegExp);

    textEdit->moveCursor(QTextCursor::Start);
    textEdit->find(phoneNumber2);
    format.setFontWeight(QFont::Bold);
    textEdit->textCursor().mergeCharFormat(format);

     while(textEdit->find(phoneNumber2))
    {
        textEdit->find(phoneNumber2);
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        textEdit->textCursor().mergeCharFormat(format);
    }

     //Check third phone number
     phoneNumber3.setCaseSensitivity(Qt::CaseInsensitive);
     phoneNumber3.setPatternSyntax(QRegExp::RegExp);

     textEdit->moveCursor(QTextCursor::Start);
     textEdit->find(phoneNumber3);
     format.setFontWeight(QFont::Bold);
     textEdit->textCursor().mergeCharFormat(format);

      while(textEdit->find(phoneNumber3))
     {
         textEdit->find(phoneNumber3);
         QTextCharFormat format;
         format.setFontWeight(QFont::Bold);
         textEdit->textCursor().mergeCharFormat(format);
     }


    //Check for emails
    email.setCaseSensitivity(Qt::CaseInsensitive);
    email.setPatternSyntax(QRegExp::RegExp);

    textEdit->moveCursor(QTextCursor::Start);
    textEdit->find(email);
    format.setFontWeight(QFont::Bold);
    textEdit->textCursor().mergeCharFormat(format);

     while(textEdit->find(email))
    {
        textEdit->find(email);
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        textEdit->textCursor().mergeCharFormat(format);
    }

     email2.setCaseSensitivity(Qt::CaseInsensitive);
     email2.setPatternSyntax(QRegExp::RegExp);

     textEdit->moveCursor(QTextCursor::Start);
     textEdit->find(email2);
     format.setFontWeight(QFont::Bold);
     textEdit->textCursor().mergeCharFormat(format);

      while(textEdit->find(email2))
     {
         textEdit->find(email2);
         QTextCharFormat format;
         format.setFontWeight(QFont::Bold);
         textEdit->textCursor().mergeCharFormat(format);
     }


    QMessageBox::information(this, "Done", "Checking Completed");
}
