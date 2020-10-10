#include "pch.h"
#include INCLUDE_FILE_X(MODULE.h)

#include <winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>

using namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::UI::ViewManagement;
using namespace NAMESPACE;

winrt::hstring MODULE::DeviceModel() noexcept {
  auto info = EasClientDeviceInformation();
  return info.SystemProductName();
}

void MODULE::ConstantsViaConstantsProvider(ReactConstantProvider  &provider) noexcept {
    provider.Add(L"uniqueId", getUniqueIdSync());
}

winrt::hstring MODULE::getUniqueIdSync() noexcept {
    try
    {
        auto deviceInfo = EasClientDeviceInformation();
        return winrt::to_hstring(deviceInfo.Id());
    }
    catch (winrt::hresult_error const &ex)
    {
        return ex.message();
    }
}

winrt::hstring MODULE::getDeviceIdSync() noexcept {
    try
    {
        auto deviceInfo = EasClientDeviceInformation();
        return deviceInfo.SystemHardwareVersion();
    }
    catch (winrt::hresult_error const& ex)
    {
        return ex.message();
    }
}

void MODULE::getDeviceId(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getDeviceIdSync());
}

winrt::hstring MODULE::getSystemManufacturerSync() noexcept {
    try
    {
        auto deviceInfo = EasClientDeviceInformation();
        return deviceInfo.SystemManufacturer();
    }
    catch (winrt::hresult_error const& ex)
    {
        return ex.message();
    }
}

void MODULE::getSystemManufacturer(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getSystemManufacturerSync());
}


bool MODULE::isTabletSync() noexcept {
    try
    {
        //auto uiview = UIViewSettings::UserInteractionMode;
        //UserInteractionMode a = uiview.UserInteractionMode();
        //return (a == UserInteractionMode::Touch); // Touch == Table mode

        return (false);
    }
    catch (winrt::hresult_error const& ex)
    {
        return false;
    }
}

void MODULE::isTablet(ReactPromise<bool> promise) noexcept {
    promise.Resolve(isTabletSync());
}

void MODULE::getTotalMemory(ReactPromise<long> promise) noexcept {
    promise.Resolve(-1);
}

long MODULE::getTotalMemorySync() noexcept {
    return -1;
}
