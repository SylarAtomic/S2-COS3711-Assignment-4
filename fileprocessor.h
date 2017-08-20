#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

class FileProcessor : public QWidget
{
    Q_OBJECT
public:
    FileProcessor();
    ~FileProcessor();
    //virtual ~FileProcessor() {};
public slots:
    void loadFile();
    void processText();
private:
    void setupUI();
    QPushButton *loadBtn;
    QPushButton *processBtn;
    QTextEdit *textEdit;
};

#endif // FILEPROCESSOR_H
