#ifndef CHANGEACCOUNTWINDOW_H
#define CHANGEACCOUNTWINDOW_H

#include "sessiondata.h"

#include <QAbstractButton>
#include <QDialog>

namespace Ui {
class ChangeAccountWindow;
}

class ChangeAccountWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeAccountWindow(QWidget *parent = nullptr, SessionData *session = nullptr);
    ~ChangeAccountWindow();

signals:
    void changeToAccount(int);

public slots:
    void updateUI();

private slots:
    void accountButtonClicked(QAbstractButton *);

    void on_buttonPrevious_clicked();
    void on_buttonNext_clicked();

    void on_buttonLogout_clicked();

private:
    Ui::ChangeAccountWindow *ui;
    int listIndex = 0;

    SessionData * session;
};

#endif // CHANGEACCOUNTWINDOW_H
