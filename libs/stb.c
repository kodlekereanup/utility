#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

// TODO: Makefile

typedef struct {
    size_t len;
    size_t cap;
    char* buf[0];
} BufHdr;

#define MAX(x, y) ((x) >= (y)? (x) : (y))

// stretchy buffers by Sean Barrett //
#define buf__hdr(b)     ((BufHdr*)((char*)b - offsetof(BufHdr, buf)))
#define buf__fits(b, n) (buf_len(b) + n <= buf_cap(b))
#define buf__fit(b, n)  (buf__fits(b, n) ? 0 : ((b) = buf__grow((b), buf_len(b) + (n), sizeof(*(b))))) 

#define buf_len(b)     ((b) ? buf__hdr(b)->len : 0)
#define buf_cap(b)     ((b) ? buf__hdr(b)->cap : 0)
#define buf_push(b, x) (buf__fit(b, 1), b[buf_len(b)] = (x), buf__hdr(b)->len++)
// the above is a hack cause of lvalue issues
// b[buf_len(b)++] should be doable 
#define buf_free(b) ((b) ? free(buf__hdr(b)) : 0)

void* buf__grow(const void* buf, size_t new_len, size_t  elem_size) {
    size_t new_cap = MAX(1 + 2 * buf_cap(buf), new_len);
    assert(new_len <= new_cap);
    size_t new_size = offsetof(BufHdr, buf) + new_cap * elem_size; // why?
    BufHdr* new_hdr;
    if(buf) {
        new_hdr = realloc(buf__hdr(buf), new_size);
    } else {
        new_hdr = malloc(new_size);
        new_hdr->len  = 0;
    }
    new_hdr->cap = new_cap;
    return new_hdr->buf;
}

void buf_test() {
    int* buf = NULL; 
    // Treats it as a zero length buffer (unallocated) and allocates 
    // a buffer on demand to accomodate the request of pushing something
    // and it's going to reassign the return value to the *buf itself
    const int n = 10;
    for(int i = 0; i < n; i++) buf_push(buf, 1); 
    assert(buf_len(buf) == n);
    for(int i = 0; i < buf_len(buf); i++) assert(buf[i] == i);
    buf_free(buf);
}

int main(int argc, char** argv) {
    buf_test();
    return 0;
}
