#ifndef MD5_H
#define MD5_H

#include <string>
#include <cstring>

using std::string;

#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

//Rotate x left n bits
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
#define FF(a, b, c, d, x, s, ac)                     \
    {                                                \
        (a) += F((b), (c), (d)) + (x) + (UINT4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }
#define GG(a, b, c, d, x, s, ac)                     \
    {                                                \
        (a) += G((b), (c), (d)) + (x) + (UINT4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }
#define HH(a, b, c, d, x, s, ac)                     \
    {                                                \
        (a) += H((b), (c), (d)) + (x) + (UINT4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }
#define II(a, b, c, d, x, s, ac)                     \
    {                                                \
        (a) += I((b), (c), (d)) + (x) + (UINT4)(ac); \
        (a) = ROTATE_LEFT((a), (s));                 \
        (a) += (b);                                  \
    }

typedef unsigned char byte;
typedef unsigned short int UINT2;
typedef unsigned long int UINT4;

//MD5 Context
typedef struct
{
    UINT4 state[4]; // state (A,B,C,D)
    UINT4 count[2]; // number of bits
    unsigned char buffer[64];
} MD5_CTX;

class md5
{
  public:
    md5();
    void Digest(const string &str);
    void Print(byte digest[16]);

  private:
    static const byte PADDING[64];
    byte digest[16];

    void Init(MD5_CTX *context);
    void Update(MD5_CTX *context, const byte *input, size_t inputLen);
    void Final(byte digest[16], MD5_CTX *context);
    void Transform(UINT4 state[4], const byte block[64]);
    void Encode(byte *output, const UINT4 *input, size_t len);
    void Decode(UINT4 *output, const byte *input, size_t len);
};

#endif