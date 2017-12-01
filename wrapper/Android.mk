
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := fingerprint.wrapper.$(TARGET_BOARD_PLATFORM)
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_RELATIVE_PATH := hw

LOCAL_SRC_FILES := fingerprint.cpp

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/../fingerprintd

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libbinder \
    libhardware \
    libutils \
    libfingerprintd_binder

LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

