//
// Created by junior1407 on 31/08/22.
//

#ifndef YETANOTHERGBEMU_SIXTEENBITREGISTERS_H
#define YETANOTHERGBEMU_SIXTEENBITREGISTERS_H

#include "Definitions.h"

class SixteenBitRegister
{
public:
    SixteenBitRegister() { }
    void SetLow(u8 low);
    u8 GetLow() const;
    void SetHigh(u8 high);
    u8 GetHigh() const;
    u8* GetHighRegister();
    u8* GetLowRegister();
    void SetValue(u16 value);
    u16 GetValue() const;
    void Increment();
    void Decrement();

private:
    union sixteenBit
    {
        u16 v;
        struct
        {
            uint8_t high;
            uint8_t low;
        };
    } m_Value;
};


inline void SixteenBitRegister::SetLow(u8 low)
{
    m_Value.low = low;
}

inline u8 SixteenBitRegister::GetLow() const
{
    return m_Value.low;
}

inline void SixteenBitRegister::SetHigh(u8 high)
{
    m_Value.high = high;
}

inline u8 SixteenBitRegister::GetHigh() const
{
    return m_Value.high;
}

inline u8* SixteenBitRegister::GetHighRegister()
{
    return &m_Value.high;
}

inline u8* SixteenBitRegister::GetLowRegister()
{
    return &m_Value.low;
}

inline void SixteenBitRegister::SetValue(u16 value)
{
    m_Value.v = value;
}

inline u16 SixteenBitRegister::GetValue() const
{
    return m_Value.v;
}

inline void SixteenBitRegister::Increment()
{
    m_Value.v++;
}

inline void SixteenBitRegister::Decrement()
{
    m_Value.v--;
}


#endif //YETANOTHERGBEMU_SIXTEENBITREGISTERS_H
