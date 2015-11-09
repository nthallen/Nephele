#ifndef TALORION_OCTAVE_SYSTEM_HPP
#define TALORION_OCTAVE_SYSTEM_HPP

#include <QThread>

#include "abstract_system.hpp"

namespace talorion {


    class octave_system : public QThread, public abstract_system
    {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "com.talorion.core.abstract_system" FILE "octave_system.json")
        Q_INTERFACES(talorion::abstract_system)
    public:
        explicit octave_system(QObject *par = 0);
        ~octave_system();
        Q_DISABLE_COPY(octave_system)



        virtual void register_entity_manager(abstract_entity_manager* entity_manager=NULL) Q_DECL_OVERRIDE {entity_manager_locator::provide(entity_manager);}
        virtual void register_event_manager(abstract_event_manager* event_manager=NULL) Q_DECL_OVERRIDE {event_manager_locator::provide(event_manager);}


    protected:
        virtual void run() Q_DECL_OVERRIDE;

    private:
        virtual void do_init_system() Q_DECL_OVERRIDE;
        virtual void do_dispose_system() Q_DECL_OVERRIDE;

        virtual void do_start_system() Q_DECL_OVERRIDE;
        virtual QString do_get_system_name() Q_DECL_OVERRIDE {return "octave_system";}
        virtual abstract_configuration_widget* do_get_configuration_widget() Q_DECL_OVERRIDE;

    private:

    };

} // namespace talorion

#endif // TALORION_OCTAVE_SYSTEM_HPP