/*
 * Copyright (C) 2025 Seclususs
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <string>
#include <functional>
#include "config.h"

class TouchMonitor {
public:
    using BoostCallback = std::function<void(BoostLevel, int)>;
    explicit TouchMonitor(BoostCallback callback);
    void start();

private:
    std::string findTouchDevice();
    void monitor();
    void setRefreshRate(const std::string& rate);

    BoostCallback boost_callback_;
    std::string touch_device_path_;
};
