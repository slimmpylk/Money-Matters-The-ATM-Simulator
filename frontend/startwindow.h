#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "sessiondata.h"

#include "optionswindow.h"
#include "dllpincode.h"
#include "dllrestapi.h"
#include "dllserialport.h"
#include "spinner.h"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

signals:
    void testOhitaKorttiSignal(QString);
    void testOhitaPINSignal(int, QString);

private slots:
    void languageButtonClicked(int);
    void sound();
    void logout(QObject*);

    void openDLLPinCode(QString);

    void startSession(int, QString);
    void fetchDataWithDLL(int);
    void swapToAccount(int);

    void on_buttonOhitaKortti_clicked(); //this shall be removed on release
    void on_buttonOhitaPIN_clicked(); //this shall be removed on release

    void updateTime();
    void expireTimedStates();

private:
    Ui::StartWindow *ui;

    OptionsWindow * optionsWindow = nullptr;

    SessionData * session = nullptr;

    DLLPinCode * pDLLPinCode = nullptr;
    DLLRestApi * pDLLRestApi = nullptr;
    DLLSerialPort * pDLLSerialPort = nullptr;
    Spinner * pSpinner = nullptr;

    //QString state = "default";
    QString language = "fi";
    QTimer *timer;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    enum State {
        Default,
        Waiting,
        Running,
        Timeout,
        Error,
        Logout
    }state = Default;

    void openOptionsWindow();

    void updateUI(); 
};

#endif // STARTWINDOW_H
