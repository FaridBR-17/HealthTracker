#ifndef HEALTHRECORD_H
#define HEALTHRECORD_H

#include <QString>

class HealthRecord {
public:
    HealthRecord() = default;
    HealthRecord(int id, int userId, const QString &ts,
                 double weight, int sys, int dia, double glucose);

    int id() const;
    int userId() const;
    QString timestamp() const;
    double weight() const;
    int systolic() const;
    int diastolic() const;
    double glucose() const;

private:
    int m_id{ -1 };
    int m_userId{ -1 };
    QString m_timestamp;
    double m_weight{ -1.0 };
    int m_systolic{ -1 };
    int m_diastolic{ -1 };
    double m_glucose{ -1.0 };
};

#endif
