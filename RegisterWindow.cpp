#include "RegisterWindow.h"
#include "DatabaseManager.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("Registro");

    usernameInput = new QLineEdit();
    usernameInput->setPlaceholderText("Nuevo Usuario");

    passwordInput = new QLineEdit();
    passwordInput->setPlaceholderText("Nueva Contraseña");
    passwordInput->setEchoMode(QLineEdit::Password);

    QPushButton* registerBtn = new QPushButton("Registrar");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(registerBtn);

    connect(registerBtn, &QPushButton::clicked, this, &RegisterWindow::registerUser);
}

void RegisterWindow::registerUser() {
    QString user = usernameInput->text();
    QString pass = passwordInput->text();

    if (DatabaseManager::instance().registerUser(user, pass)) {
        QMessageBox::information(this, "Éxito", "Usuario registrado.");
        this->close();
    }
    else {
        QMessageBox::warning(this, "Error", "No se pudo registrar (usuario existente).");
    }
}
