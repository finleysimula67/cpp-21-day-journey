#include "Expense.h"

Expense::Expense(const QString &description,
                 double amount,
                 const QString &category)
    : m_description(description),
      m_amount(amount),
      m_category(category)
{
}

QString Expense::description() const
{
    return m_description;
}

double Expense::amount() const
{
    return m_amount;
}

QString Expense::category() const
{
    return m_category;
}