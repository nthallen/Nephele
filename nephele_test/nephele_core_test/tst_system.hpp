#ifndef TST_SYSTEM_H
#define TST_SYSTEM_H

#include <QString>
#include <QtTest>

class tst_system: public QObject
{
    Q_OBJECT
public:
    tst_system(QObject *par = 0);
    ~tst_system() = default;

private slots:
    void initTestCase();

    void cleanupTestCase();

    void init();

    void cleanup();

private slots:
    void system_is_in_undefined_state_after_creation();
    void initalize_changes_system_state();
    void configuration_widget_is_null_after_creation();

};

#endif // TST_SYSTEM_H
