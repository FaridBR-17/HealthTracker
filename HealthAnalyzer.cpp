#include "HealthAnalyzer.h"

double HealthAnalyzer::averageWeight(const QVector<HealthRecord>& records) {
    double sum = 0; int c = 0;
    for (const auto& r : records) {
        if (r.weight() > 0) { sum += r.weight(); c++; }
    }
    return c == 0 ? -1 : sum / c;
}

double HealthAnalyzer::averageSystolic(const QVector<HealthRecord>& records) {
    double sum = 0; int c = 0;
    for (const auto& r : records) {
        if (r.systolic() > 0) { sum += r.systolic(); c++; }
    }
    return c == 0 ? -1 : sum / c;
}

double HealthAnalyzer::averageDiastolic(const QVector<HealthRecord>& records) {
    double sum = 0; int c = 0;
    for (const auto& r : records) {
        if (r.diastolic() > 0) { sum += r.diastolic(); c++; }
    }
    return c == 0 ? -1 : sum / c;
}

double HealthAnalyzer::averageGlucose(const QVector<HealthRecord>& records) {
    double sum = 0; int c = 0;
    for (const auto& r : records) {
        if (r.glucose() > 0) { sum += r.glucose(); c++; }
    }
    return c == 0 ? -1 : sum / c;
}

QString HealthAnalyzer::riskSummary(const QVector<HealthRecord>& records) {
    double sys = averageSystolic(records);
    double dia = averageDiastolic(records);
    double glu = averageGlucose(records);

    QString res;

    if (sys > 130 || dia > 85)
        res += "⚠ Riesgo de hipertensión.\n";

    if (glu > 110)
        res += "⚠ Glucosa elevada.\n";

    if (res.isEmpty())
        res = "Todo dentro de rangos normales.";

    return res;
}
