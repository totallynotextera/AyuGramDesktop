#pragma once

#include "boxes/abstract_box.h"
#include "base/timer.h"
#include "mtproto/sender.h"

class MessageHistoryBox: public Ui::BoxContent {
public:
    MessageHistoryBox(QWidget*);
protected:
    void prepare() override;

private:
    void save();
};