/******************************************************************************
 * Includes
 ******************************************************************************/
#include "XSAA1064.h"

#include <Arduino.h>
#include <Wire.h>

namespace murxy {

/******************************************************************************
 * Definitions
 ******************************************************************************/
namespace Register {
    constexpr uint8_t Control = 0x00;
    constexpr uint8_t Digit1 = 0x01;
    constexpr uint8_t Digit2 = 0x02;
    constexpr uint8_t Digit3 = 0x03;
    constexpr uint8_t Digit4 = 0x04;
} // namespace Register

namespace DelayFor {
    constexpr uint32_t Initialize = 100u;
    constexpr uint32_t Update = 0u;
} // namespace Timeout

namespace Led {

constexpr uint8_t Count = 24;
constexpr uint32_t All = 0b00001111011111110111111001111110;
constexpr uint32_t None = 0b00000000000000000000000000000000;

const uint32_t At[Count] = {
    0b00000000000000000000000000000001,
    0b00000000000000000000000000000010,
    0b00000000000000000000001000000000,
    0b00000000000000000000000000000100,
    0b00000000000000000000010000000000,
    0b00000000000000000000000000001000,

    0b00000000000000000000100000000000,
    0b00000000000000000000000000010000,
    0b00000000000000000001000000000000,
    0b00000000000000000000000000100000,
    0b00000000000000000010000000000000,
    0b00000000000000000000000001000000,

    0b00000000000000000100000000000000,
    0b00000000000000010000000000000000,
    0b00000001000000000000000000000000,
    0b00000000000000100000000000000000,
    0b00000010000000000000000000000000,
    0b00000000000001000000000000000000,

    0b00000100000000000000000000000000,
    0b00000000000010000000000000000000,
    0b00001000000000000000000000000000,
    0b00000000000100000000000000000000,
    0b00000000001000000000000000000000,
    0b00000000010000000000000000000000,
};

} // namespace Led

/******************************************************************************
 * Constructors
 ******************************************************************************/
XSAA1064::XSAA1064(uint8_t address) noexcept
    : mAddress(address)
    , mLeds(Led::None)
    , mDirtyFlag(true) {}

/******************************************************************************
 * User API
 ******************************************************************************/
void XSAA1064::begin(uint8_t address) {
    mAddress = address;
    begin();
}

void XSAA1064::begin() {
    Wire.begin();
    Wire.beginTransmission(mAddress);
    const uint8_t arr[]{ Register::Control, 0b00100111 };
    Wire.write(arr, sizeof(arr));
    Wire.endTransmission();
    delay(DelayFor::Initialize);
}

void XSAA1064::clear() {
    mLeds = Led::None;
    mDirtyFlag = true;
}

void XSAA1064::set(uint8_t from, uint8_t to, bool enabled) {
    if (from > to) {
        set(LinkLed, false);
        return;
        // set(to, from, enabled);
    }
    if (to >= Led::Count) to = Led::Count;
    if (from == LinkLed && to == Led::Count) {
        setAll(enabled);
        return;
    }
    if (from == to) {
        set(from, enabled);
        return;
    }
    for(uint8_t current{ from }; current < to; ++current) {
        set(current, enabled);
    }
}

void XSAA1064::set(uint8_t position, bool enabled) {
    if (position >= Led::Count)
        return;

    if (enabled)
        mLeds |= Led::At[position];
    else
        mLeds &= ~Led::At[position];

    mDirtyFlag = true;
}

void XSAA1064::setAll(bool enabled) {
    mLeds = (enabled ? Led::All : Led::None);
    mDirtyFlag = true;
}

bool XSAA1064::get(uint8_t position) const {
    if (position >= Led::Count)
        return false;
    return static_cast<bool>(mLeds & ~Led::At[position]);
}

bool XSAA1064::initialized() const {
    return mAddress != 0;
}

void XSAA1064::update() {
    if (!mDirtyFlag)
        return;
    Wire.beginTransmission(mAddress);
    Wire.write(Register::Digit1);
    Wire.write(reinterpret_cast<const uint8_t*>(&mLeds), sizeof(mLeds));
    Wire.endTransmission();
    delay(DelayFor::Update);
    mDirtyFlag = false;
}

uint8_t XSAA1064::ledCount() {
    return Led::Count;
}

} // namespace murxy
