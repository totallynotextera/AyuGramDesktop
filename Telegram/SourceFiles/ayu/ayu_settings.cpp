#include "ayu_settings.h"

namespace AyuSettings {
    const QString filename = "tdata/ayu_settings.json";
    const int latestMigration = 1;
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
        settings.migrationVersion = latestMigration;
        QByteArray json = settings.toRawJson();

        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        file.write(json);
        file.close();
    }
}
