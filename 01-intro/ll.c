#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct node *remove_at(struct node *ll, int i) {
        if (i == 1) {
                struct node *ret = ll->next;
                ret->prev = NULL;
                /* free(ll); */

                return ret;
        }

        struct node *ret = ll;
        struct node *prev = ll;

        while (ll) {
                i--;

                if (i == 0) {
                        // i = 2
                        //
                        // x -> y -> z -> NULL
                        // 1    2    3    4
                        //
                        // prev = x
                        // ll   = y
                        // next = z
                        //
                        // prev->next = next;
                        // next->prev = prev;
                        if (ll->next) {
                                struct node *next = ll->next;
                                prev->next = next;
                                next->prev = prev;
                        } else {
                                prev->next = NULL;
                        }
                        /* free(ll); */
                        return ret;
                }
                prev = ll;
                ll = ll->next;
        }

        if (i != 0) {
                printf("fell off the end of linked list when removing\n");
        }
}

struct node* tail(struct node *ll) {
        struct node *ret = ll;

        while (ll) {
                ret = ll;
                ll = ll->next;
        }

        return ret;
}

void append(struct node *ll, char *str) {
        struct node *t = tail(ll);
        struct node *n = malloc(sizeof(struct node));
        n->contents = str;
        n->next = NULL;
        n->prev = t;
        t->next = n;
}

int main() {
        struct node n;
        n.next = NULL;
        n.prev = NULL;
        n.contents = (char *)malloc(sizeof(char)*4);
        strcpy(n.contents, "x");
        print_node(&n);

        char *str = (char *)malloc(sizeof(char)*5);
        strcpy(str, "y");
        append(&n, str);
        print_node(&n);

        char *str2 = (char *)malloc(sizeof(char)*5);
        strcpy(str2, "z");
        append(&n, str2);
        print_node(&n);

        struct node *m = remove_at(&n, 3);
        print_node(m);
}
