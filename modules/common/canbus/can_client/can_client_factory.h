/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Defines the CanClientFactory class.
 */

#ifndef MODULES_COMMON_CANBUS_CAN_CLIENT_CAN_CLIENT_FACTORY_H_
#define MODULES_COMMON_CANBUS_CAN_CLIENT_CAN_CLIENT_FACTORY_H_

#include <memory>
#include <unordered_map>

#include "modules/common/canbus/can_client/can_client.h"
#include "modules/common/macro.h"
#include "modules/common/util/factory.h"

/**
 * @namespace apollo::common::canbus
 * @brief apollo::common::canbus
 */
namespace apollo {
namespace common {
namespace canbus {

/**
 * @class CanClientFactory
 * @brief CanClientFactory inherites apollo::common::util::Facotory.
 */
class CanClientFactory
    : public apollo::common::util::Factory<CANCardParameter::CANCardBrand,
                                           CanClient> {
 public:
  /**
   * @brief Register the CAN clients of all brands. This function call the
   *        Function apollo::common::util::Factory::Register() for all of the
   *        CAN clients.
   */
  void RegisterCanClients();

  /**
   * @brief Create a pointer to a specified brand of CAN client. The brand is
   *        set in the parameter.
   * @param parameter The parameter to create the CAN client.
   * @return A pointer to the created CAN client.
   */
  std::unique_ptr<CanClient> CreateCANClient(const CANCardParameter &parameter);

 private:
  DECLARE_SINGLETON(CanClientFactory);
};

}  // namespace canbus
}  // namespace common
}  // namespace apollo

#endif  // MODULES_COMMON_CANBUS_CAN_CLIENT_CAN_CLIENT_FACTORY_H_
