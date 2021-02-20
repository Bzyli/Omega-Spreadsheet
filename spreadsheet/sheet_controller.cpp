#include "sheet_controller.h"


namespace spreadsheet {
    View* SheetController::view() {
        return &m_tableView;
    }
    SheetController::SheetController(Responder * parentResponder):
        ViewController(parentResponder),
        m_tableView(this, this){
    }
    
        int SheetController::numberOfRows() const { 
            return 2;
        }

        KDCoordinate SheetController::cellHeight() {
            return 50;
        }
        HighlightCell * SheetController::reusableCell(int index) {
            return nullptr;
        }

        int SheetController::reusableCellCount() const {
            return 8;
        }
}