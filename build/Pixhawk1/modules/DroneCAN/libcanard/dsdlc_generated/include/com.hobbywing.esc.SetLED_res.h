#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define COM_HOBBYWING_ESC_SETLED_RESPONSE_MAX_SIZE 3
#define COM_HOBBYWING_ESC_SETLED_RESPONSE_SIGNATURE (0xB493BD48C0853EE5ULL)
#define COM_HOBBYWING_ESC_SETLED_RESPONSE_ID 212

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class com_hobbywing_esc_SetLED_cxx_iface;
#endif

struct com_hobbywing_esc_SetLEDResponse {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = com_hobbywing_esc_SetLED_cxx_iface;
#endif
    uint8_t option;
    uint8_t color;
    uint8_t blink;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t com_hobbywing_esc_SetLEDResponse_encode(struct com_hobbywing_esc_SetLEDResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool com_hobbywing_esc_SetLEDResponse_decode(const CanardRxTransfer* transfer, struct com_hobbywing_esc_SetLEDResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _com_hobbywing_esc_SetLEDResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_hobbywing_esc_SetLEDResponse* msg, bool tao);
static inline void _com_hobbywing_esc_SetLEDResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_hobbywing_esc_SetLEDResponse* msg, bool tao);
void _com_hobbywing_esc_SetLEDResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct com_hobbywing_esc_SetLEDResponse* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->option);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->color);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->blink);
    *bit_ofs += 8;
}

void _com_hobbywing_esc_SetLEDResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct com_hobbywing_esc_SetLEDResponse* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->option);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->color);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->blink);
    *bit_ofs += 8;

}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct com_hobbywing_esc_SetLEDResponse sample_com_hobbywing_esc_SetLEDResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
