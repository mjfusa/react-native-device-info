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
		
		REACT_SYNC_METHOD(getBundleIdSync);
		winrt::hstring getBundleIdSync() noexcept;

		REACT_METHOD(getBundleId);
		void getBundleId(ReactPromise<winrt::hstring> promise) noexcept;

		
		REACT_SYNC_METHOD(getSystemVersionSync);
		winrt::hstring getSystemVersionSync() noexcept;

		REACT_METHOD(getSystemVersion);
		void getSystemVersion(ReactPromise<winrt::hstring> promise) noexcept;

		REACT_SYNC_METHOD(getAppVersionSync);
		winrt::hstring getAppVersionSync() noexcept;

		REACT_METHOD(getAppVersion);
		void getAppVersion(ReactPromise<winrt::hstring> promise) noexcept;


		REACT_SYNC_METHOD(getBuildNumberSync);
		winrt::hstring getBuildNumberSync() noexcept;

		REACT_METHOD(getBuildNumber);
		void getBuildNumber(ReactPromise<winrt::hstring> promise) noexcept;

		REACT_SYNC_METHOD(getAppNameSync);
		winrt::hstring getAppNameSync() noexcept;

		REACT_METHOD(getAppName);
		void getAppName(ReactPromise<winrt::hstring> promise) noexcept;

		REACT_SYNC_METHOD(getBrandSync) 
		winrt::hstring getBrandSync() noexcept;

		REACT_METHOD(getBrand);
		void getBrand(ReactPromise<winrt::hstring> promise) noexcept;

		REACT_SYNC_METHOD(getModelSync);
		winrt::hstring getModelSync() noexcept;

		REACT_METHOD(getModel);
		void getModel(ReactPromise<winrt::hstring> promise) noexcept;


		REACT_SYNC_METHOD(isEmulatorSync);
		bool isEmulatorSync() noexcept;
		

		REACT_METHOD(isEmulator);
		void isEmulator(ReactPromise<bool> promise) noexcept;
		
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
