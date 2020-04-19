#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document doc;
    doc.data = (struct paragraph*)malloc(sizeof(struct paragraph));
    doc.paragraph_count = 1;
    doc.data[0].data = (struct sentence*)malloc(sizeof(struct sentence));
    doc.data[0].sentence_count = 1;
    doc.data[0].data[0].data = (struct word*)malloc(sizeof(struct word));
    doc.data[0].data[0].word_count = 1;
    doc.data[0].data[0].data[0].data = text;
    int i = 0,pc = 1, sc = 1, wc = 1;
    for(i =0;text[i+1]!='\0';i++){
        if(text[i+1]=='\n' && text[i] =='.'){
            text[i] = '\0';
            continue;
        }
        switch(text[i]){
            case '\n':
                doc.paragraph_count++;
                pc = doc.paragraph_count;
                doc.data = (struct paragraph*)realloc(doc.data, pc*(sizeof(struct paragraph)));
                doc.data[pc -1].sentence_count = 0;
                sc = 0;
            case '.':
                doc.data[doc.paragraph_count -1].sentence_count++;
                sc = doc.data[pc -1].sentence_count;
                if(sc ==1){
                    doc.data[pc -1].data =(struct sentence*)malloc(sizeof(struct sentence));
                }
                else{
                    doc.data[pc -1].data = (struct sentence*)realloc(doc.data[pc -1].data,sc*sizeof(struct sentence));
                }
                doc.data[pc -1].data[sc -1].word_count=0;
                wc = 0;
            case ' ':
                doc.data[pc -1].data[sc -1].word_count++;
                wc = doc.data[pc -1].data[sc -1].word_count;
                if(wc ==1){
                    doc.data[pc -1].data[sc -1].data =(struct word*)malloc(sizeof(struct word));
                }
                else{
                    doc.data[pc -1].data[sc -1].data =(struct word*)realloc(doc.data[pc -1].data[sc -1].data,wc*sizeof(struct word));
                }
                doc.data[pc -1].data[sc -1].data[wc-1].data = &text[i+1];
                text[i] = '\0';
        }
    }
    text[i] = '\0';
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}

