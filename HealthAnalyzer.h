#ifndef HEALTHANALYZER_H
#define HEALTHANALYZER_H

#include <QVector>
#include "HealthRecord.h"

class HealthAnalyzer {
public:
    static double averageWeight(const QVector<HealthRecord>& records);
    static double averageSystolic(const QVector<HealthRecord>& records);
    static double averageDiastolic(const QVector<HealthRecord>& records);
    static double averageGlucose(const QVector<HealthRecord>& records);

    static QString riskSummary(const QVector<HealthRecord>& records);
};

#endif
