#ifndef APPS_SHEET_VIEW_H
#define APPS_SHEET_VIEW_H

#include <escher.h>

namespace Spreadsheet {
    class SheetView  : public View {
        public:
            SheetView();
            void drawRect(KDContext * ctx, KDRect rect) const override;
            void reload();
            void changeColor();
            int numberOfSubviews() const override;
            View * subviewAtIndex(int index) override;
        private:
            void layoutSubviews(bool force = false) override;
            BufferTextView m_bufferTextView;
            int m_color;
            KDColor m_kdcolor;
    };
}


#endif