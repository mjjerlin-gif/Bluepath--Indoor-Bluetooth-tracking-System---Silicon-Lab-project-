#include "sl_bluetooth.h"
#include "sl_status.h"
#include "app_assert.h"
#include "app_log.h"
#include "sl_bluetooth_advertiser.h"

// Unique Beacon UUID
static const uint8_t beacon_uuid[16] = {
  0x01, 0x12, 0x23, 0x34,
  0x45, 0x56, 0x67, 0x78,
  0x89, 0x9A, 0xAB, 0xBC,
  0xCD, 0xDE, 0xEF, 0xF0
};

// Location Info (You can change this for each beacon)
#define LOCATION_NAME "BLOCK_A_FLOOR_1_ROOM_101"

void app_init(void)
{
  app_log(" BluePath Indoor Beacon Started\r\n");
  app_log(" Location: %s\r\n", LOCATION_NAME);
}

void app_process_action(void)
{
  // Nothing to do in loop; beacon keeps advertising automatically
}

void sl_bt_on_event(sl_bt_msg_t *evt)
{
  sl_status_t sc;

  switch (SL_BT_MSG_ID(evt->header)) {

    // System boot event
    case sl_bt_evt_system_boot_id:
      app_log("System Booted. Starting Beacon...\r\n");

      // Set advertising data as iBeacon
      uint8_t adv_data[] = {
        0x02, 0x01, 0x06,             // Flags
        0x1A, 0xFF,                   // Length + Manufacturer specific data
        0x4C, 0x00,                   // Apple company ID (for iBeacon format)
        0x02, 0x15,                   // iBeacon indicator
        // UUID
        0x01, 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78,
        0x89, 0x9A, 0xAB, 0xBC, 0xCD, 0xDE, 0xEF, 0xF0,
        // Major
        0x00, 0x01,
        // Minor
        0x00, 0x02,
        // Measured Power
        0xC5
      };

      sc = sl_bt_advertiser_set_data(0, 0, sizeof(adv_data), adv_data);
      app_assert_status(sc);

      // Start advertising continuously
      sc = sl_bt_advertiser_start(0, sl_bt_advertiser_non_connectable, sl_bt_advertiser_user_data);
      app_assert_status(sc);

      app_log("Beacon advertising started!\r\n");
      break;

    default:
      break;
  }
}
