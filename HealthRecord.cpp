#include "HealthRecord.h"

HealthRecord::HealthRecord(int id, int userId, const QString &ts,
                           double weight, int sys, int dia, double glucose)
    : m_id(id), m_userId(userId), m_timestamp(ts),
      m_weight(weight), m_systolic(sys), m_diastolic(dia), m_glucose(glucose)
{}

int HealthRecord::id() const { return m_id; }
int HealthRecord::userId() const { return m_userId; }
QString HealthRecord::timestamp() const { return m_timestamp; }
double HealthRecord::weight() const { return m_weight; }
int HealthRecord::systolic() const { return m_systolic; }
int HealthRecord::diastolic() const { return m_diastolic; }
double HealthRecord::glucose() const { return m_glucose; }
