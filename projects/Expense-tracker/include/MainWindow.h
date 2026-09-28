#pragma once

#include <QWidget>
#include <QList>

#include "Expense.h"

class QLabel;
class QLineEdit;
class QDoubleSpinBox;
class QComboBox;
class QListWidget;
class QPushButton;

class MainWindow : public QWidget
{
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void addExpense();
    void updateTotal();

    QList<Expense> m_expenses;
    double m_total = 0.0;

    QLabel *m_totalLabel;
    QLineEdit *m_descriptionInput;
    QDoubleSpinBox *m_amountInput;
    QComboBox *m_categoryInput;
    QListWidget *m_expenseList;
    QPushButton *m_addButton;
};