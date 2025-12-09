#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include <QString>
#include <QVector>
#include "HealthRecord.h"

class CSVExporter {
public:
    static bool exportRecords(const QString& filePath,
                              const QVector<HealthRecord>& records);
};

#endif
