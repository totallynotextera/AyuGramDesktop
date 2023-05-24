#include "ayu_settings.h"

namespace AyuSettings {
    const QString filename = "ayu_settings.json";
    AyuGramSettings settings;

    AyuGramSettings &getInstance() {
        return settings;
    }

    void load() {
        QFile file(filename);
        if (!file.exists()) {
            return;
        }
        file.open(QIODevice::ReadOnly);
        QByteArray json = file.readAll();
        file.close();

        settings.fromJson(json);
    }

    void save() {
        QByteArray json = settings.toRawJson();

        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        file.write(json);
        file.close();
    }
}
