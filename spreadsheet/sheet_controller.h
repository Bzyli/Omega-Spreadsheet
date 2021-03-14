#ifndef APPS_SHEET_CONTROLLER_H
#define APPS_SHEET_CONTROLLER_H

#include <escher.h>
#include "sheet_view.h"

namespace Spreadsheet {
    class SheetController : public ViewController  {
        public:
            SheetController(); //Responder * parentResponder
            View * view() override;
            bool handleEvent(Ion::Events::Event event) override;
            void didBecomeFirstResponder() override;
        private:
            SheetView m_sheetView;
    };
    
}

#endif