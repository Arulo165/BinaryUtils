#pragma once

#include <vector>
#include <cstring>
#include <types.h>

inline u32 Read32(const u8* ptr) 
{
    return (ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];
}

inline u16 Read16(const u8* ptr) 
{
    return (ptr[0] << 8) | ptr[1];
}

inline float ReadFloat(const u8* ptr) 
{
    u32 temp = (ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];
    float f;
    memcpy(&f, &temp, sizeof(float));
    return f;
}


inline void WriteFloatBE(std::vector<u8>& buffer, u32 offset, float value) 
{
    u32 temp;
    memcpy(&temp, &value, sizeof(float));
    buffer[offset]     = (temp >> 24) & 0xFF;
    buffer[offset + 1] = (temp >> 16) & 0xFF;
    buffer[offset + 2] = (temp >> 8) & 0xFF;
    buffer[offset + 3] = temp & 0xFF;
}

inline void Write16BE(std::vector<u8>& data, u32 offset, u16 value) 
{
    data[offset] = (value >> 8) & 0xFF;     
    data[offset + 1] = value & 0xFF;        
}

inline void Write32BE(std::vector<u8>& data, u32 offset, u32 value) 
{
    data[offset]     = (value >> 24) & 0xFF;
    data[offset + 1] = (value >> 16) & 0xFF;
    data[offset + 2] = (value >> 8) & 0xFF;
    data[offset + 3] = value & 0xFF;
}

inline uint32_t alignTo(uint32_t value, uint32_t alignment) 
{
    return (value + alignment - 1) & ~(alignment - 1);
}
