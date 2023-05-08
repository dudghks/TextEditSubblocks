#ifndef CODESUBBLOCK_H
#define CODESUBBLOCK_H

#include <QToolButton>
#include <QTextFrame>
#include <QTextFrameFormat>


class CodeSubblock
{
public:
    CodeSubblock(QTextFrame* _frame);
    void setFrame(QTextFrame* _frame);
    QTextFrame* frame() const;
    void setSettingsButton(QToolButton* _settingsButton);
    QToolButton* settingsButton() const;
    QTextFrameFormat format() const;

private:
    QTextFrame* m_frame;
    QToolButton* m_settingsButton;
    QTextFrameFormat m_format;
};

#endif // CODESUBBLOCK_H
