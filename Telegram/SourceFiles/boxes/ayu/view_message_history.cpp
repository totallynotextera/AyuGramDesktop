#include "view_message_history.h"

#include "lang/lang_keys.h"
#include "base/random.h"
#include "boxes/peer_list_controllers.h"
#include "ui/widgets/buttons.h"
#include "ui/widgets/fields/special_fields.h"
#include "ui/widgets/popup_menu.h"
#include "ui/ui_utility.h"
#include "data/data_cloud_file.h"
#include "main/main_session.h"
#include "styles/style_layers.h"


MessageHistoryBox::MessageHistoryBox(QWidget *) {}

void MessageHistoryBox::prepare() {
    setTitle(rpl::single(QString("Message history")));
    setDimensions(st::boxWidth, 900);
}

void MessageHistoryBox::save() {
    closeBox();
}