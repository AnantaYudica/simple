#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

namespace simple
{

struct IdentifierConstant {};

typedef simple::IdentifierConstant IDConst; 

struct AnonymousIDConst : simple::IDConst {};

}

#endif //!IDENTIFIER_H_
