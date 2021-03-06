#include "script_system.hpp"

#include <QDebug>
#include "scripting_worker.hpp"
#include "core/event_manager.hpp"

#include "script_config_widget/script_config_widget.hpp"

namespace talorion {

    script_system::script_system(QObject *par) :
        QThread(par),
        abstract_system("{8c2f892c-e2e2-417b-a3b1-96600e7822d3}"),
        config_wdg(NULL)
    {
        config_wdg = new script_config_widget();

        connect(event_manager::get_instance(),SIGNAL(application_aboutToQuit()),this,SLOT(quit()));
    }

    script_system::~script_system()
    {
        if(config_wdg)
            delete config_wdg;
    }


    void script_system::run()
    {
        scripting_worker* wrk = new scripting_worker();
        wrk->initialize();

        exec();

        delete wrk;
    }

    void script_system::do_start_system()
    {
        this->start();
    }

    abstract_configuration_widget *script_system::do_get_configuration_widget()
    {
        return config_wdg;
    }


}
