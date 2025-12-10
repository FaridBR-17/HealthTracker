#include "LoginWindow.h"
#include "DatabaseManager.h"
#include "RegisterWindow.h"
#include "MainWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("Login");

    usernameInput = new QLineEdit();
    usernameInput->setPlaceholderText("Usuario");

    passwordInput = new QLineEdit();
    passwordInput->setPlaceholderText("Contraseña");
    passwordInput->setEchoMode(QLineEdit::Password);

    QPushButton* loginBtn = new QPushButton("Ingresar");
    QPushButton* registerBtn = new QPushButton("Registrarse");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginBtn);
    layout->addWidget(registerBtn);

    connect(loginBtn, &QPushButton::clicked, this, &LoginWindow::attemptLogin);
    connect(registerBtn, &QPushButton::clicked, this, &LoginWindow::openRegisterWindow);
}

void LoginWindow::attemptLogin() {
    QString user = usernameInput->text();
    QString pass = passwordInput->text();

    if (DatabaseManager::instance().validateUser(user, pass)) {

        
        MainWindow* main = new MainWindow(user);
        main->show();

        this->close();
    }
    else {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos");
    }
}

void LoginWindow::openRegisterWindow() {
    RegisterWindow* reg = new RegisterWindow();
    reg->show();
}
