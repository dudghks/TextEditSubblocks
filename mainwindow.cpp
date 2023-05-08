#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>
#include <QTextEdit>
#include <QScrollBar>
#include <QTextFrame>
#include <QTextFrameFormat>
#include <QToolButton>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Set up document
    QSizeF pageSize = QSizeF(BlockTextEdit::inchesToPixels(8.5), BlockTextEdit::inchesToPixels(11));
    ui->textEdit->setPixelPageSize(pageSize);
    QMarginsF pageMargins = QMarginsF(BlockTextEdit::inchesToPixels(1), BlockTextEdit::inchesToPixels(1),
                                      BlockTextEdit::inchesToPixels(1), BlockTextEdit::inchesToPixels(1));
    ui->textEdit->setPixelPageMargins(pageMargins);
    ui->textEdit->setPageBreakGap(20);
    ui->textEdit->document()->setDefaultFont(QFont("Courier", 12));

    // Lists to keep track of sub blocks and their associated buttons
//    QTextFrame* newFrame = nullptr;
//    QList<QTextFrame*> frames;
//    QList<QToolButton*> buttons;
//    QList<CodeSubblock> csb;
    // When insert subblock button is clicked, insert new subblock
    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
        ui->textEdit->insertCodeBlock(ui->centralwidget);
    });


//    connect(ui->pushButton, &QPushButton::clicked, this, [this, newFrame, frames, buttons, csb]() mutable {
//        // Create new subblock edit button
//        QToolButton* newButton = new QToolButton(this);
//        buttons.append(newButton);

//        // Make subblock button visible
//        ui->centralwidget->layout()->addWidget(newButton);
//        buttons.constLast()->setParent(ui->centralwidget);

//        // Set up subblock format
//        QTextFrameFormat format;
//        format.setBorder(1);
//        format.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);

//        // Insert new frame
//        ui->textEdit->textCursor().insertFrame(format);
//        newFrame = ui->textEdit->textCursor().currentFrame();
//        frames.append(newFrame);

//        CodeSubblock newCodeBlock(newFrame);
//        csb.append(newCodeBlock);

//        // Keep the button on top of the frame
//        connect(ui->textEdit->verticalScrollBar(), &QScrollBar::valueChanged, this, [this, frames, buttons, csb]() {
//            // Get the bounding rectangle of the frame
//            QRectF frameRect = ui->textEdit->document()->documentLayout()->frameBoundingRect(frames.constLast());

//            // Convert the frame-bounding rectangle coordinate system to the one of the central widget
//            QPointF frameRectTopLeft = ui->textEdit->viewport()->mapTo(ui->centralwidget, frameRect.topLeft());
//            frameRectTopLeft.setY(frameRectTopLeft.y() - ui->textEdit->verticalScrollBar()->value());

//            // Move the button over the frame
//            QRectF border = QRectF(frameRectTopLeft, frameRect.size());
//            buttons.constLast()->setGeometry(border.toRect());
//            buttons.constLast()->repaint();
//        });

//    });

//    QTextDocument *doc = new QTextDocument();
//    QSizeF documentSize = QSizeF(500, 500);
//    QMargins documentMargins = QMargins(50, 50, 50, 50);

//    doc->setPageSize(documentSize);
//    doc->setDocumentMargin(0);


//    connect(ui->textEdit, &QTextEdit::textChanged, [](){
//
//    });
//    connect(ui->textEdit->verticalScrollBar(), &QScrollBar::rangeChanged, [](int min, int max){
//        Q_UNUSED(min)
//        Q_UNUSED(max)
//    });
//    connect(ui->textEdit->document()->documentLayout(), &QAbstractTextDocumentLayout::update, [documentSize, documentMargins, this](){

//        if (ui->textEdit->document()->pageSize() != documentSize) {
//            ui->textEdit->document()->setPageSize(documentSize);
//        }
//        if (ui->textEdit->document()->documentMargin() != 0) {
//            ui->textEdit->document()->setDocumentMargin(0);
//        }
//        QTextFrameFormat rootFrameFormat = ui->textEdit->document()->rootFrame()->frameFormat();
//        if (rootFrameFormat.leftMargin() != documentMargins.left()
//            || rootFrameFormat.topMargin() != documentMargins.top()
//            || rootFrameFormat.rightMargin() != documentMargins.right()
//            || rootFrameFormat.bottomMargin() != documentMargins.bottom()) {
//            rootFrameFormat.setLeftMargin(documentMargins.left());
//            rootFrameFormat.setTopMargin(documentMargins.top());
//            rootFrameFormat.setRightMargin(documentMargins.right());
//            rootFrameFormat.setBottomMargin(documentMargins.bottom());
//            ui->textEdit->document()->rootFrame()->setFrameFormat(rootFrameFormat);
//        }
//    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

