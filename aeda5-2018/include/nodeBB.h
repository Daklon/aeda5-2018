#ifndef NODEBB_H
#define NODEBB_H
#include "DNI.h"

template<typename Clave>
class NodeBB
{
public:
    NodeBB(){

    }


private:
    NodeBB *father_ptr;
    NodeBB *leftChildren_ptr;
    NodeBB *rightChildren_ptr;
}

#endif
