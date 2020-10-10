#pragma once
#include "NativeModules.h"
using namespace winrt::Microsoft::ReactNative;


namespace NAMESPACE {

	REACT_MODULE(MODULE);
	struct MODULE {

		REACT_METHOD(DeviceModel, L"deviceModel");
		winrt::hstring MODULE::DeviceModel() noexcept;

		REACT_CONSTANT_PROVIDER(ConstantsViaConstantsProvider);
		void ConstantsViaConstantsProvider(ReactConstantProvider& provider) noexcept;
	
		REACT_SYNC_METHOD(getUniqueIdSync);
        winrt::hstring getUniqueIdSync() noexcept;

		REACT_SYNC_METHOD(getDeviceIdSync);
        winrt::hstring getDeviceIdSync() noexcept;

		REACT_METHOD(getDeviceIdSync);
		void getDeviceId(ReactPromise<winrt::hstring> promise) noexcept;

		REACT_SYNC_METHOD(getDeviceIdSync);
		winrt::hstring getSystemManufacturerSync() noexcept;
		
		REACT_METHOD(getSystemManufacturer);
		void getSystemManufacturer(ReactPromise<winrt::hstring> promise) noexcept;

		REACT_SYNC_METHOD(isTabletSync);
		bool isTabletSync() noexcept;

		REACT_METHOD(isTablet);
		void isTablet(ReactPromise<bool> promise) noexcept;

		REACT_METHOD(getTotalMemory);
		void getTotalMemory(ReactPromise<long> promise) noexcept;

		REACT_SYNC_METHOD(getTotalMemorySync);
		long getTotalMemorySync() noexcept;




	};


} // namespace MODULE
