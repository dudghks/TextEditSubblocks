#include "framehelper.h"
#include "blocktextedit.h"
#include <QTextEdit>
#include <QTextBlock>
#include <QAbstractTextDocumentLayout>


QRectF FrameHelper::boundingRect(BlockTextEdit* textEditor, QTextFrame* frame) {
    // Get the bounding rectangle of the frame
    QRectF frameRect = textEditor->document()->documentLayout()->frameBoundingRect(frame);

    // Convert the frame-bounding rectangle coordinate system to the one of the text editor
    QPointF frameRectTopLeft = textEditor->viewport()->mapTo(textEditor, frameRect.topLeft());
    return QRectF(frameRectTopLeft, frameRect.size());
}
