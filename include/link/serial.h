#ifndef GUARD_LINK_SERIAL_H
#define GUARD_LINK_SERIAL_H

// Serial (link cable) multiplayer transfer.

void sub_080023D8(void);
void serial_link_init(void);
void serial_multiplayer_init(void);
void serial_prepare_send_packet(u16 *packet);
u32 serial_link_init_and_status(u32 *recv);
void serial_multiplayer_transfer_handler(void);
void sub_08002190(void);

#endif // GUARD_LINK_SERIAL_H
