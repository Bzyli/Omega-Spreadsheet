#include "app.h"
#include "spreadsheet_icon.h"
#include "apps/apps_container.h"
#include "apps/i18n.h"
#include <assert.h>

namespace spreadsheet {
    I18n::Message App::Descriptor::name() 
    {
         return I18n::Message::SpreadsheetApp;
    }

    I18n::Message App::Descriptor::upperName()
    {
        return I18n::Message::SpreadsheetAppCapital;
    }

    const Image * App::Descriptor::icon() 
    {
        return ImageStore::SpreadsheetIcon;
    }

    App::Snapshot::Snapshot(){
    }

    App * App::Snapshot::unpack(Container * container) {
        return new (container->currentAppBuffer()) App(this);
    }

    App::Descriptor * App::Snapshot::descriptor() {
        static Descriptor descriptor;
    return &descriptor;
    }

    void App::Snapshot::reset() {
    }

    App::App(Snapshot * snapshot) :
        ::App(snapshot, &m_sheetController),
        m_sheetController(this)
        {
        }

}