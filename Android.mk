ifeq ($(strip $(BUILD_WITH_GST)),true)

LOCAL_PATH := $(call my-dir)

LIBOIL_TOP := $(LOCAL_PATH)

include $(CLEAR_VARS)

include $(LIBOIL_TOP)/liboil/Android.mk

endif
