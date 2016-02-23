#ifndef SYSTEM_DUMMY_HPP
#define SYSTEM_DUMMY_HPP

#include <QObject>

#include "system_manager/abstract_system.hpp"

namespace talorion{
  class system_dummy : public abstract_system
  {
    Q_OBJECT
  public:
    explicit system_dummy(QObject *par = nullptr);
    ~system_dummy()=default;
    Q_DISABLE_COPY(system_dummy)

  signals:

  public slots:

  private:
    virtual state_trans_ret_t do_initialize() Q_DECL_OVERRIDE;
    virtual state_trans_ret_t do_start() Q_DECL_OVERRIDE;
    virtual state_trans_ret_t do_dispose() Q_DECL_OVERRIDE;
    virtual abstract_configuration_widget *do_get_configuration_widget() const Q_DECL_OVERRIDE;
  };
}

#endif // SYSTEM_DUMMY_HPP
