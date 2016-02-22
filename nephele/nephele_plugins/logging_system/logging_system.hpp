#ifndef TALORION_LOGGING_SYSTEM_HPP
#define TALORION_LOGGING_SYSTEM_HPP

//#include "system_manager/abstract_system.hpp"
#include "../../nephele_core/system_manager/abstract_system.hpp"

#include <QStringList>

namespace talorion {

  class logging_system : public abstract_system
  {
    Q_OBJECT
  public:
    explicit logging_system(QObject *par = nullptr);
    virtual ~logging_system();

  //private:
    //Q_DISABLE_COPY(logging_system)

  signals:

  public slots:

  public:
    QStringList get_all_entries()const{return m_entries;}

    // abstract_system interface
  private:
    virtual state_trans_ret_t do_initialize() Q_DECL_OVERRIDE;
    virtual state_trans_ret_t do_start() Q_DECL_OVERRIDE;
    virtual abstract_configuration_widget *do_get_configuration_widget() const Q_DECL_OVERRIDE;

  private:
    QStringList m_entries;
  };

} // namespace talorion

#endif // TALORION_LOGGING_SYSTEM_HPP
