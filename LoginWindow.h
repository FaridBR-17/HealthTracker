#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>

class LoginWindow : public QWidget {
    Q_OBJECT
public:
    explicit LoginWindow(QWidget* parent = nullptr);

private slots:
    void attemptLogin();
    void openRegisterWindow();

private:
    QLineEdit* usernameInput;
    QLineEdit* passwordInput;
};

#endif
