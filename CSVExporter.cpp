#include "CSVExporter.h"
#include <QFile>
#include <QTextStream>

bool CSVExporter::exportRecords(const QString& filePath,
                                const QVector<HealthRecord>& records)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);

    out << "ID,UserID,Timestamp,Weight,Systolic,Diastolic,Glucose\n";

    for (const auto& r : records) {
        out << r.id() << ","
            << r.userId() << ","
            << r.timestamp() << ","
            << r.weight() << ","
            << r.systolic() << ","
            << r.diastolic() << ","
            << r.glucose() << "\n";
    }

    file.close();
    return true;
}
