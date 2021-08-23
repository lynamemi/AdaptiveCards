// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "TimeInput.h"
#include "AdaptiveInputElement.h"
#include "AdaptiveTimeInput.g.h"

namespace winrt::AdaptiveCards::ObjectModel::WinUI3::implementation
{
    struct DECLSPEC_UUID("5d05c3fe-f808-4181-9f44-3a802b556a43") AdaptiveTimeInput : AdaptiveTimeInputT < AdaptiveTimeInput, ITypePeek>, AdaptiveInputElementBase
    {
        AdaptiveTimeInput(const std::shared_ptr<::AdaptiveCards::TimeInput>& sharedTimeInput = std::make_shared<::AdaptiveCards::TimeInput>());

        property<hstring> Max;
        property<hstring> Min;
        property<hstring> Placeholder;
        property<hstring> Value;

        // IAdaptiveCardElement
        auto ElementType() { return ElementType::TimeInput; }

        virtual std::shared_ptr<::AdaptiveCards::BaseCardElement> GetSharedModel() override;

        // ITypePeek method
        void* PeekAt(REFIID riid) override { return PeekHelper(riid, this); }

    private:
        Microsoft::WRL::Wrappers::HString m_max;
        Microsoft::WRL::Wrappers::HString m_min;
        Microsoft::WRL::Wrappers::HString m_placeholder;
        Microsoft::WRL::Wrappers::HString m_value;
    };
}

namespace winrt::AdaptiveCards::ObjectModel::WinUI3::factory_implementation
{
    struct AdaptiveTimeInput : AdaptiveTimeInputT<AdaptiveTimeInput, implementation::AdaptiveTimeInput>
    {
    };
}
