//
// Created by adrja on 10.04.2018.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H


#include <cstdint>
#include <cstddef>

namespace memorychunk {
    class MemoryChunk {
    public:
        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

//Rule of five://
        //1. konstruktor kopiujący
        MemoryChunk(const MemoryChunk &memoryChunk);

        //2. konstruktor przenoszący
        MemoryChunk(MemoryChunk &&memoryChunk);

        //3. operator przypisania kopiujący
        MemoryChunk &operator=(const MemoryChunk &memoryChunk);

        //4. operator przypisania przenoszący
        MemoryChunk &operator=(MemoryChunk &&memoryChunk);

        //5. Destruktor
        ~MemoryChunk();

    private:
        size_t pointer_size_;
        int8_t *pointer_;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
