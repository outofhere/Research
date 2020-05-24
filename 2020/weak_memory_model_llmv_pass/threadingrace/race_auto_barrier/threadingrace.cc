#include <pthread.h>
#include <assert.h>
volatile unsigned __attribute__((aligned (256))) a = 1;
volatile unsigned __attribute__((aligned (256))) b = 1;

extern "C"
void * update(void *vargp) {
  while (a) {
    a++;
    b++;
  }
}

extern "C"
void * read(void *vargp) {
  unsigned al, bl;
  do {
    bl = b;
    al = a;

    assert(bl <= al);
  } while (bl);
}

int main() {
  pthread_t thread_id1;
  pthread_t thread_id2;
  pthread_create(&thread_id1, NULL, update, NULL);
  pthread_create(&thread_id2, NULL, read, NULL);
  pthread_join(thread_id1, NULL);
  pthread_join(thread_id2, NULL);

  return 0;
}
