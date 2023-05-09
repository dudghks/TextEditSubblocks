#include "codesubblocksettings.h"

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>

CodeSubblockSettings::CodeSubblockSettings(QWidget* parent) : QDialog(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    QFormLayout *formLayout = new QFormLayout;
    QLabel *backgroundColorLabel = new QLabel("Background Color");
    QPushButton *backgroundColorButton = new QPushButton;
    QLabel *borderColorLabel = new QLabel("Border Color");
    QPushButton *borderColorButton = new QPushButton;
    QLabel *borderStyleLabel = new QLabel("Border Style");
    QComboBox *borderStyleBox = new QComboBox;
    QDialogButtonBox *buttonBox = new QDialogButtonBox;

    setLayout(verticalLayout);
    formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    verticalLayout->addLayout(formLayout);
    formLayout->addRow(backgroundColorLabel, backgroundColorButton);
    formLayout->addRow(borderColorLabel, borderColorButton);
    formLayout->addRow(borderStyleLabel, borderStyleBox);

    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    verticalLayout->addWidget(buttonBox);

    setWindowTitle(tr("Code Subblock Settings"));
    setFixedSize(400, 300);
}

