#include "jynxmainwindow.h"
#include "repodialog.h"
#include "ui_repodialog.h"
#include <iostream>

#include <QMessageBox>
#include <QPushButton>

repoDialog::repoDialog(QWidget *parent) :
    QDialog(parent),
    repo_ui(new Ui::repoDialog)
{
    repo_ui->setupUi(this);
    this->set_style_sheets();
    this->setWindowIcon(QIcon("/jynx/data/icon.png"));
}
repoDialog::~repoDialog()
{
    delete repo_ui;
}

void repoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QString b = button->text();
    if (!b.compare("&OK"))
    {
        if(!(repo_ui->repoName->text().isEmpty() || repo_ui->repoPath->text().isEmpty()))
        {
            w_instance->set_combobox_item(repo_ui->repoName->text(), repo_ui->repoPath->text());
            repo_ui->repoName->clear();
            repo_ui->repoPath->clear();
            return;
        }

        QMessageBox msgBox;
        msgBox.setText("You must to specify a name and a complete path to repository.");
        msgBox.exec();

    }
}

void repoDialog::setw_instance(jynxMainWindow *w)
{
    w_instance = w;
}

void  repoDialog::set_style_sheets()
{
        repo_ui->repoName->setStyleSheet(
            "QLineEdit {"
                "border-style: outset;"
                "border-radius: 5px;"
            "}"
        );
        repo_ui->repoPath->setStyleSheet(
            "QLineEdit {"
                "border-style: outset;"
                "border-radius: 5px;"
            "}"
        );
}



