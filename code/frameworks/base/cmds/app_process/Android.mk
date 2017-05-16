LOCAL_PATH:= $(call my-dir)

# This is a list of libraries that need to be included in order to avoid
# bad apps. This prevents a library from having a mismatch when resolving
# new/delete from an app shared library.
# See b/21032018 for more details.
app_process_common_shared_libs := \
    libwilhelm \

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    app_main.cpp

LOCAL_LDFLAGS := -Wl,--version-script,art/sigchainlib/version-script.txt -Wl,--export-dynamic

$(warning "cooee:    app_process Android.mk was bulid start")
# COE_SAFE_FUNCTION := true
ifeq ($(strip $(COE_SAFE_FUNCTION)), true)
$(warning "cooee-----------------------------------")
$(warning "cooee:    COE_SAFE_FUNCTION is true")
LOCAL_SRC_FILES += \
  xposed.cpp \
  xposed_logcat.cpp \
  xposed_service.cpp \
  xposed_safemode.cpp
endif

LOCAL_SHARED_LIBRARIES := \
    libdl \
    libcutils \
    libutils \
    liblog \
    libbinder \
    libandroid_runtime \
    $(app_process_common_shared_libs) \

LOCAL_WHOLE_STATIC_LIBRARIES := libsigchain

LOCAL_MODULE:= app_process
LOCAL_MULTILIB := both
LOCAL_MODULE_STEM_32 := app_process32
LOCAL_MODULE_STEM_64 := app_process64

ifeq ($(strip $(COE_SAFE_FUNCTION)), true)
LOCAL_CFLAGS += -Wall -Werror -Wextra -Wunused
else
LOCAL_CFLAGS += -Wall -Werror -Wunused -Wunreachable-code
endif
ifeq ($(strip $(COE_SAFE_FUNCTION)), true)
LOCAL_CFLAGS += -DPLATFORM_SDK_VERSION=$(PLATFORM_SDK_VERSION)
ifeq (1,$(strip $(shell expr $(PLATFORM_SDK_VERSION) \>= 17)))
  LOCAL_SHARED_LIBRARIES += libselinux
  LOCAL_CFLAGS += -DXPOSED_WITH_SELINUX=1
endif
LOCAL_CFLAGS += -D__COE_SAFE_FUNCTION__
endif

include $(BUILD_EXECUTABLE)

# Create a symlink from app_process to app_process32 or 64
# depending on the target configuration.
include  $(BUILD_SYSTEM)/executable_prefer_symlink.mk

# Build a variant of app_process binary linked with ASan runtime.
# ARM-only at the moment.
ifeq ($(TARGET_ARCH),arm)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    app_main.cpp

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    liblog \
    libbinder \
    libandroid_runtime \
    $(app_process_common_shared_libs) \

LOCAL_WHOLE_STATIC_LIBRARIES := libsigchain

LOCAL_LDFLAGS := -ldl -Wl,--version-script,art/sigchainlib/version-script.txt -Wl,--export-dynamic
LOCAL_CPPFLAGS := -std=c++11

LOCAL_MODULE := app_process__asan
LOCAL_MULTILIB := both
LOCAL_MODULE_STEM_32 := app_process32
LOCAL_MODULE_STEM_64 := app_process64

LOCAL_ADDRESS_SANITIZER := true
LOCAL_CLANG := true
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)/asan

LOCAL_CFLAGS += -Wall -Werror -Wunused -Wunreachable-code

include $(BUILD_EXECUTABLE)

endif # ifeq($(TARGET_ARCH),arm)

##########################################################
# Library for Dalvik-/ART-specific functions
##########################################################
# COE_SAFE_FUNCTION := true
ifeq ($(strip $(COE_SAFE_FUNCTION)), true)
ifeq (1,$(strip $(shell expr $(PLATFORM_SDK_VERSION) \>= 21)))
  include frameworks/base/cmds/app_process/ART.mk
else
  include frameworks/base/cmds/app_process/Dalvik.mk
endif
endif
