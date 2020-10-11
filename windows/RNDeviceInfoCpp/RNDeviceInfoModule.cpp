#include "pch.h"
#include INCLUDE_FILE_X(MODULE.h)

#include <winrt/Windows.Security.ExchangeActiveSyncProvisioning.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.System.Profile.h>

using namespace winrt::Windows::Security::ExchangeActiveSyncProvisioning;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::UI::ViewManagement;
using namespace winrt::Windows::ApplicationModel;
using namespace winrt::Windows::System::Profile;
using namespace NAMESPACE;

winrt::hstring MODULE::DeviceModel() noexcept {
  auto info = EasClientDeviceInformation();
  return info.SystemProductName();
}

void MODULE::ConstantsViaConstantsProvider(ReactConstantProvider  &provider) noexcept {
    provider.Add(L"uniqueId", getUniqueIdSync());
    provider.Add(L"deviceId", getDeviceIdSync());
    provider.Add(L"bundleId", getBundleIdSync());
    provider.Add(L"systemVersion", getSystemVersionSync());
    provider.Add(L"appVersion", getAppVersionSync());
    provider.Add(L"buildNumber", getBuildNumberSync());
    provider.Add(L"isTablet", isTabletSync());
    provider.Add(L"appName", getAppNameSync());
    provider.Add(L"brand", getBrandSync());
    provider.Add(L"model", getModelSync());
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

winrt::hstring MODULE::getBundleIdSync() noexcept {
    return Package::Current().Id().Name();
}

void MODULE::getBundleId(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getBundleIdSync());
}

winrt::hstring MODULE::getSystemVersionSync() noexcept {
    try
    {
        auto deviceInfo = EasClientDeviceInformation();
        winrt::hstring deviceFamilyVersion = AnalyticsInfo::VersionInfo().DeviceFamilyVersion();
        long version2 = _wtol(deviceFamilyVersion.data());
        long major = (version2 & 0xFFFF000000000000L) >> 48;
        long minor = (version2 & 0x0000FFFF00000000L) >> 32;
        return winrt::to_hstring(major) + L"." + winrt::to_hstring(minor);
    }
    catch (winrt::hresult_error const& ex )
    {
        return ex.message();
    }
}

void MODULE::getSystemVersion(ReactPromise<winrt::hstring> promise) noexcept
{
    promise.Resolve(getSystemVersionSync());
}

winrt::hstring MODULE::getAppVersionSync() noexcept {
    try
    {
        PackageVersion version = Package::Current().Id().Version();
        return winrt::to_hstring(version.Major) + L"." + winrt::to_hstring(version.Minor) + L"." + winrt::to_hstring(version.Build) + L"." + winrt::to_hstring(version.Revision);
    }
    catch (winrt::hresult_error const& ex)
    {
        return ex.message();
    }
}

void MODULE::getAppVersion(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getAppVersionSync());
}

winrt::hstring MODULE::getBuildNumberSync() noexcept {
    try
    {
        return winrt::to_hstring(Package::Current().Id().Version().Build);
    }
    catch (winrt::hresult_error const& ex)
    {
        return ex.message();
    }
}

void MODULE::getBuildNumber(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getBuildNumberSync());
}

winrt::hstring MODULE::getAppNameSync() noexcept {
    return Package::Current().DisplayName();
}

void MODULE::getAppName(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getAppNameSync());
}

winrt::hstring MODULE::getBrandSync() noexcept {
    return getModelSync();
}

void MODULE::getBrand(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getBrandSync());
}

winrt::hstring MODULE::getModelSync() noexcept {
    try
    {
        return EasClientDeviceInformation().SystemProductName();
    }
    catch (winrt::hresult_error const& ex)
    {
        return ex.message();
    }
}

void MODULE::getModel(ReactPromise<winrt::hstring> promise) noexcept {
    promise.Resolve(getModelSync());
}

bool MODULE::isEmulatorSync() noexcept {
    try
    {
        auto deviceInfo = EasClientDeviceInformation();
        return deviceInfo.SystemProductName() == L"Virtual";
    }
    catch (winrt::hresult_error )
    {
        return false;
    }
}

void MODULE::isEmulator(ReactPromise<bool> promise) noexcept {
    promise.Resolve(isEmulatorSync());
}










bool MODULE::isTabletSync() noexcept {
    try
    {
        auto uiMode = UIViewSettings::GetForCurrentView().UserInteractionMode();
        return (uiMode == UserInteractionMode::Touch); // Touch == Tablet mode
    }
    catch (winrt::hresult_error)
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
