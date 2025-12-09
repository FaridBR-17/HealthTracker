#include "LoginWindow.h"
#include "DatabaseManager.h"
#include "RegisterWindow.h"
#include "MainWindow.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Login");
    resize(300, 150);

    usernameInput = new QLineEdit();
    usernameInput->setPlaceholderText("Usuario");

    passwordInput = new QLineEdit();
    passwordInput->setPlaceholderText("Contraseña");
    passwordInput->setEchoMode(QLineEdit::Password);

    QPushButton* loginBtn = new QPushButton("Ingresar");

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginBtn);

    setLayout(layout);

    connect(loginBtn, &QPushButton::clicked, this, &LoginWindow::attemptLogin);
}

void LoginWindow::attemptLogin()
{
    QString username = usernameInput->text();
    QString password = passwordInput->text();

    if (DatabaseManager::instance().validateUser(username, password)) {
        MainWindow* mw = new MainWindow();
        mw->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos.");
    }
}
