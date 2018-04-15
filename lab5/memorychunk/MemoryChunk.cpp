//
// Created by adrja on 10.04.2018.
//

#include "MemoryChunk.h"
#include <cstdint>
#include <algorithm>

using ::std::swap;
using ::memorychunk::MemoryChunk;

MemoryChunk::MemoryChunk(size_t sz) {
    if (sz == 0) {
        pointer_size_ = 0;
        pointer_ = nullptr;
    }
    pointer_ = new int8_t[sz];
    pointer_size_ = sz;
}

int8_t *MemoryChunk::MemoryAt(size_t offset) const {
    return pointer_ + offset;
}

size_t MemoryChunk::ChunkSize() const {
    return pointer_size_;
}

MemoryChunk::MemoryChunk(const MemoryChunk &memoryChunk) {
    pointer_size_ = memoryChunk.ChunkSize();
    pointer_ = new int8_t[pointer_size_];
    std::copy(memoryChunk.MemoryAt(0), memoryChunk.MemoryAt(memoryChunk.ChunkSize()), pointer_);
}

MemoryChunk::MemoryChunk(MemoryChunk &&memoryChunk) {
    pointer_ = nullptr;
    pointer_size_ = 0;
    swap(pointer_, memoryChunk.pointer_);
    swap(pointer_size_, memoryChunk.pointer_size_);
}

MemoryChunk &MemoryChunk::operator=(const MemoryChunk &memoryChunk) {
    if (this == &memoryChunk) {
        return *this;
    }
    delete pointer_;
    pointer_size_ = memoryChunk.ChunkSize();
    pointer_ = new int8_t[pointer_size_];
    std::copy(memoryChunk.MemoryAt(0), memoryChunk.MemoryAt(memoryChunk.ChunkSize()), pointer_);
    return *this;
}

MemoryChunk &MemoryChunk::operator=(MemoryChunk &&memoryChunk) {
    if (this == &memoryChunk) {
        return *this;
    }
    delete[] pointer_;
    pointer_ = nullptr;
    pointer_size_ = 0;
    swap(pointer_size_, memoryChunk.pointer_size_);
    swap(pointer_, memoryChunk.pointer_);
    return *this;
}

MemoryChunk::~MemoryChunk() {
    delete[]  pointer_;
    pointer_size_ = 0;
}
