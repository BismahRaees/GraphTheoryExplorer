#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

int main()
{
    QApplication app(__argc, __argv); // Use predefined global variables for QApplication
    QWidget window;
    window.setWindowTitle("Friendship Finder");
    window.resize(700, 500);

    QPushButton *loadButton = new QPushButton("Load Dataset", &window);
    loadButton->setGeometry(50, 30, 200, 40);

    QTextEdit *outputArea = new QTextEdit(&window);
    outputArea->setGeometry(50, 90, 600, 300);

    QObject::connect(loadButton, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(&window, "Open Dataset", "", "CSV Files (.csv);;All Files ()");
        if (fileName.isEmpty())
        {
            QMessageBox::warning(&window, "No File", "No file selected.");
            return;
        }

        std::ifstream file(fileName.toStdString().c_str());
        if (!file)
        {
            QMessageBox::critical(&window, "Error", "Error opening file.");
            return;
        }