#ifndef ABSTRACT_SYSTEM
#define ABSTRACT_SYSTEM

#include <QString>
#include <QWidget>

namespace talorion{
    class abstract_system
    {
    public:
        abstract_system():entity_id(-1){}
        virtual ~abstract_system(){}
        Q_DISABLE_COPY(abstract_system)

        void start_system(){return do_start_system();}
        QString get_system_name(){return do_get_system_name();}
        QWidget* get_configuration_widget(){return do_get_configuration_widget();}

        int getEntity_id() const{return entity_id;}
        void setEntity_id(int value){entity_id = value;}

    private:
        virtual void do_start_system()=0;
        virtual QString do_get_system_name()=0;
        virtual QWidget* do_get_configuration_widget()=0;

    private:
        int entity_id;
    };
}

#endif // ABSTRACT_SYSTEM

