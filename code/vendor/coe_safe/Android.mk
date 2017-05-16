# Copyright (C) 2011 The Android Open Source Project
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
LOCAL_PATH:= $(call my-dir)

$(warning "cooee:    coe_safe Android.mk was bulid start")
$(warning "cooee-----------------------------------")
# COE_SAFE_FUNCTION := true
ifeq ($(strip $(COE_SAFE_FUNCTION)), true)
$(warning "cooee:    COE_SAFE_FUNCTION is true")
include $(CLEAR_VARS)
LOCAL_MODULE := byland.apk
LOCAL_MODULE_CLASS := byland
LOCAL_MODULE_PATH := $(TARGET_OUT)/priv-app/Hera
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := GtechBlocker.apk
LOCAL_MODULE_CLASS := GtechBlocker
LOCAL_MODULE_PATH := $(TARGET_OUT)/priv-app/GtechBlocker
LOCAL_MODULE_OWNER := google
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)

ifeq ($(strip $(TARGET_IS_64_BIT)), true)
$(warning "cooee:    TARGET_IS_64_BIT is true")
include $(CLEAR_VARS)
LOCAL_MODULE := libdaemon_api20.so
LOCAL_MODULE_CLASS := libdaemon_api20
LOCAL_MODULE_PATH := $(TARGET_OUT)/priv-app/GtechBlocker/lib/arm
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libdaemon_api21.so
LOCAL_MODULE_CLASS := libdaemon_api21
LOCAL_MODULE_PATH := $(TARGET_OUT)/priv-app/GtechBlocker/lib/arm
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)
else
$(warning "cooee:    TARGET_IS_64_BIT is false")
include $(CLEAR_VARS)
LOCAL_MODULE := libdaemon_api20.so
LOCAL_MODULE_CLASS := libdaemon_api20
LOCAL_MODULE_PATH := $(TARGET_OUT)/priv-app/GtechBlocker/lib/arm
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libdaemon_api21.so
LOCAL_MODULE_CLASS := libdaemon_api21
LOCAL_MODULE_PATH := $(TARGET_OUT)/priv-app/GtechBlocker/lib/arm
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)
endif

include $(CLEAR_VARS)
LOCAL_MODULE := XposedBridge.jar
LOCAL_MODULE_CLASS := XposedBridge
LOCAL_MODULE_PATH := $(TARGET_OUT)/framework
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := xposed.prop
LOCAL_MODULE_CLASS := xposed
LOCAL_MODULE_PATH := $(TARGET_OUT)
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)
endif

$(warning "cooee-----------------------------------")
$(warning "cooee:    coe_safe Android.mk was bulid end")

