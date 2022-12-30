#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include<QDebug>
#include<QFile>
#include<QString>
#include<QDir>
#include<QTextStream>
#include<QFileDialog>
#include<QPrinter>
#include<QPrintDialog>
#include<QTextDocument>
#include<QMessageBox>
#include <QCloseEvent>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButtonOpen_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonSaveAs_clicked();
    void on_pushButtonNew_clicked();
    void on_pushButtonPrint_clicked();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionPrint_triggered();
    void on_actionCopy_triggered();
    void on_actionCute_triggered();
    void on_Mode_clicked();
    void on_pushButtonPast_2_clicked();
    void on_actionFont_triggered();
    void on_pushButtonCopy_clicked();
    void on_pushButtonPast_clicked();

protected:
   void closeEvent(QCloseEvent *event)
   {
       QMessageBox::StandardButton resBtn = QMessageBox::question( this, tr("MyNotepad"),
                                                                   tr("Are you sure?\n"),
                                                                   QMessageBox::Yes | QMessageBox::No,
                                                                   QMessageBox::No);
       if (resBtn != QMessageBox::Yes) {
           event->ignore();
       } else {
           event->accept();
       }
   }
};
#endif // MAINWINDOW_H
