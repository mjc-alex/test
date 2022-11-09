#include "mytest.h"
#define NR_WP 32
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  bool isfree;
  long long val;
} WP;

static WP wp_pool[NR_WP] ;
static WP *head = NULL, *free_ = NULL;
void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].isfree = true;
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
  for(int i = 0;i < NR_WP;++i){
    if(wp_pool[i].isfree == true){
      for(int j = i;j < NR_WP - 1;++j)
        wp_pool[j] = wp_pool[j+1];
      if(i == NR_WP - 1) wp_pool[i - 1].next = NULL;
      wp_pool[i].isfree = false;
      wp_pool[i].next = NULL;
      return &wp_pool[i];
    }
  }
  assert(0);
}
int main(){
    init_wp_pool();
    head = new_wp();
    P("%d\n%d\n",head->next->NO,wp_pool[1].next->NO);
    return 0;
}



