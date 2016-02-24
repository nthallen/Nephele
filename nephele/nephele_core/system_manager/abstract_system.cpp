#include "abstract_system.hpp"

#include "configuration_widget/abstract_configuration_widget.hpp"

#include "entity_manager/entity_manager.hpp"

namespace talorion {

  entity_manager abstract_system::s_ent_mng;

  abstract_system::abstract_system(QObject *par) :
    QObject(par)
  {

  }


  void abstract_system::initialize(){
    do_initialize();
  }

  void abstract_system::dispose()
  {
    do_dispose();
  }

  void abstract_system::start()
  {

  }

  entity_manager &abstract_system::get_entity_manager() const
  {
    return s_ent_mng;
  }

  QStringList abstract_system::get_default_components() const
  {
    return do_get_default_components();
  }

}
