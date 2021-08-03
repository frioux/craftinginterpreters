#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node* next;
  struct node* prev;
  char* contents;
};

void print_node(struct node *ll) {
  while (ll) {
    printf("«%s» ", ll->contents);
    ll = ll->next;
  }
  printf("\n");
}

void remove_str(struct node *ll, char *str) {

}

void remove_at(struct node *ll, char *str) {

}

void append(struct node *ll, char *str) {
        struct node n;
        n.contents = str;
        n.prev = ll;
        ll->next = &n;
}

int main() {
        struct node n;
        n.contents = (char *)malloc(sizeof(char)*4);
        *(n.contents+0) = 'x';
        *(n.contents+1) = '\0';
        print_node(&n);
        append(&n, "frew");
        print_node(&n);
}
