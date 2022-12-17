#ifndef aicimaajut
#define aicimaajut

#include <inttypes.h>

typedef struct QuadtreeNode{
    unsigned char red, green, blue; // componentele care formeaza o culoare ce defineste blocul analizat
    uint32_t area; // numarul de pixeli din blocul descris de nod
    int32_t top_left; // indicele asociat nodului copil-1
    int32_t top_right; // indicele asociat nodului copil-2
    int32_t bottom_right; // indicele asociat nodului copil-3
    int32_t bottom_left; // indicele asociat nodului copil-4
}__attribute__((packed)) QuadtreeNode;


#endif