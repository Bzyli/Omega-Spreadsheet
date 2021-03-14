#include "sheet_view.h"
#include "apps/i18n.h"

namespace Spreadsheet {
    SheetView::SheetView():
        View(),
        m_bufferTextView(KDFont::LargeFont, 0.5, 0.5, KDColorBlack),
        m_color(3),
        m_kdcolor(Palette::GreyWhite){
        m_bufferTextView.setText(I18n::translate(I18n::Message::SpreadsheetApp));
    }

    void SheetView::drawRect(KDContext * ctx, KDRect rect) const {
         ctx->fillRect(KDRect(0, 0, bounds().width(), bounds().height()), m_kdcolor);
    }

    void SheetView::reload() {
        switch (m_color) {
            case 0:
                m_kdcolor = Palette::GreyDark;
                break;
            case 1:
                m_kdcolor = Palette::GreyMiddle;
                break;
            case 2:
                m_kdcolor = Palette::GreyBright;
                break;
            default:
                m_kdcolor = Palette::GreyWhite;
        }

        m_bufferTextView.setBackgroundColor(m_kdcolor);

        markRectAsDirty(bounds());
    }   

    void SheetView::changeColor() {
        m_color++;
        if(m_color > 3)
            m_color=0;

        reload();
    }

    int SheetView::numberOfSubviews() const {
        return 1;
    }

    View * SheetView::subviewAtIndex(int index) {
        return &m_bufferTextView;
    }

    void SheetView::layoutSubviews(bool force) {
        m_bufferTextView.setFrame(KDRect(0, 0, bounds().width(), bounds().height()), force);
    }
}