#ifndef TALORION_UNDEFINED_STATE_HPP
#define TALORION_UNDEFINED_STATE_HPP

#include "abstract_system_state.hpp"

namespace talorion {

  class undefined_state : public abstract_system_state
  {
    Q_OBJECT
  public:
    undefined_state(QObject *par = nullptr);
    virtual ~undefined_state()=default;
  private:
    Q_DISABLE_COPY(undefined_state)

    // abstract_system_state interface
  public:
    virtual abstract_system_state* state_transition(abstract_system* sys, abstract_system::state_input_t input)Q_DECL_OVERRIDE;
    virtual abstract_system::state_t type() const Q_DECL_OVERRIDE;
    virtual void enter(abstract_system *sys) Q_DECL_OVERRIDE{Q_UNUSED(sys);}
    virtual void exit(abstract_system *sys) Q_DECL_OVERRIDE{Q_UNUSED(sys);}
  };

} // namespace talorion

#endif // TALORION_UNDEFINED_STATE_HPP
