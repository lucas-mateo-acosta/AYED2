#include <assert.h>
#include <stdlib.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t d) {
    bool b = true;
    if (d!=NULL){
        if (d->left!=NULL){
            b = b && key_less(d->left->key, d->key);
        }
        if (d->right!=NULL){
            b = b && key_less(d->key, d->right->key);
        }
        if (b==false){
            return false;
        }
        invrep(d->left);
        invrep(d->right);
    }

    return b;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict)==0u);
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict));
    if (dict==NULL){
        dict = malloc(sizeof(struct _node_t));
        assert(dict!=NULL);
        dict->key = word;
        dict->value = def;
        dict->left = NULL;
        dict->right = NULL;
    } else {
        if (key_less(word, dict->key)){
            dict->left = dict_add(dict->left, word, def);
        } else if (key_less(dict->key, word)){
            dict->right = dict_add(dict->right, word, def);
        } else if (key_eq(dict->key, word)){
            dict->value = def;
        }
    }
    assert(invrep(dict) && key_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    assert(invrep(dict));
    value_t def = NULL;
    if (dict!=NULL){
        if (key_eq(word, dict->key)){
            def = dict->value;
        } else if (key_less(word, dict->key)){
            def = dict_search(dict->left, word);
        } else if (key_less(dict->key, word)){
            def = dict_search(dict->right, word);
        }
    }
    assert(invrep(dict) && (def != NULL) == dict_exists(dict, word));
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    bool exists=false;
    assert(invrep(dict));
    if (dict!=NULL){
        if (key_eq(dict->key, word)){
            return true;
        }
        if (exists==false){
            exists = dict_exists(dict->left, word) || dict_exists(dict->right, word);
        }
    }
    assert(invrep(dict));
    return exists;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length=0u;
    assert(invrep(dict));
    if (dict!=NULL){
        length = 1 + dict_length(dict->left) + dict_length(dict->right);  
    }
    assert(invrep(dict) && (dict==NULL || length > 0));
    return length;
}

dict_t dict_remove(dict_t dict, key_t word) {
    assert(invrep(dict));
    struct _node_t *search = dict;
    struct _node_t *aux = NULL;
    if (dict!=NULL){
        while (search!=NULL && !key_eq(search->key, word)){
            if (key_less(search->key, word)){
                aux = search;
                search = search->right;
            } else {
                aux = search;
                search = search->left;
            }
        }
        if (search!=NULL){
            if (search->left==NULL && search->right==NULL){
                if (key_eq(aux->left->key, word)){
                    aux->left = NULL;
                } else if (key_eq(aux->right->key, word)){
                    aux->right = NULL;
                }
                free(search);
                search=NULL;

            }  else if (search->left!=NULL && search->right==NULL){
                if (aux->left!=NULL && key_eq(aux->left->key, word)){
                    aux->left = search->left;
                } else if (aux->right!=NULL && key_eq(aux->right->key, word)){
                    aux->right = search->left;
                }
                free(search);
                search=NULL;

            } else if (search->left==NULL && search->right!=NULL){
                if (aux->left!=NULL && key_eq(aux->left->key, word)){
                    aux->left = search->right;
                } else if (aux->right!=NULL && key_eq(aux->right->key, word)){
                    aux->right = search->right;
                }
                free(search);
                search=NULL;

            } else if (search->left!=NULL && search->right!=NULL){
                search = search->right;
                struct _node_t *parent = NULL;
                while (search->left!=NULL){
                    parent = search;
                    search = search->left;
                }
               
                if (key_eq(aux->left->key, word)){
                    aux->left->key = search->key;
                    aux->left->value = search->value;
                } else if (key_eq(aux->right->key, word)){
                    aux->right->key = search->key;
                    aux->right->value = search->value;
                }
                free(search);
                search=NULL;
                parent->left = search;
            }
        }
    }
    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    dict = dict_destroy(dict);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict) && file!=NULL);
    if (dict != NULL) {
        const char *key = string_ref(dict->key);
        const char *value = string_ref(dict->value);
        dict_dump(dict->left, file);
        fprintf(file, "%s:%s\n", key, value);
        dict_dump(dict->right, file);
    }
}

dict_t dict_destroy(dict_t dict) {
    assert(invrep(dict));
    if (dict!=NULL){
        dict_t dict_left = dict->left;
        dict_t dict_right = dict->right;
        dict->key = string_destroy(dict->key);
        dict->value = string_destroy(dict->value);
        free(dict);
        dict = NULL;
        dict_left = dict_destroy(dict_left);
        dict_right = dict_destroy(dict_right);
    }
    assert(dict==NULL);
    return dict;
}

