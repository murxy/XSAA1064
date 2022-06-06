/*
Header file from SAA1064 lib for XServe Raid

www.murxy.link
*/

#ifndef XSAA1064_h
#define XSAA1064_h

#include <inttypes.h>

namespace murxy {

class XSAA1064 {
public:
    static constexpr uint8_t LinkLed = 0;

    explicit XSAA1064(uint8_t address = 0) noexcept;

    void begin(uint8_t address);
    void begin();

    void clear();

    void set(uint8_t from, uint8_t to, bool enabled);
    void set(uint8_t position, bool enabled = true);
    void setAll(bool enabled);

    bool get(uint8_t position) const;
    bool initialized() const;

    void update();

    static uint8_t ledCount();

private:
    uint8_t mAddress;
    uint32_t mLeds;
    uint8_t mDirtyFlag : 1;
};

} // namespace murxy

#endif
