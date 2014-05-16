
#ifndef REPODIALOG_H
#define REPODIALOG_H

#include <QDialog>
#include <QAbstractButton>

class jynxMainWindow;

namespace Ui {
class repoDialog;
}

class repoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit repoDialog(QWidget *parent = 0);
    ~repoDialog();
    //static jynxMainWindow * w_instance() {static jynxMainWindow *www; return www;}
    void setw_instance(jynxMainWindow *w);
    void set_style_sheets();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::repoDialog *repo_ui;
    jynxMainWindow *w_instance;
    QString repo;


};
#endif // REPODIALOG_H
