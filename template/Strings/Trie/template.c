#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int NUM_CHARS = 26;

typedef struct TrieNode {
    struct TrieNode * children[NUM_CHARS];
    bool terminal;
} TrieNode;

TrieNode * creatNode() {
    TrieNode * newNode = (TrieNode *) malloc(sizeof * newNode);

    for (int i = 0; i < NUM_CHARS; ++i) {
        newNode->children[i] = NULL;
    }
    newNode->terminal = false;
    return newNode;
}

bool trieInsert(TrieNode ** root, char * signedText) {
    if (*root == NULL) * root = creatNode();

    TrieNode *tmp = *root;

    unsigned char * text = (unsigned char *) signedText;
    int length = strlen(signedText);

    for (int i = 0; i < length; ++i) {
        if (tmp->children[text[i]] == NULL) {
            tmp->children[text[i]] = creatNode();
        }
        tmp = tmp->children[text[i]];
    }
    if (tmp->terminal) return false;
    return tmp->terminal = true;
}

bool searchTrie(TrieNode * root, char * signedText) {
    unsigned char * text = (unsigned char *) signedText;
    int length = strlen(signedText);
    TrieNode * tmp = root;
    
    for (int i = 0; i < length; ++i) {
        if (tmp->children[text[i]] == NULL) return false;
        tmp = tmp->children[text[i]];
    }

    return tmp->terminal;
}

bool nodeHasChildren(TrieNode * node) {
    if (node == NULL) return false;
    for (int i = 0; i < NUM_CHARS; ++i) {
        if (node->children[i] != NULL) return true;
    }
    return false;
}
TrieNode * deleteTrieHelper(TrieNode * node, unsigned char * text, bool * deleted) {
    if (node == NULL) return node;

    if (* text == '\0') {
        if (node->terminal) {
            node->terminal = false;
            * deleted = true;

            if (nodeHasChildren(node) == false) {
                free(node);
                node = NULL;
            }
        }
        return node;
    }

    node->children[text[0]] = deleteTrieHelper(node->children[text[0]], text + 1, deleted);
    if (* deleted && nodeHasChildren(node) == false && node->terminal == false) {
        free(node);
        node = NULL;
    }
    return node;
}
bool deleteTrie(TrieNode ** root, char * signedText) {
    unsigned char * text = (unsigned char *) signedText;
    bool result = false;

    if (* root == NULL) return false;
    *root = deleteTrieHelper(*root, text, &result);
    return result;
}

void printTrieHelper(TrieNode * node, unsigned char * prefix, int length);
void printTrie(TrieNode * root);

int main() {
    TrieNode * root = NULL;

    int n = 6;
    int m = 2;
    char ** words = (char * []){"KIT", "CATTLE", "KIN", "CAT", "HAPPY", "AHMAD"};
    char ** search= (char * []){"KIT", "CATTLE", "KIN", "CAR", "AHMED", "AHMAD"};
    char ** remove= (char * []){"KIT", "CAT"};

    for (int i = 0; i < n; ++i) trieInsert(&root, words[i]);
    printTrie(root);
    for (int i = 0; i < n; ++i) {
        if (searchTrie(root, search[i])) {
            printf("Found \"%s\" in the Set\n", search[i]);
        }
        else printf("Didn't find \"%s\" in the Set\n", search[i]);
    }
    for (int i = 0; i < m; ++i) {
        deleteTrie(&root, remove[i]);
    }
    printTrie(root);
}

void printTrieHelper(TrieNode * node, unsigned char * prefix, int length) {
    unsigned char newPrefix[length + 2];
    memcpy(newPrefix, prefix, length);
    newPrefix[length + 1] = 0;

    if (node->terminal) {
        printf("Word: %s\n", prefix);
    }

    for (int i = 0; i < NUM_CHARS; ++i) {
        if (node->children[i] != NULL) {
            newPrefix[length] = i;
            printTrieHelper(node->children[i], newPrefix, length + 1);
        }
    }
}
void printTrie(TrieNode * root) {
    if (root == NULL) {
        printf("Trie is empty\n");
        return;
    }

    printTrieHelper(root, NULL, 0);
}