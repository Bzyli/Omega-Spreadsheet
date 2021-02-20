apps += spreadsheet::App
app_headers += apps/spreadsheet/app.h

app_sspreadsheet_src = $(addprefix apps/spreadsheet/,\
  app.cpp \
  sheet_controller.cpp \
)

apps_src += $(app_sspreadsheet_src)

app_images += apps/spreadsheet/spreadsheet_icon.png

i18n_files += $(call i18n_without_universal_for,spreadsheet/base)

$(eval $(call depends_on_image,apps/spreadsheet/app.cpp,apps/spreadsheet/spreadsheet_icon.png))