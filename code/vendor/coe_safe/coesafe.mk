#
# Copyright (C) 2015 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This file includes all definitions that apply to ALL angler devices, and
# are also specific to angler devices
#
# Everything in this directory will become public
$(warning "cooee:    coesafe.mk was bulid start")
$(warning "cooee-----------------------------------")
# libxpoase_art module
ifeq ($(strip $(COE_SAFE_FUNCTION)), true)
$(warning "cooee:    COE_SAFE_FUNCTION is true")
ifeq (1,$(strip $(shell expr $(PLATFORM_SDK_VERSION) \>= 21)))
$(warning "cooee:    PLATFORM_SDK_VERSION >= 21")
PRODUCT_PACKAGES += \
    libxposed_art \
    GtechBlocker.apk \
    byland.apk
else
$(warning "cooee:    PLATFORM_SDK_VERSION  < 21")
PRODUCT_PACKAGES += \
    libxposed_dalvik \
    GtechBlocker.apk \
    byland.apk
endif

# libxposed module
PRODUCT_COPY_FILES += \
    vendor/coe_safe/xposed.prop:system/xposed.prop:google \
    vendor/coe_safe/XposedBridge.jar:system/framework/XposedBridge.jar:google

ifeq ($(strip $(TARGET_IS_64_BIT)), true)
$(warning "cooee:    TARGET_IS_64_BIT is true")
PRODUCT_COPY_FILES += \
    vendor/coe_safe/libdaemon_api20.so:system/priv-app/GtechBlocker/lib/arm/libdaemon_api20.so:google \
    vendor/coe_safe/libdaemon_api21.so:system/priv-app/GtechBlocker/lib/arm/libdaemon_api21.so:google
else
$(warning "cooee:    TARGET_IS_64_BIT is false")
PRODUCT_COPY_FILES += \
    vendor/coe_safe/libdaemon_api20.so:system/priv-app/GtechBlocker/lib/arm/libdaemon_api20.so:google \
    vendor/coe_safe/libdaemon_api21.so:system/priv-app/GtechBlocker/lib/arm/libdaemon_api21.so:google
endif
endif
$(warning "cooee-----------------------------------")
$(warning "cooee:    coesafe.mk was bulid end")
