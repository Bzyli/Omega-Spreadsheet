#include "sheet_controller.h"
#include <assert.h>

namespace Spreadsheet {
    SheetController::SheetController(): //Responder * parentResponder
        ViewController(nullptr) //parentResponder
        {
        }

    View * SheetController::view() {
        return &m_sheetView;
    }

    void SheetController::didBecomeFirstResponder() {
    }

    bool SheetController::handleEvent(Ion::Events::Event event) {
        if (event == Ion::Events::OK || event == Ion::Events::EXE) {
            m_sheetView.changeColor();
            return true;
        }
    return false;
}
}