#pragma once

#include <QString>

class Expense
{
public:
    Expense(const QString &description,
            double amount,
            const QString &category);

    QString description() const;
    double amount() const;
    QString category() const;

private:
    QString m_description;
    double m_amount;
    QString m_category;
};