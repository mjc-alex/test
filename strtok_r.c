#include "mytest.h"
#define NR_WP 32
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  bool isfree;
  long long val;
} WP;

static WP wp_pool[NR_WP] = { };
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
      if(i == 0) {
      }
      else if(i == NR_WP - 1){
        wp_pool[i - 1].next = NULL;
      }
      else{
        wp_pool[i - 1].next = &wp_pool[i + 1];
      }
      wp_pool[i].isfree = false;
      wp_pool[i].next = NULL;
      return &wp_pool[i];
    }
  }
  assert(0);
}
void free_wp(WP *wp){
  for (int i = 0;i < wp->NO;++i){
    if(wp_pool[i].isfree == true){
      wp_pool[i].next = wp;
    }
  }
  for(int i = wp->NO;i < NR_WP;++i){
    if(wp_pool[i].isfree == true){
      wp->next = &wp_pool[i];
      break;
    }
    if(i == NR_WP - 1) wp->next = NULL;
  }
  wp->isfree = true;
}
int main(){
    init_wp_pool();
    head = new_wp();
    head->next = new_wp();
    head->next->next = new_wp();
    free_wp(head->next->next);
    free_wp(head->next);
    P("%d\n%d\n%d\n",wp_pool[3].next->NO,head->next->next->NO,wp_pool[2].next->NO);
    return 0;
}


