#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

/*static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}*/

static bool invrep(abb tree) {
    bool b = true;
    if (tree!=NULL){
        if (tree->left!=NULL){
            b = b && tree->left->elem < tree->elem;
        }
        if (tree->right!=NULL){
            b = b && tree->right->elem > tree->elem;
        }
        if (b==false){
            return false;
        }
        invrep(tree->left);
        invrep(tree->right);
    }

    return b;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree==NULL){
        tree = malloc(sizeof(struct _s_abb));
        assert(tree!=NULL);
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if (tree->elem > e){
            tree->left = abb_add(tree->left, e);
        } else if (tree->elem < e){
            tree->right = abb_add(tree->right, e);
        } else if (tree->elem == e){
            tree->elem = e;
        }
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return tree==NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (tree!=NULL){
        if (tree->elem == e){
            return true;
        }
        if (exists==false){
            exists = abb_exists(tree->left, e) || abb_exists(tree->right, e);
        }
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree!=NULL){
        length = 1 + abb_length(tree->left) + abb_length(tree->right);  
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    struct _s_abb *search = tree;
    struct _s_abb *aux = NULL;
    if (tree!=NULL){
        while (search!=NULL && search->elem!=e){
            if (search->elem<e){
                aux = search;
                search = search->right;
            } else {
                aux = search;
                search = search->left;
            }
        }
        if (search!=NULL){
            if (search->left==NULL && search->right==NULL){
                if (aux->left->elem==e){
                    aux->left = NULL;
                } else if (aux->right->elem==e){
                    aux->right = NULL;
                }
                free(search);
                search=NULL;

            }  else if (search->left!=NULL && search->right==NULL){
                if (aux->left->elem==e){
                    aux->left = search->left;
                } else if (aux->right->elem==e){
                    aux->right = search->left;
                }
                free(search);
                search=NULL;

            } else if (search->left==NULL && search->right!=NULL){
                if (aux->left->elem==e){
                    aux->left = search->right;
                } else if (aux->right->elem==e){
                    aux->right = search->right;
                }
                free(search);
                search=NULL;

            } else if (search->left!=NULL && search->right!=NULL){
                search = search->right;
                struct _s_abb *parent = NULL;
                while (search->left!=NULL){
                    parent = search;
                    search = search->left;
                }
               
                if (aux->left->elem==e){
                    aux->left->elem = search->elem;
                } else if (aux->right->elem==e){
                    aux->right->elem = search->elem;
                }
                free(search);
                search=NULL;
                parent->left = search;
            }
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->right==NULL){
        return tree->elem;
    }
    max_e = abb_max(tree->right);
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->left==NULL){
        return tree->elem;
    }
    min_e = abb_min(tree->left);
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree!=NULL){
        abb tree_left = tree->left;
        abb tree_right = tree->right;
        free(tree);
        tree = NULL;
        tree_left = abb_destroy(tree_left);
        tree_right = abb_destroy(tree_right);
    }
    assert(tree == NULL);
    return tree;
}

