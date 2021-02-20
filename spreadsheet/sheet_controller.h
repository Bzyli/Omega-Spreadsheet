#ifndef __SHEET_CONTROLLER_H
#define __SHEET_CONTROLLER_H
#include <escher.h>

namespace spreadsheet{
    class SheetController :  public ViewController, public SimpleListViewDataSource, public ScrollViewDataSource{
        public : 
            SheetController(Responder * parentResponder);
            View* view() override;

            int numberOfRows() const override;
            KDCoordinate cellHeight() override;
            HighlightCell * reusableCell(int index) override;
            int reusableCellCount() const override;
            
        private:
            TableView m_tableView;
    };
}

#endif