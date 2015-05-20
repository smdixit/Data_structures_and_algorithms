#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef LINKED_LIST_C
#define EXTERN extern
#else
#define EXTERN
#endif

typedef struct ListEle{
	void *data;
	struct ListEle *next;
}LISTELE_T;

typedef struct List{
	int size;
	void (*destroy)(void *data);
	LISTELE_T *head_sp;
	LISTELE_T *tail_sp;
}LIST_T;

/* APIs */
EXTERN void init_list(LIST_T *p_list_sp, void (*destroy)(void *));
EXTERN int destroy_list(LIST_T *p_list_sp);
EXTERN int list_ins_next(LIST_T *p_list_sp, LISTELE_T *p_element_sp, const void *p_data);
EXTERN void list_del_next(LIST_T *p_list_sp, LISTELE_T *p_element_sp, void **p_data);

#define get_list_size(list)	(list->size)
#define is_head(list, element)	((list->head_SP) == element ? 1:0)
#define is_tail(list, element)	((list->tail_SP) == element ? 1:0)
#define get_element_data(element)	(element->data)
#define get_next_element(element)	(element->next)

/* configurations */
#define MAX_LIST_SIZE	(1024)

#undef EXTERN
#endif

