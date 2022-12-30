#include "mainwindow.h"
#include "ui_mainwindow.h"
QString fileName;
bool dark = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOpen_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("Text Files (*.txt)"));

    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString txt = stream.readAll();
        ui->textEdit->setText(txt);
        QStringList filePath = fileName.split("/");
        setWindowTitle("MyNotepad | "+ filePath[filePath.size()-1]);
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    QFile file(fileName);
    if(file.open(QIODevice::Truncate | QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
    }
    else MainWindow::on_pushButtonSaveAs_clicked();

    //qDebug()<<file.open(QIODevice::Truncate | QIODevice::ReadWrite);
}

void MainWindow::on_pushButtonSaveAs_clicked()
{
    QString fileName2 = QFileDialog::getSaveFileName(0, "Save File", QDir::currentPath(),
                                 tr("Text Files (*.txt)"));
    if(fileName2 != "")
    {
        fileName = fileName2;
        QFile file(fileName);
        if(file.open(QIODevice::Truncate | QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            QStringList filePath = fileName.split("/");
            setWindowTitle("MyNotepad | "+ filePath[filePath.size()-1]);
        }
    }
}

void MainWindow::on_pushButtonNew_clicked()
{

    QString fileName2 = QFileDialog::getSaveFileName(0, "New File", QDir::currentPath(),
                                 tr("Text Files (*.txt)"));
    if(fileName2 != "")
    {
        ui->textEdit->clear();
        fileName = fileName2;
        QFile file(fileName);
        if(file.open(QIODevice::Truncate | QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            QStringList filePath = fileName.split("/");
            setWindowTitle("MyNotepad | "+ filePath[filePath.size()-1]);
        }
    }
}

void MainWindow::on_pushButtonPrint_clicked()
{
    QFile txtFileOut(fileName);
    txtFileOut.open(QFile::ReadOnly | QFile::Text);
    QTextStream txtFileIn(&txtFileOut);
    QString txtFileToQString(txtFileIn.readAll());
    QTextDocument *document = new QTextDocument(txtFileToQString);

    QPrinter printer;

    QPrintDialog *dlg = new QPrintDialog(&printer, this);
       if (dlg->exec() != QDialog::Accepted)
            return;
     document->print(&printer);

}


void MainWindow::on_actionNew_triggered()
{
    MainWindow::on_pushButtonNew_clicked();
}


void MainWindow::on_actionOpen_triggered()
{
    MainWindow::on_pushButtonNew_clicked();
}


void MainWindow::on_actionSave_triggered()
{
    MainWindow::on_pushButtonSave_clicked();
}


void MainWindow::on_actionSave_As_triggered()
{
    MainWindow::on_pushButtonSaveAs_clicked();
}


void MainWindow::on_actionPrint_triggered()
{
    MainWindow::on_pushButtonPrint_clicked();
}


void MainWindow::on_Mode_clicked()
{
    if(dark==0)
    {
        QFile file(":/styles/styles/style.qss");
        if(file.open(QFile::ReadOnly))
        {
            dark =1;
            QString styleSheet = QLatin1String(file.readAll());
            setStyleSheet(styleSheet);
        }
    }
    else if(dark==1)
    {
        dark=0;
        setStyleSheet("");
    }
}


void MainWindow::on_pushButtonPast_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("this application ...");
    msgBox.exec();
}



void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCute_triggered()
{
    ui->textEdit->cut();
}



