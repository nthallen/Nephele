#ifndef TALORION_ECMD_CONNECTION_MANAGER_HPP
#define TALORION_ECMD_CONNECTION_MANAGER_HPP

#include <QObject>
#include <QSignalMapper>

#include "ecmd_connection.hpp"
#include "tcpbox_factory.hpp"
#include "entity_manager/entity_manager.hpp"

namespace talorion {

  class tcpbox_system;
  class ecmd_connection;

  class ecmd_connection_manager : public QObject
  {
    Q_OBJECT
  public:
    using ecmd_connection_container = QMap<tcpbox_factory::tcpbox_t, QPointer<ecmd_connection> >;

  public:
    explicit ecmd_connection_manager(const tcpbox_system &sys, QObject *par = Q_NULLPTR);

  signals:
    void box_connected(entity_manager::entity_id_t);
    void box_disconnected(entity_manager::entity_id_t);

  public slots:
    //void add_box(entity_manager::entity_id_t tcpbox);
    //void delete_box(entity_manager::entity_id_t tcpbox);
    //void delete_all_boxes();

    void slot_new_tcpbox(entity_manager::entity_id_t tcpbox_id);
    void slot_delete_tcpbox(entity_manager::entity_id_t tcpbox_id);
    void slot_connect_box(entity_manager::entity_id_t tcpbox_id);
    void slot_disconnect_box(entity_manager::entity_id_t tcpbox_id);
    void slot_send_command_to_box(entity_manager::entity_id_t tcpbox_id, const QString& cmd);

  private slots:
    void connection_changed(int tcpbox_id);

  private:
    bool has_connection(entity_manager::entity_id_t tcpbox_id);

  private:
    ecmd_connection_container m_connections;
    const tcpbox_system& m_sys;
    QScopedPointer<QSignalMapper> m_signal_mapper;
  };

} // namespace talorion

#endif // TALORION_ECMD_CONNECTION_MANAGER_HPP