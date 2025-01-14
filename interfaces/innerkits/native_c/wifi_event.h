/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup wifiservice
 * @{
 *
 * @brief Provides functions for the Wi-Fi station and hotspot modes.
 *
 * You can use this module to enable and disable the Wi-Fi station or hotspot mode, connect to and disconnect from a
 * station or hotspot, query the station or hotspot status, and listen for events. \n
 *
 * @since 7
 */

/**
 * @file wifi_event.h
 *
 * @brief Defines callbacks and structure of Wi-Fi events.
 *
 * {@link RegisterWifiEvent} can be used to listen for Wi-Fi connection, disconnection, and scan events. \n
 *
 * @since 7
 */
#ifndef WIFI_EVENT_C_H
#define WIFI_EVENT_C_H

#include "wifi_linked_info.h"
#include "station_info.h"
#include "wifi_error_code.h"

/**
 * @brief Indicates that the Wi-Fi station mode is enabled.
 *
 */
#define WIFI_STA_ACTIVE 1
/**
 * @brief Indicates that the Wi-Fi station mode is disabled.
 *
 */
#define WIFI_STA_NOT_ACTIVE 0

/**
 * @brief Indicates that the Wi-Fi hotspot mode is enabled.
 *
 */
#define WIFI_HOTSPOT_ACTIVE 1
/**
 * @brief Indicates that the Wi-Fi hotspot mode is disabled.
 *
 */
#define WIFI_HOTSPOT_NOT_ACTIVE 0

/**
 * @brief Indicates the maximum number of event listeners that can be registered using {@link RegisterWifiEvent}.
 *
 * When the maximum number is reached, you need to unregister at least one listener before registering new ones. \n
 */
#define WIFI_MAX_EVENT_SIZE 10

/**
 * @brief Represents the pointer to a Wi-Fi event callback for station and hotspot connection, disconnection, or scan.
 *
 *
 * If you do not need a callback, set the value of its pointer to <b>NULL</b>. \n
 *
 * @since 7
 */
typedef struct {
    /** Connection state change */
    void (*OnWifiConnectionChanged)(int state, WifiLinkedInfo *info);
    /** Scan state change */
    void (*OnWifiScanStateChanged)(int state, int size);
    /** Hotspot state change */
    void (*OnHotspotStateChanged)(int state);
    /** Station connected */
    void (*OnHotspotStaJoin)(StationInfo *info);
    /** Station disconnected */
    void (*OnHotspotStaLeave)(StationInfo *info);
} WifiEvent;

/**
 * @brief Enumerates states in Wi-Fi events.
 *
 *
 *
 * @since 7
 */
typedef enum {
    /** Unavailable state */
    WIFI_STATE_NOT_AVALIABLE = 0,
    /** Available state */
    WIFI_STATE_AVALIABLE
} WifiEventState;

/**
 * @brief Registers a callback for a specified Wi-Fi event.
 *
 * The registered callback will be invoked when the Wi-Fi event defined in {@link WifiEvent} occurs. \n
 *
 * @param event Indicates the event for which the callback is to be registered.
 * @return Returns {@link WIFI_SUCCESS} if the callback is registered successfully; returns an error code defined
 * in {@link WifiErrorCode} otherwise.
 * @since 7
 */
WifiErrorCode RegisterWifiEvent(const WifiEvent *event);

/**
 * @brief Unregisters a callback previously registered for a specified Wi-Fi event.
 *
 * @param event Indicates the event for which the callback is to be unregistered.
 * @return Returns {@link WIFI_SUCCESS} if the callback is unregistered successfully; returns an error code defined
 * in {@link WifiErrorCode} otherwise.
 * @since 7
 */
WifiErrorCode UnRegisterWifiEvent(const WifiEvent *event);

#endif // WIFI_EVENT_C_H
/** @} */
