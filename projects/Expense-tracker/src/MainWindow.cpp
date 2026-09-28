#include "MainWindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      m_totalLabel(new QLabel("Rs. 0.00")),
      m_descriptionInput(new QLineEdit),
      m_amountInput(new QDoubleSpinBox),
      m_categoryInput(new QComboBox),
      m_expenseList(new QListWidget),
      m_addButton(new QPushButton("Add Expense"))
{
    setWindowTitle("Expense Tracker");
    resize(800, 600);

    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Expense Tracker"));
    layout->addWidget(new QLabel("Total Spent"));
    layout->addWidget(m_totalLabel);

    layout->addWidget(new QLabel("Description"));
    layout->addWidget(m_descriptionInput);

    layout->addWidget(new QLabel("Amount"));
    layout->addWidget(m_amountInput);

    layout->addWidget(new QLabel("Category"));
    m_categoryInput->addItems({"Food",
                               "Transport",
                               "Education",
                               "Shopping",
                               "Bills",
                               "Other"});
    layout->addWidget(m_categoryInput);

    layout->addWidget(m_addButton);
    layout->addWidget(m_expenseList);

    connect(
        m_addButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            QMessageBox::information(
                this,
                "Test",
                "Button works!");
        });
}

void MainWindow::addExpense()
{
}

void MainWindow::updateTotal()
{
}